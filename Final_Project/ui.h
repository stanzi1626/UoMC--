#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <termios.h>
#include <unistd.h>

#include "starCatalogue.h"

namespace ui {
    void clear_terminal();
    void input_filenames(std::vector<std::string>& filenames);
    void read_files(StarCatalogue& catalogue, const std::vector<std::string>& filenames);
    void move_up(StarCatalogue& catalogue);
    void move_down(StarCatalogue& catalogue);
    void handle_catalogue_keypress(StarCatalogue& catalogue, int& arrow_pos, bool& print_info, bool& exit_catalogue);
    void print_catalogue(StarCatalogue& catalogue);
    void handle_menu_keypress(bool& execute_option, int num_options, int& arrow_pos, bool& exit_menu);
    void execute_appropriate_function(int option, StarCatalogue& catalogue, std::vector<std::string>& filenames, std::string& save_filename);
    int make_usr_object_menu();
    void main_menu(StarCatalogue& catalogue);
}  // namespace ui
