#include "oop.hpp"
#include "akuarium.hpp"
#include "controller.hpp"
#include "konstanta.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

const double speed = 100; // pixels per second

void drawAquarium(akuarium tank);

int main( int argc, char* args[] )
{
    akuarium a(SCREEN_WIDTH, SCREEN_HEIGHT);
    controller control(a);
    control.addGuppy();

    init();
    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    bool running = true;

    // Posisi pointer
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;


    double prevtime = time_since_start();


    while (control.levelTelur < 3 && running) {
		//cout << control.uang;
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan kursor selama tombol panah ditekan
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
            case SDLK_p:
      				if (control.uang >= HARGA_PIRANHA) {
      					control.addPiranha();
      				}
                break;
            case SDLK_m:
      				if (control.uang >= HARGA_MAKANAN) {
      					control.addMakanan(cx);
      				}
                break;
      			case SDLK_n:
      				if (control.uang >= HARGA_GUPPY) {
      					control.addGuppy();
      				}
                break;
            case SDLK_t:
      				if (control.levelTelur == 0) {
      					if (control.uang >= HARGA_TELUR1) {
      						control.levelTelur++;
      						control.uang -= HARGA_TELUR1;
      					}
      				} else if (control.levelTelur == 1) {
      					if (control.uang >= HARGA_TELUR2) {
      						control.levelTelur++;
      						control.uang -= HARGA_TELUR2;
      					}
      				} else if (control.levelTelur == 2) {
        					if (control.uang >= HARGA_TELUR3) {
        						control.levelTelur++;
        						control.uang -= HARGA_TELUR3;
        					}
      				}
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

        ostringstream cKoin;
        ostringstream cTelur;
        ostringstream priceInfo;
        ostringstream priceTelur;

        cKoin << "Koin : " <<  control.uang;
        cTelur << "Level Telur : " << control.levelTelur;
        priceInfo << "Food : " << HARGA_MAKANAN << " - M | Guppy : " << HARGA_GUPPY << " - N"
                  << " | Piranha : " << HARGA_PIRANHA << " - P";
        priceInfo << " | Telur : ";
        if (control.levelTelur == 0) {
          priceInfo << HARGA_TELUR1;
        } else if (control.levelTelur == 1) {
          priceInfo << HARGA_TELUR2;
        } else if (control.levelTelur == 2) {
          priceInfo << HARGA_TELUR3;
        }
        priceInfo << " - T";

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("background.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        draw_image("pointer.png", cx, cy);
        draw_text(cKoin.str(), 22, 30, 8, 0, 0, 0);
        draw_text(cTelur.str(), 22, SCREEN_WIDTH-170, 8, 0, 0, 0);
        //draw_text(priceTelur.str(), 22, SCREEN_WIDTH-180, 20, 0, 0, 0);
        draw_text(priceInfo.str(), 20, 20, SCREEN_HEIGHT-30, 0, 0, 0);
        drawAquarium(control.getAkuarium());
        update_screen();
    }

	//cout << control.uang << endl;

    close();

    return 0;
}

void drawAquarium(akuarium tank) {

	if ((tank.getSiput().getDirection()>=0 &&  tank.getSiput().getDirection()<0.5*M_PI) ||
		(tank.getSiput().getDirection()>=1.5*M_PI &&  tank.getSiput().getDirection()<2*M_PI)) {

		draw_image("siputkanan.png", tank.getSiput().getX(), tank.getSiput().getY());
	} else {
		draw_image("siputkiri.png", tank.getSiput().getX(), tank.getSiput().getY());
	}

    if (!tank.getListGuppy().isEmpty()) {
        elmt<guppy>* currentGuppy = tank.getListGuppy().first;
        while (currentGuppy != NULL) {
          if ((currentGuppy->info.getDirection()>=0 &&  currentGuppy->info.getDirection()<0.5*M_PI) ||
                (currentGuppy->info.getDirection()>=1.5*M_PI &&  currentGuppy->info.getDirection()<2*M_PI)) { //Hadap kanan
      				if (currentGuppy->info.getTahap()==1) {
      					if (currentGuppy->info.getHungerState()) { //guppy lapar
      						draw_image("guppy1laparkanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
      					} else {
      						draw_image("guppy1kanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
      					}
      				} else if (currentGuppy->info.getTahap() == 2) {
      					if (currentGuppy->info.getHungerState()) { //guppy lapar
      						draw_image("guppy2laparkanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
      					} else {
      						draw_image("guppy2kanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
      					}
      				} else if (currentGuppy->info.getTahap() == 3) {
      					if (currentGuppy->info.getHungerState()) { //guppy lapar
      						draw_image("guppy3laparkanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
      					} else {
      						draw_image("guppy3kanan.png", currentGuppy->info.getX(), currentGuppy->info.getY());
      					}
      				}
			    } else { //Hadap kiri
    				if (currentGuppy->info.getTahap()==1) {
    					if (currentGuppy->info.getHungerState()) { //guppy lapar
    						draw_image("guppy1laparkiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
    					} else {
    						draw_image("guppy1kiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
    					}
    				} else if (currentGuppy->info.getTahap() == 2) {
    					if (currentGuppy->info.getHungerState()) { //guppy lapar
    						draw_image("guppy2laparkiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
    					} else {
    						draw_image("guppy2kiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
    					}
    				} else if (currentGuppy->info.getTahap() == 3) {
    					if (currentGuppy->info.getHungerState()) { //guppy lapar
    						draw_image("guppy3laparkiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
    					} else {
    						draw_image("guppy3kiri.png", currentGuppy->info.getX(), currentGuppy->info.getY());
    					}
    				}
			   }

            currentGuppy = currentGuppy->next;
        }
    }

	if (!tank.getListPiranha().isEmpty()) {
        elmt<piranha>* currentPiranha = tank.getListPiranha().first;
        while (currentPiranha != NULL) {
            if ((currentPiranha->info.getDirection()>=0 &&  currentPiranha->info.getDirection()<0.5*M_PI) ||
                (currentPiranha->info.getDirection()>=1.5*M_PI &&  currentPiranha->info.getDirection()<2*M_PI)) { //Hadap kanan
				if (currentPiranha->info.getHungerState()) { //piranha lapar
						draw_image("piranhalaparkanan.png", currentPiranha->info.getX(), currentPiranha->info.getY());
					} else {
						draw_image("piranhakanan.png", currentPiranha->info.getX(), currentPiranha->info.getY());
					}
			} else {
				if (currentPiranha->info.getHungerState()) { //piranha lapar
						draw_image("piranhalaparkiri.png", currentPiranha->info.getX(), currentPiranha->info.getY());
					} else {
						draw_image("piranhakiri.png", currentPiranha->info.getX(), currentPiranha->info.getY());
					}
			}
			currentPiranha = currentPiranha->next;
		}
	}

    if (!tank.getListMakanan().isEmpty()) {
        elmt<makanan>* currentFood = tank.getListMakanan().first;
        while (currentFood != NULL) {
            draw_image("food.png", currentFood->info.getX(), currentFood->info.getY());
            currentFood = currentFood->next;
        }
    }

    if (!tank.getListKoin().isEmpty()) {
      elmt<koin>* temp = tank.getListKoin().first;
      do {
		if (temp->info.getNilai() == NILAI_KOIN_TAHAP1) {
			draw_image("koin1.png", temp->info.getX(), temp->info.getY());
		} else if (temp->info.getNilai() == NILAI_KOIN_TAHAP2) {
			draw_image("koin2.png", temp->info.getX(), temp->info.getY());
		} else if (temp->info.getNilai()  == NILAI_KOIN_TAHAP3) {
			draw_image("Diamond.png", temp->info.getX(), temp->info.getY());
		}
        temp = temp->next;
      } while (temp != NULL);
    }
}
