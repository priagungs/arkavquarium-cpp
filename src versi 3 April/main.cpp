#include "oop.hpp"
#include "controller.h"
#include <iostream>
#include <math.h>
#include <sstream>

const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();
    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    bool running = true;

    double prevtime = time_since_start();

    controller tank;

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

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

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("ikan.png", cx, cy);
        update_screen();
    }

    close();

    return 0;
}
