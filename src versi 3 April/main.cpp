#include "oop.hpp"
#include "akuarium.hpp"
#include "controller.hpp"
#include <iostream>
#include <math.h>
#include <sstream>

const double speed = 50; // pixels per second

void drawAquarium(akuarium tank);

int main( int argc, char* args[] )
{
    akuarium a(SCREEN_WIDTH, SCREEN_HEIGHT);
    controller control(a);
    control.addGuppy(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
  //  control.addGuppy(SCREEN_HEIGHT/2, SCREEN_WIDTH/2);
  //  control.addGuppy(SCREEN_WIDTH/2, SCREEN_WIDTH/2);

    init();
    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    bool running = true;

        // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;


    double prevtime = time_since_start();


    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
                case SDLK_UP:
                    cy -= speed * sec_since_last;
                    break;
                case SDLK_DOWN:
                    cy += speed * sec_since_last;
                    break;
                case SDLK_LEFT:
                    cx -= speed * sec_since_last;
                    break;
                case SDLK_RIGHT:
                    cx += speed * sec_since_last;
                    break;
            }
        }

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            case SDLK_x:
                control.addMakanan(SCREEN_WIDTH/2);
                break;
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }
        control.processAkuarium();

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_image("ikan.png", cx, cy);
        drawAquarium(control.getAkuarium());
        update_screen();
    }

    close();

    return 0;
}

void drawAquarium(akuarium tank) {
    draw_image("snail.png", tank.getSiput().getX(), tank.getSiput().getY());

    if (!tank.getListGuppy().isEmpty()) {
        elmt<guppy>* currentGuppy = tank.getListGuppy().first;
        while (currentGuppy != NULL) {
            if ((currentGuppy->info.getDirection()>=0 &&  currentGuppy->info.getDirection()<90) ||
                (currentGuppy->info.getDirection()>=270 &&  currentGuppy->info.getDirection()<360)) {
              draw_image("guppykanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
            } else {
              draw_image("guppykiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
            }
            currentGuppy = currentGuppy->next;
        }
    }

    if (!tank.getListMakanan().isEmpty()) {
        elmt<makanan>* currentFood = tank.getListMakanan().first;
        while (currentFood != NULL) {
            draw_image("upil.png", currentFood->info.getX(), currentFood->info.getY());
            currentFood = currentFood->next;
        }
    }
}
