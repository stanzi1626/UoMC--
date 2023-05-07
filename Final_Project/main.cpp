#include <iostream>
#include "StarCatalogue.h"
#include "ui.h"

int main() {
    // Initialize the catalogue
    StarCatalogue catalogue;

    // Read the file
    catalogue.read_file();

    // Run the UI
    ui::run_ui(catalogue);
}
