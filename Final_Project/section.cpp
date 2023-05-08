#include "sections.h"

std::vector<std::shared_ptr<AstroObject>> GalaxySection::get_items() const {
    std::vector<std::shared_ptr<AstroObject>> items;
    for (const auto& item : m_galaxies) {
        items.push_back(std::make_shared<Galaxy>(dynamic_cast<Galaxy&>(*item)));
    }
    return items;
}

std::vector<std::shared_ptr<AstroObject>> NebulaSection::get_items() const {
    std::vector<std::shared_ptr<AstroObject>> items;
    for (const auto& item : m_nebulae) {
        items.push_back(std::make_shared<StellarNebula>(dynamic_cast<StellarNebula&>(*item)));
    }
    return items;
}

std::vector<std::shared_ptr<AstroObject>> SolarSystemSection::get_items() const {
    std::vector<std::shared_ptr<AstroObject>> items;
    for (const auto& item : m_solar_systems) {
        items.push_back(std::make_shared<SolarSystem>(dynamic_cast<SolarSystem&>(*item)));
    }
    return items;
}

std::vector<std::shared_ptr<AstroObject>> StarSection::get_items() const {
    std::vector<std::shared_ptr<AstroObject>> items;
    for (const auto& item : m_stars) {
        items.push_back(std::make_shared<Star>(dynamic_cast<Star&>(*item)));
    }
    return items;
}

std::vector<std::shared_ptr<AstroObject>> PlanetSection::get_items() const {
    std::vector<std::shared_ptr<AstroObject>> items;
    for (const auto& item : m_planets) {
        items.push_back(std::make_shared<Planet>(dynamic_cast<Planet&>(*item)));
    }
    return items;
}