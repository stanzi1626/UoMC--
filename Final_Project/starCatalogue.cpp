#include <string>
#include <list>
#include <fstream>
#include <algorithm>

#include "starCatalogue.h"

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
        // Print if the object was successfully created
        if (object_ptr) {
            std::cout << "Object created with name: " << object_ptr->get_astro_name() << std::endl;
        }
    }
    else if (line.find("Star") != std::string::npos) {
        // Make a Star object
        object_ptr = std::make_shared<Star>(line);
        if (object_ptr) {
            std::cout << "Object created with name: " << object_ptr->get_astro_name() << std::endl;
        }
    }
    else if (line.find("Planet") != std::string::npos) {
        // Make a Planet object
        object_ptr = std::make_shared<Planet>(line);
        if (object_ptr) {
            std::cout << "Object created with name: " << object_ptr->get_astro_name() << std::endl;
        }
    }
    else if (line.find("Stellar Nebula") != std::string::npos) {
        // Make a Stellar Nebula object
        object_ptr = std::make_shared<StellarNebula>(line);
        if (object_ptr) {
            std::cout << "Object created with name: " << object_ptr->get_astro_name() << std::endl;
        }
    }
    else if (line.find("Solar System") != std::string::npos) {
        // Make an Solar System object
        object_ptr = std::make_shared<SolarSystem>(line);
        if (object_ptr) {
            std::cout << "Object created with name: " << object_ptr->get_astro_name() << std::endl;
        }
    }
    else {
        std::cout << "Error: Unknown object type." << std::endl;
        return nullptr;
    }
    return object_ptr;
}


void StarCatalogue::add_object(std::string& sectionName, std::shared_ptr<AstroObject>& obj_ptr) {
    auto it = m_catalogue.find(sectionName);
    // if (it != m_catalogue.end()) {
    //     Section* section = it->second.get();
    //     section->add_object(std::move(objPtr));
    // }
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
                item->set_parent(parent_ptr);
                parent_ptr->add_child(item);
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


    file << std::string("Type, Name, Parent name, Mass, Age") << std::endl;
    for (const auto& section : m_catalogue) {
        for (const auto& item : section.second->get_items()) {
            file << item->get_info() << std::endl;
        }
    }

    file.close();
    std::cout << "Catalogue saved to file \"" << filename << "\"" << std::endl;
}