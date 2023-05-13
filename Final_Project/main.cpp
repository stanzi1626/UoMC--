#include <iostream>
#include "ui.h"
#include "starCatalogue.h"

// TODO:
// Fix reading in of saved_catalogue.csv for planets (obvo mist writing to file)

int main() {
    // Clear the terminal
    ui::clear_terminal();

    // Initialize the catalogue
    StarCatalogue catalogue;

    // Main Menu
    ui::main_menu(catalogue);

    return 0;
}
