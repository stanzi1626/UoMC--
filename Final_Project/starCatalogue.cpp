#include <string>
#include <list>
#include <fstream>

#include "starCatalogue.h"

StarCatalogue::StarCatalogue()
{
    addSection("Galaxy", std::make_unique<GalaxySection>());
    addSection("Nebula", std::make_unique<NebulaSection>());
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
        return m_catalogue.at("Nebula").get();
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

std::unique_ptr<AstroObject> StarCatalogue::make_object(const std::string& line)
{
    std::unique_ptr<AstroObject> object_ptr;
    // Check what type of object the line describes
    if (line.find("Galaxy") != std::string::npos) {
        // Make a Galaxy object
        object_ptr = std::make_unique<Galaxy>(line);
    }
    else if (line.find("Star") != std::string::npos) {
        // Make a Star object
        object_ptr = std::make_unique<Star>(line);
    }
    else if (line.find("Planet") != std::string::npos) {
        // Make a Planet object
        object_ptr = std::make_unique<Planet>(line);
    }
    else if (line.find("Stellar Nebula") != std::string::npos) {
        // Make a Stellar Nebula object
        object_ptr = std::make_unique<StellarNebula>(line);
    }
    else if (line.find("Solar System") != std::string::npos) {
        // Make an Solar System object
        object_ptr = std::make_unique<SolarSystem>(line);
    }
    else {
        std::cout << "Error: Unknown object type." << std::endl;
        return nullptr;
    }
    return object_ptr;
}


void StarCatalogue::add_object(std::string sectionName, std::unique_ptr<AstroObject> objPtr) {
    auto it = m_catalogue.find(sectionName);
    if (it != m_catalogue.end()) {
        Section* section = it->second.get();
        section->add_object(std::move(objPtr));
    }
}

void StarCatalogue::printSections()
{
    for (const auto& [name, section] : m_catalogue) {
        std::cout << "Section " << name << std::endl;
        section->get_section_name();
    }
}

void StarCatalogue::read_file()
{
    std::string line;

    std::ifstream file("starCatalogue.csv");

    // skip the first line
    std::getline(file, line);

    while (std::getline(file, line)) {
        // Make the AstroObject from the line
        std::unique_ptr<AstroObject> object_ptr = make_object(line);

        // Check what type of object the line describes
        // and add it to the correct section
        if (typeid(*object_ptr) == typeid(Galaxy)) {
            add_object("Galaxy", std::move(object_ptr));
        }
        else if (typeid(*object_ptr) == typeid(StellarNebula)) {
            add_object("Nebula", std::move(object_ptr));
        }
        else if (typeid(*object_ptr) == typeid(SolarSystem)) {
            add_object("Solar System", std::move(object_ptr));
        }
        else if (typeid(*object_ptr) == typeid(Star)) {
            add_object("Star", std::move(object_ptr));
        }
        else if (typeid(*object_ptr) == typeid(Planet)) {
            add_object("Planet", std::move(object_ptr));
        }
        else {
            std::cout << "Error: Unknown object type." << std::endl;
        }
    }
    file.close();

}
