#include "ui.h"

namespace ui {

    void clear_terminal() {
        std::cout << "\033[2J\033[1;1H";
    }

    void input_filenames(std::vector<std::string>& filenames) {
        while (true) {
            std::string filename;
            std::cout << "Enter the name of the file you would like to read into the catalogue (or 'q' to quit): ";
            std::cin >> filename;

            if (filename == "q") {
                // Clear the input buffer
                std::cin.clear();
                std::cin.ignore(256, '\n');
                break;
            } else if (filename.substr(filename.length() - 4) != ".csv") {
                std::cerr << "Error: Filename must end with \".csv\"" << std::endl;
            } else {
                filenames.push_back(filename);
            }
        }
    }

    void read_files(StarCatalogue& catalogue, const std::vector<std::string>& filenames) {
        std::cout << "Reading files..." << std::endl;

        if (filenames.size() == 0) {
            std::cout << "No files to read." << std::endl;
            return;
        } else {
            for (const auto filename : filenames) {
            std::ifstream file(filename);

            if (!file.is_open()) {
                std::cerr << "Error: Could not open file \"" << filename << "\", this file might not exist." << std::endl;
                continue;
            }

            catalogue.read_file(filename);

            file.close();

            std::cout << "Successfully read file \"" << filename << "\"" << std::endl;
            }
        }
        // Press to continue
        std::cout << "Press any key to continue..." << std::endl;
        getchar();
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

    void handle_catalogue_keypress(StarCatalogue& catalogue, int& arrow_pos, bool& print_info, bool& exit_catalogue) {
        termios old_tio, new_tio;
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;
        new_tio.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

        char key = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

        switch (key) {
            case 'q':
                std::cout << "Exiting Star Catalogue..." << std::endl;
                std::cout << "Press any key to continue..." << std::endl;
                getchar();
                exit_catalogue = true;
                break;
            case 'h':
                if (print_info == false) {
                    arrow_pos = 0;
                    move_up(catalogue);
                }
                break;
            case 'l':
                if (print_info == false) {
                    arrow_pos = 0;
                    move_down(catalogue);
                }
                break;
            case 'j':
                if (arrow_pos < catalogue.current_section()->get_number_objects() - 1 && print_info == false) {
                    arrow_pos++;
                }
                break;
            case 'k':
                if (arrow_pos > 0 && print_info == false) {
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

    void print_catalogue(StarCatalogue& catalogue) {
        clear_terminal();
        int arrow_pos = 0;
        bool print_info = false;
        bool exit_catalogue = false;

        while (!exit_catalogue) {
            std::cout << "Use 'j' to move up, 'k' to move down, 'h' to move left, 'l' to move right, 'q' to quit, and 'enter' to view more information." << std::endl;

            std::cout << "Current section: " << catalogue.current_section()->get_section_name() << std::endl;
            std::cout << std::endl;

            // Print each object in the section, with an arrow next to the selected one
            for (int i = 0; i < catalogue.current_section()->get_number_objects(); i++) {
                if (!print_info) {
                    if (i == arrow_pos) {
                        std::cout << " ->  ";
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

            handle_catalogue_keypress(catalogue, arrow_pos, print_info, exit_catalogue);
        }
    }

    void handle_menu_keypress(bool& execute_option, int num_options, int& arrow_pos, bool& exit_menu) {
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
            exit_menu = true;
            break;
        case 'j':
            if (arrow_pos < num_options - 1) {
                arrow_pos++;
            }
            break;
        case 'k':
            if (arrow_pos > 0) {
                arrow_pos--;
            }
            break;
        case '\n':
            execute_option = true;
            break;
        default:
            std::cout << "Invalid key pressed." << std::endl;
            break;
        }
        clear_terminal();
    }

    void execute_appropriate_function(int option, StarCatalogue& catalogue, std::vector<std::string>& filenames, std::string& save_filename) {
        switch (option) {
            case 0:
                clear_terminal();
                input_filenames(filenames);
                break;
            case 1:
                clear_terminal();
                read_files(catalogue, filenames);
                break;
            case 2:
                clear_terminal();
                catalogue.make_usr_object();
                break;
            case 3:
                clear_terminal();
                print_catalogue(catalogue);
                break;
            case 4:
                clear_terminal();
                catalogue.save_to_csv(save_filename);
                // Press to continue
                std::cout << "Press any key to continue..." << std::endl;
                getchar();
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                exit(0);
                break;
            default:
                std::cout << "Invalid option selected." << std::endl;
                break;
        }
    }

    int make_usr_object_menu() {
        int num_options = 5;
        int arrow_pos = 0;
        bool execute_option = false;
        bool exit_menu = false;

        while (true) {
            std::cout << "Use 'j' to move down the menu, 'k' to move up the menu and 'q' to quit." << std::endl << std::endl;
            for (int i = 0; i < num_options; i++) {
                if (arrow_pos == i) {
                    std::cout << " ->  ";
                } else {
                    std::cout << "    ";
                }
                switch (i) {
                    case 0:
                        std::cout << "Make a Galaxy" << std::endl;
                        break;
                    case 1:
                        std::cout << "Make a Stellar Nebula" << std::endl;
                        break;
                    case 2:
                        std::cout << "Make a Solar System" << std::endl;
                        break;
                    case 3:
                        std::cout << "Make a Star" << std::endl;
                        break;
                    case 4:
                        std::cout << "Make a Planet" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid option selected." << std::endl;
                        break;
                }
            }

            handle_menu_keypress(execute_option, num_options, arrow_pos, exit_menu);

            if (execute_option) {
                return arrow_pos;
            } else if (exit_menu) {
                return -1;
            }
        }
    }

    void main_menu(StarCatalogue& catalogue) {
        bool exit_menu = false;
        int num_options = 6;
        int arrow_pos = 0;
        bool execute_option = false;

        std::vector<std::string> filenames;
        std::string save_filename = "saved_catalogue.csv";

        while (true) {
            std::cout << "Welcome to the Star Catalogue!" << std::endl;
            std::cout << "Use 'j' to move down the menu, 'k' to move up the menu and 'q' to quit." << std::endl << std::endl;
            for (int i = 0; i < num_options; i++) {
                if (arrow_pos == i) {
                    std::cout << " -> ";
                } else {
                    std::cout << "   ";
                }
                switch (i) {
                    case 0:
                        std::cout << "Input filenames" << std::endl;
                        break;
                    case 1:
                        std::cout << "Load files into catalogue" << std::endl;
                        break;
                    case 2:
                        std::cout << "Add object to catalogue" << std::endl;
                        break;
                    case 3:
                        std::cout << "Print catalogue" << std::endl;
                        break;
                    case 4:
                        std::cout << "Save catalogue" << std::endl;
                        break;
                    case 5:
                        std::cout << "Exit" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid option selected." << std::endl;
                        break;
                }
            }
            if (execute_option) {
                execute_appropriate_function(arrow_pos, catalogue, filenames, save_filename);
                execute_option = false;
                clear_terminal();
            } else {
                handle_menu_keypress(execute_option, num_options, arrow_pos, exit_menu);
            }
        }
    }
}  // namespace ui
