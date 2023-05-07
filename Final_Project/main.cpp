#include <iostream>

#include "starCatalogue.h"

int main()
{
    StarCatalogue catalogue;
    
    catalogue.print_current_section();
    catalogue.move_down();
    catalogue.print_current_section();
    catalogue.current_section()->print();

    return 0;
}