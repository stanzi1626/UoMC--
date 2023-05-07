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

    void handle_keypress(StarCatalogue& catalogue) {
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
            case 'j':
                move_up(catalogue);
                break;
            case 'k':
                move_down(catalogue);
                break;
            default:
                std::cout << "Invalid key pressed." << std::endl;
                break;
        }

        clear_terminal();
    }

    void run_ui(StarCatalogue& catalogue) {
        std::cout << "Welcome to the Star Catalogue!" << std::endl;
        std::cout << "Use 'j' to move up and 'k' to move down." << std::endl;

        while (true) {
            std::cout << "Current section: ";
            catalogue.print_current_section();
            std::cout << std::endl;

            ui::handle_keypress(catalogue);
        }
    }

}  // namespace ui
