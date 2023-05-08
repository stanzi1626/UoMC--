#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

namespace ui {

    void clear_terminal() {
        std::cout << "\033[2J\033[1;1H";
    }

    void move_up(StarCatalogue& catalogue) {
        catalogue.move_up();
        std::cout << "Moved up to section: ";
        catalogue.print_current_section();
        std::cout << std::endl;
    }

    void move_down(StarCatalogue& catalogue) {
        catalogue.move_down();
        std::cout << "Moved down to section: ";
        catalogue.print_current_section();
        std::cout << std::endl;
    }

    void handle_keypress(StarCatalogue& catalogue, int& arrow_pos, bool& print_info) {
        termios old_tio, new_tio;
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;
        new_tio.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

        char key = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

        switch (key) {
            case 'q':
                std::cout << "Exiting..." << std::endl;
                exit(0);
                break;
            case 'h':
                arrow_pos = 0;
                move_up(catalogue);
                break;
            case 'l':
                arrow_pos = 0;
                move_down(catalogue);
                break;
            case 'j':
                if (arrow_pos < catalogue.current_section()->get_number_objects() - 1) {
                    arrow_pos++;
                }
                break;
            case 'k':
                if (arrow_pos > 0) {
                    arrow_pos--;
                }
                break;
            case '\n':
                if (print_info) {
                    print_info = false;
                } else {
                    print_info = true;
                }
                break;
            default:
                std::cout << "Invalid key pressed." << std::endl;
                break;
        }

        clear_terminal();
    }

    void run_ui(StarCatalogue& catalogue) {
        clear_terminal();
        int arrow_pos = 0;
        bool print_info = false;

        std::cout << "Welcome to the Star Catalogue!" << std::endl;
        std::cout << "Use 'j' to move up and 'k' to move down." << std::endl;

        while (true) {
            std::cout << "Current section: " << catalogue.current_section()->get_section_name() << std::endl;
            std::cout << std::endl;

            // Print each object in the section, with an arrow next to the selected one
            for (int i = 0; i < catalogue.current_section()->get_number_objects(); i++) {
                if (!print_info) {
                    if (i == arrow_pos) {
                        std::cout << " -> ";
                    } else {
                        std::cout << "    ";
                    }
                    std::cout << catalogue.current_section()->get_object_at_index(i)->get_astro_name() << std::endl;
                } else {
                    if (i == arrow_pos) {
                        std::cout << " -> ";
                        std::cout << catalogue.current_section()->get_object_at_index(i)->get_astro_name() << ":" << std::endl;
                        catalogue.current_section()->get_object_at_index(i)->print_astro_info();
                    }
                }
            }

            handle_keypress(catalogue, arrow_pos, print_info);
        }
    }

}  // namespace ui
