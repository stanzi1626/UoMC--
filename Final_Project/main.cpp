#include <iostream>

#include "starCatalogue.h"

int main()
{
    StarCatalogue catalogue;
    
    catalogue.read_file();

    // Go to the Solar System section and print it
    catalogue.move_down();
    catalogue.print_current_section();
    // Print all entries in Solar System section
    catalogue.current_section()->print_all_objects();

    // Go to the Galaxt section and print it
    catalogue.move_up();
    catalogue.print_current_section();
    // Print all entries in Galaxy section
    catalogue.current_section()->print_all_objects();

    return 0;
}