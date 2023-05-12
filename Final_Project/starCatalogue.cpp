#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <limits>

#include "starCatalogue.h"
#include "ui.h"

StarCatalogue::StarCatalogue()
{
    addSection("Galaxy", std::make_unique<GalaxySection>());
    addSection("Stellar Nebula", std::make_unique<NebulaSection>());
    addSection("Solar System", std::make_unique<SolarSystemSection>());
    addSection("Star", std::make_unique<StarSection>());
    addSection("Planet", std::make_unique<PlanetSection>());

    m_current_section_type = SectionType::GALAXY;
}

StarCatalogue::~StarCatalogue()
{
}

void StarCatalogue::move_up()
{
    switch (m_current_section_type)
    {
    case SectionType::GALAXY:
        std::cout << "You are already at the top of the catalogue." << std::endl;
        break;
    case SectionType::NEBULA:
        m_current_section_type = SectionType::GALAXY;
        break;
    case SectionType::SOLARSYSTEM:
        m_current_section_type = SectionType::NEBULA;
        break;
    case SectionType::STAR:
        m_current_section_type = SectionType::SOLARSYSTEM;
        break;
    case SectionType::PLANET:
        m_current_section_type = SectionType::STAR;
        break;
    default:
        break;
    }
}

void StarCatalogue::move_down()
{
    switch (m_current_section_type)
    {
    case SectionType::GALAXY:
        m_current_section_type = SectionType::NEBULA;
        break;
    case SectionType::NEBULA:
        m_current_section_type = SectionType::SOLARSYSTEM;
        break;
    case SectionType::SOLARSYSTEM:
        m_current_section_type = SectionType::STAR;
        break;
    case SectionType::STAR:
        m_current_section_type = SectionType::PLANET;
        break;
    case SectionType::PLANET:
        std::cout << "You are already at the bottom of the catalogue." << std::endl;
        break;
    default:
        break;
    }
}

void StarCatalogue::print_current_section(){
    switch (m_current_section_type)
    {
    case SectionType::GALAXY:
        std::cout << "You are currently in the Galaxy section." << std::endl;
        break;
    case SectionType::NEBULA:
        std::cout << "You are currently in the Nebula section." << std::endl;
        break;
    case SectionType::SOLARSYSTEM:
        std::cout << "You are currently in the Solar System section." << std::endl;
        break;
    case SectionType::STAR:
        std::cout << "You are currently in the Star section." << std::endl;
        break;
    case SectionType::PLANET:
        std::cout << "You are currently in the Planet section." << std::endl;
        break;
    default:
        break;
    }    
}

const Section* StarCatalogue::current_section() const
{
    switch (m_current_section_type)
    {
    case SectionType::GALAXY:
        return m_catalogue.at("Galaxy").get();
    case SectionType::NEBULA:
        return m_catalogue.at("Stellar Nebula").get();
    case SectionType::SOLARSYSTEM:
        return m_catalogue.at("Solar System").get();
    case SectionType::STAR:
        return m_catalogue.at("Star").get();
    case SectionType::PLANET:
        return m_catalogue.at("Planet").get();
    default:
        return nullptr;
    }
}

void StarCatalogue::addSection(const std::string& name, std::unique_ptr<Section> section)
{
    m_catalogue[name] = std::move(section);
}

std::shared_ptr<AstroObject> StarCatalogue::make_object(const std::string& line)
{
    std::shared_ptr<AstroObject> object_ptr;
    // Check what type of object the line describes
    if (line.find("Galaxy") != std::string::npos) {
        // Make a Galaxy object
        object_ptr = std::make_shared<Galaxy>(line);
    }
    else if (line.find("Star") != std::string::npos) {
        // Make a Star object
        object_ptr = std::make_shared<Star>(line);
    }
    else if (line.find("Planet") != std::string::npos) {
        // Make a Planet object
        object_ptr = std::make_shared<Planet>(line);
    }
    else if (line.find("Stellar Nebula") != std::string::npos) {
        // Make a Stellar Nebula object
        object_ptr = std::make_shared<StellarNebula>(line);
    }
    else if (line.find("Solar System") != std::string::npos) {
        // Make an Solar System object
        object_ptr = std::make_shared<SolarSystem>(line);
    }
    else {
        std::cout << "Error: Unknown object type." << std::endl;
        return nullptr;
    }
    if (object_ptr) {
        std::cout << "Object created with name: " << object_ptr->get_astro_name() << std::endl;
    }
    return object_ptr;
}

std::string string_check() {
    std::string usr_string;
    std::getline(std::cin, usr_string);

    std::string input;
    bool isValidInput = false;

    while (!isValidInput) {
        std::cout << "The string you entered is: " << usr_string << ". Press enter to continue or type 'r' to re-enter." << std::endl;
        std::getline(std::cin, input);

        if (input.empty()) {
            isValidInput = true;
        } else if (input == "r") {
            std::cout << "Please re-enter the string: ";
            std::getline(std::cin, usr_string);
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
    return usr_string;
}

int number_check(const double min, const double max) {
    int usr_number;
    bool isValidInput = false;

    while (!isValidInput) {
        std::cout << "Please enter a number between " << min << " and " << max << ": ";
        std::cin >> usr_number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        } else if (usr_number < min || usr_number > max) {
            std::cout << "Number out of range. Please enter a number between " << min << " and " << max << "." << std::endl;
        } else {
            isValidInput = true;
        }
    }
    return usr_number;
}

std::string galaxy_type_check()
{
    std::string usr_galaxy_type;
    bool isValidInput = false;

    while (!isValidInput) {
        std::cout << "Please enter the type of galaxy (E0, E3, E5, E7, S0, Sa, Sb, Sc, SBa, SBb, SBc, Irr): ";
        std::getline(std::cin, usr_galaxy_type);

        auto it = hubble_type.find(usr_galaxy_type);
        if (it == hubble_type.end()) {
            std::cout << "Invalid input. Please enter a valid galaxy type." << std::endl;
        } else {
            isValidInput = true;
        }
    }
    return usr_galaxy_type;
}

void StarCatalogue::make_usr_object() {
    std::shared_ptr<AstroObject> object_ptr;
    // Get type of object to create
    int usr_choice = ui::make_usr_object_menu();
    if (usr_choice == -1) {
        return;
    }
    // Get name of object from user
    std::cout << "Enter the name of the object: ";
    std::string usr_object_name = string_check();
    std::cout << "Enter the ascension of the object: ";
    double usr_ascension = number_check(0, 360);
    std::cout << "Enter the declination of the object: ";
    double usr_declination = number_check(-90, 90);
    std::cout << "Enter the apparent magnitude of the object: ";
    double usr_apparent_magnitude = number_check(1, 6);
    std::cout << "Enter the redshift of the object: ";
    double usr_redshift = number_check(0, std::numeric_limits<double>::infinity());
    std::cout << "Enter the distance of the object from Earth: ";
    double usr_distance = number_check(0, std::numeric_limits<double>::infinity());

    // Create object
    if (usr_choice == 0) {
        // Make a Galaxy object
        std::string usr_galaxy_type = galaxy_type_check();
        std::cout << "Enter the stellar mass fraction of the object: ";
        double usr_stellar_mass_fraction = number_check(0, 1);
        object_ptr = std::make_shared<Galaxy>(usr_object_name, usr_ascension, usr_declination, 
                                              usr_apparent_magnitude, usr_redshift, usr_distance,
                                              usr_galaxy_type, usr_stellar_mass_fraction);
    } else if (usr_choice == 1) {
        // Make a Stellar Nebula object
        object_ptr = std::make_shared<StellarNebula>(usr_object_name, usr_ascension, usr_declination, 
                                                     usr_apparent_magnitude, usr_redshift, usr_distance);
    } else if (usr_choice == 2) {
        // Make a Solar System object
        object_ptr = std::make_shared<SolarSystem>(usr_object_name, usr_ascension, usr_declination, 
                                                   usr_apparent_magnitude, usr_redshift, usr_distance);
    } else if (usr_choice == 3) {
        // Make a Star object
        std::cout << "Enter the mass of the object: ";
        double usr_mass = number_check(0, 1e12);
        std::cout << "Enter the radius of the object: ";
        double usr_radius = number_check(0, 1e12);
        std::cout << "Enter the temperature of the object: ";
        double usr_temperature = number_check(0, 1e12);
        std::cout << "Enter the metallicty of the object: ";
        double usr_metallicity = number_check(0, 1);
        object_ptr = std::make_shared<Star>(usr_object_name, usr_mass, usr_ascension, usr_declination, 
                                            usr_apparent_magnitude, usr_redshift, usr_distance,
                                            usr_radius, usr_temperature, usr_metallicity);
    } else if (usr_choice == 4) {
        // Make a Planet object
        std::cout << "Enter the mass of the object: ";
        double usr_mass = number_check(0, 1e12);
        std::cout << "Enter the radius of the object: ";
        double usr_radius = number_check(0, 1e12);
        std::cout << "Enter the number of moons of the object: ";
        int usr_num_moons = number_check(0, 100);
        std::cout << "Enter the orbital period of the object: ";
        double usr_orbital_period = number_check(0, 500);
        std::cout << "Enter the rotation period of the object: ";
        double usr_rotation_period = number_check(0, 500);
        std::cout << "Enter the orbital eccentricity of the object: ";
        double usr_orbital_eccentricity = number_check(0, 1);
        object_ptr = std::make_shared<Planet>(usr_object_name, usr_mass, usr_ascension, usr_declination, 
                                              usr_apparent_magnitude, usr_redshift, usr_distance,
                                              usr_radius, usr_num_moons, usr_orbital_period,
                                              usr_rotation_period, usr_orbital_eccentricity);
    } else {
        std::cout << "Error: Unknown object type." << std::endl;
    }
    // Add object to catalogue
    if (object_ptr) {
        add_object(object_ptr->get_type(), object_ptr);
    }
    // Clear input buffer
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

void StarCatalogue::add_object(const std::string& sectionName, std::shared_ptr<AstroObject>& obj_ptr) {
    auto it = m_catalogue.find(sectionName);
    if (it != m_catalogue.end()) {
        it->second->add_object(obj_ptr);
    }
}

void StarCatalogue::printSections()
{
    for (const auto& [name, section] : m_catalogue) {
        std::cout << "Section " << name << std::endl;
        section->get_section_name();
    }
}

std::shared_ptr<AstroObject> StarCatalogue::get_object(const std::string& object_name) const {
    for (const auto& [name, section_ptr] : m_catalogue) {
        for (const auto& object_ptr : section_ptr->get_items()) {
            if (object_ptr->get_astro_name() == object_name) {
                return object_ptr;
            }
        }
    }
    return nullptr;
}

void StarCatalogue::set_object_relationships() {
    // Set parent and child pointers
    for (const auto& [name, section_ptr] : m_catalogue) {
        for (const auto& item : section_ptr->get_items()) {
            if (item->get_parent_name() != "") {
                std::shared_ptr<AstroObject> parent_ptr = get_object(item->get_parent_name());
                if (parent_ptr == nullptr) {
                    std::cout << "Error: Parent object with name " << item->get_parent_name() << " not found." << std::endl;
                    continue;
                } else {    
                    item->set_parent(parent_ptr);
                    parent_ptr->add_child(item);
                }
            }
        }
    }
}

void StarCatalogue::remove_object(std::shared_ptr<AstroObject> object_ptr)
{
    // Remove the object from the catalogue
    std::string section_name = object_ptr->get_type();
    std::vector<std::shared_ptr<AstroObject>>& section = m_catalogue[section_name]->get_items_not_const();
    auto it = std::find_if(section.begin(), section.end(),
                       [&](const std::shared_ptr<AstroObject>& ptr)
                       { return ptr->get_astro_name() == object_ptr->get_astro_name(); });
    if (it != section.end()) {
        section.erase(it);
    }

    // Remove the object from the parent's children list
    std::shared_ptr<AstroObject> parent_ptr = object_ptr->get_parent().lock();
    if (parent_ptr != nullptr) {
        std::vector<std::shared_ptr<AstroObject>>& children = parent_ptr->get_children();
        auto child_it = std::find(children.begin(), children.end(), object_ptr);
        if (child_it != children.end()) {
            children.erase(child_it);
        }
    }

    // Remove the object from the child's parent pointer
    for (std::shared_ptr<AstroObject> child_ptr : object_ptr->get_children()) {
        child_ptr->set_parent(nullptr);
    }
}

void StarCatalogue::read_file(const std::string& filename)
{
    std::string line;

    std::ifstream file(filename);

    // skip the first line
    std::getline(file, line);

    // Check what type of object the line describes
    // and add it to the correct section
    while (std::getline(file, line)) {
        // Make the AstroObject from the line
        std::shared_ptr<AstroObject> object_ptr = make_object(line);

        // Check whether the object has the same name as an object already in the catalogue
        // If it does, then prompt the user for their choice
        std::string object_name = object_ptr->get_astro_name();
        std::shared_ptr<AstroObject> existing_object_ptr = get_object(object_name);
        if (existing_object_ptr != nullptr) {
            std::cout << "Object with name " << object_name << " already exists." << std::endl;
            std::cout << "Do you want to replace the existing object with this new one?" << std::endl;
            // Print the existing object and the new object
            std::cout << "Existing object: " << std::endl;
            existing_object_ptr->print_astro_info();
            std::cout << "New object: " << std::endl;
            object_ptr->print_astro_info();
            std::cout << "Enter 'y' for yes or 'n' for no: ";
            char choice;
            std::cin >> choice;
            if (choice == 'y') {
                // Replace the existing object with the new one
                remove_object(existing_object_ptr);
            } else {
                // Discard the new object
                continue;
            }
        }

        // Add the object to the catalogue
        std::string section_name = object_ptr->get_type();
        add_object(section_name, object_ptr);
    }
    // Set parent and child pointers
    set_object_relationships();

    // DEBUG - wait for input
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.get();

    file.close();
}

void StarCatalogue::save_to_csv(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not create file \"" << filename << "\"" << std::endl;
        return;
    }


    file << std::string("Type,Name,Parent Name,Mass,Ascension,Declination,Apparent Magnitude,Redshift,Distance from Earth,Galaxy Type,Stellar Mass Fraction,Radius,Temperature,Metalicity,Number of Moons,Orbital Period,Rotation Period,Orbital Eccentricity") << std::endl;
    for (const auto& section : m_catalogue) {
        for (const auto& item : section.second->get_items()) {
            file << item->get_info() << std::endl;
        }
    }

    file.close();
    std::cout << "Catalogue saved to file \"" << filename << "\"" << std::endl;
}