#include "sections.h"

const std::vector<std::shared_ptr<AstroObject>>& GalaxySection::get_items() const {
    return m_galaxies;
}

const std::vector<std::shared_ptr<AstroObject>>& NebulaSection::get_items() const {
    return m_nebulae;
}

const std::vector<std::shared_ptr<AstroObject>>& SolarSystemSection::get_items() const {
    return m_solar_systems;
}

const std::vector<std::shared_ptr<AstroObject>>& StarSection::get_items() const {
    return m_stars;
}

const std::vector<std::shared_ptr<AstroObject>>& PlanetSection::get_items() const {
    return m_planets;
}