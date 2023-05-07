#include <string>
#include <list>

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

Section* StarCatalogue::current_section()
{
    switch (m_current_section_type)
    {
    case SectionType::GALAXY:
        return m_catalogue["Galaxy"].get();
    case SectionType::NEBULA:
        return m_catalogue["Nebula"].get();
    case SectionType::SOLARSYSTEM:
        return m_catalogue["Solar System"].get();
    case SectionType::STAR:
        return m_catalogue["Star"].get();
    case SectionType::PLANET:
        return m_catalogue["Planet"].get();
    default:
        return nullptr;
    }
}

void StarCatalogue::addSection(const std::string& name, std::unique_ptr<Section> section) {
        m_catalogue[name] = std::move(section);
}

void StarCatalogue::printSections() {
        for (const auto& [name, section] : m_catalogue) {
            std::cout << "Section " << name << std::endl;
            section->print();
        }
    }