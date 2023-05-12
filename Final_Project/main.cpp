#include <iostream>
#include "ui.h"
#include "starCatalogue.h"

int main() {
    // Clear the terminal
    ui::clear_terminal();

    // Initialize the catalogue
    StarCatalogue catalogue;

    // Main Menu
    ui::main_menu(catalogue);

    return 0;
}
