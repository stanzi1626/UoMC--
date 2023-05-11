#include <iostream>
#include "StarCatalogue.h"
#include "ui.h"

int main() {
    // Clear the terminal
    ui::clear_terminal();

    // Initialize the catalogue
    StarCatalogue catalogue;

    // Main Menu
    ui::main_menu(catalogue);

    return 0;
}
