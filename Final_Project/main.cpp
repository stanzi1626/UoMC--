#include <iostream>
#include "StarCatalogue.h"
#include "ui.h"

int main() {
    // Initialize the catalogue
    StarCatalogue catalogue;

    // Main Menu
    ui::main_menu(catalogue);

    return 0;
}
