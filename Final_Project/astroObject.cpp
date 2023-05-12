#include <string>
#include <sstream>

#include "astroObject.h"

void AstroObject::set_parent(std::shared_ptr<AstroObject> parent) {
    m_parent = parent;
}

void AstroObject::add_child(std::shared_ptr<AstroObject> child) {
    m_children.push_back(child);
    child->set_parent(shared_from_this());
}

Galaxy::Galaxy(const std::string& line)
{
        std::stringstream ss(line);
        std::string field;

        // Ignore the first column
        std::getline(ss, field, ',');
        // Read the name column
        std::getline(ss, m_name, ',');
        // Ignore the parent ID column
        std::getline(ss, field, ',');
        // Ignore the mass column
        std::getline(ss, field, ',');
        // Read Ascension column
        std::getline(ss, field, ',');
        m_ascension = std::stod(field);
        // Read Declination column
        std::getline(ss, field, ',');
        m_declination = std::stod(field);
        // Read Apparent Magnitude column
        std::getline(ss, field, ',');
        m_apparent_magnitude = std::stod(field);
        // Read Redshift column
        std::getline(ss, field, ',');
        m_redshift = std::stod(field);
        // Read Distance from Earth column
        std::getline(ss, field, ',');
        m_distance_from_earth = std::stod(field);
        // Read Galaxy Type column
        std::getline(ss, m_galaxy_type, ',');
        // Read Stellar Mass Fraction column
        std::getline(ss, field, ',');
        m_stellar_mass_fraction = std::stod(field);
        // Ignore the rest of the line
        ss.ignore();
        ss.clear();
    }

Star::Star(const std::string& line)
{
    // Initialize a stringstream with the CSV line
    std::stringstream ss(line);
    std::string field;

    // Ignore the first column
    std::getline(ss, field, ',');
    // Read the name column
    std::getline(ss, m_name, ',');
    // Read the parent ID column
    std::getline(ss, m_parent_name, ',');
    // Read the mass column and convert to float
    std::getline(ss, field, ',');
    m_mass = std::stod(field);
    // Read Ascension column
    std::getline(ss, field, ',');
    m_ascension = std::stod(field);
    // Read Declination column
    std::getline(ss, field, ',');
    m_declination = std::stod(field);
    // Read Apparent Magnitude column
    std::getline(ss, field, ',');
    m_apparent_magnitude = std::stod(field);
    // Read Redshift column
    std::getline(ss, field, ',');
    m_redshift = std::stod(field);
    // Read Distance from Earth column
    std::getline(ss, field, ',');
    m_distance_from_earth = std::stod(field);
    // Ignore Galaxy Type and Stellar Mass Fraction columns
    std::getline(ss, field, ',');
    std::getline(ss, field, ',');
    // Read the radius column and convert to double
    std::getline(ss, field, ',');
    m_radius = std::stod(field);
    // Read the temperature column and convert to double
    std::getline(ss, field, ',');
    m_temperature = std::stod(field);
    // Read metalicity column and convert to double
    std::getline(ss, field, ',');
    m_metalicity = std::stod(field);
    // Ignore the rest of the line
    ss.ignore();
    ss.clear();
}

Planet::Planet(const std::string& line)
{
    // Initialize a stringstream with the CSV line
    std::stringstream ss(line);
    std::string field;

    // Ignore the first column
    std::getline(ss, field, ',');
    // Read the name column
    std::getline(ss, m_name, ',');
    // Read the parent ID column
    std::getline(ss, m_parent_name, ',');
    // Read the mass column and convert to float
    std::getline(ss, field, ',');
    m_mass = std::stod(field);
    // Read Ascension column
    std::getline(ss, field, ',');
    m_ascension = std::stod(field);
    // Read Declination column
    std::getline(ss, field, ',');
    m_declination = std::stod(field);
    // Read Apparent Magnitude column
    std::getline(ss, field, ',');
    m_apparent_magnitude = std::stod(field);
    // Read Redshift column
    std::getline(ss, field, ',');
    m_redshift = std::stod(field);
    // Read Distance from Earth column
    std::getline(ss, field, ',');
    m_distance_from_earth = std::stod(field);
    // Ignore Galaxy Type and Stellar Mass Fraction columns
    std::getline(ss, field, ',');
    std::getline(ss, field, ',');
    // Read the radius column and convert to double
    std::getline(ss, field, ',');
    m_radius = std::stod(field);
    // Ignore temperature and metalicity columns
    std::getline(ss, field, ',');
    std::getline(ss, field, ',');
    // Read number of moons column and convert to int
    std::getline(ss, field, ',');
    m_number_moons = std::stoi(field);
    // Read the orbital period column and convert to double
    std::getline(ss, field, ',');
    m_orbital_period = std::stod(field);
    // Read Rotation Period column and convert to double
    std::getline(ss, field, ',');
    m_rotation_period = std::stod(field);
    // Read Orbital Eccentricity column and convert to double
    std::getline(ss, field, ',');
    m_orbital_eccentricity = std::stod(field);

    // Ignore the rest of the line
    ss.ignore();
    ss.clear();
}


StellarNebula::StellarNebula(const std::string& line)
{
    // Initialize a stringstream with the CSV line
    std::stringstream ss(line);
    std::string field;

    // Ignore the first column
    std::getline(ss, field, ',');
    // Read the name column
    std::getline(ss, m_name, ',');
    // Read the parent ID column
    std::getline(ss, m_parent_name, ',');
    // Ignore the mass column
    std::getline(ss, field, ',');
     // Read Ascension column
    std::getline(ss, field, ',');
    m_ascension = std::stod(field);
    // Read Declination column
    std::getline(ss, field, ',');
    m_declination = std::stod(field);
    // Read Apparent Magnitude column
    std::getline(ss, field, ',');
    m_apparent_magnitude = std::stod(field);
    // Read Redshift column
    std::getline(ss, field, ',');
    m_redshift = std::stod(field);
    // Read Distance from Earth column
    std::getline(ss, field, ',');
    m_distance_from_earth = std::stod(field);
    // Ignore the rest of the line
    ss.ignore();
    ss.clear();
}

SolarSystem::SolarSystem(const std::string& line)
{
    // Initialize a stringstream with the CSV line
    std::stringstream ss(line);
    std::string field;

    // Ignore the first column
    std::getline(ss, field, ',');
    // Read the name column
    std::getline(ss, m_name, ',');
    // Read the parent ID column
    std::getline(ss, m_parent_name, ',');
    // Ignore the mass column
    std::getline(ss, field, ',');
     // Read Ascension column
    std::getline(ss, field, ',');
    m_ascension = std::stod(field);
    // Read Declination column
    std::getline(ss, field, ',');
    m_declination = std::stod(field);
    // Read Apparent Magnitude column
    std::getline(ss, field, ',');
    m_apparent_magnitude = std::stod(field);
    // Read Redshift column
    std::getline(ss, field, ',');
    m_redshift = std::stod(field);
    // Read Distance from Earth column
    std::getline(ss, field, ',');
    m_distance_from_earth = std::stod(field);
    // Ignore the rest of the line
    ss.ignore();
    ss.clear();
}

void AstroObject::print_parent() const {
    if (m_parent.expired()) {
        std::cout << "Parent: NONE" << std::endl;
    }
    else {
        std::cout << std::endl << "Parent: " << m_parent.lock()->get_astro_name() << std::endl;
    }
}

void AstroObject::print_children() const {
    if (m_children.empty()) {
        std::cout << "Children: NONE" << std::endl;
    }
    else {
        std::cout << "Children: " << std::endl;
        for (auto it = m_children.begin(); it != m_children.end(); ++it) {
            std::cout << " | " << " -> " << (*it)->get_astro_name() << std::endl;
        }
    }
}

void Galaxy::print_astro_info() const {
    std::cout << "Galaxy: " << m_name << std::endl;
    std::cout << "Ascensions: " << m_ascension << std::endl;
    std::cout << "Declination: " << m_declination << std::endl;
    std::cout << "Apparent Magnitude: " << m_apparent_magnitude << std::endl;
    std::cout << "Redshift: " << m_redshift << std::endl;
    std::cout << "Distance from Earth: " << m_distance_from_earth << std::endl;
    std::cout << "Galaxy Type: " << m_galaxy_type << std::endl;
    std::cout << "Stellar Mass Fraction: " << m_stellar_mass_fraction << std::endl;
    print_parent();
    print_children();
}

void Star::print_astro_info() const {
    std::cout << "Star: " << m_name << std::endl;
    std::cout << "Ascensions: " << m_ascension << std::endl;
    std::cout << "Declination: " << m_declination << std::endl;
    std::cout << "Apparent Magnitude: " << m_apparent_magnitude << std::endl;
    std::cout << "Redshift: " << m_redshift << std::endl;
    std::cout << "Distance from Earth: " << m_distance_from_earth << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
    std::cout << "Radius: " << m_radius << std::endl;
    std::cout << "Temperature: " << m_temperature << std::endl;
    std::cout << "Metallicity: " << m_metalicity << std::endl;
    print_parent();
    print_children();
}

void Planet::print_astro_info() const {
    std::cout << "Planet: " << m_name << std::endl;
    std::cout << "Ascensions: " << m_ascension << std::endl;
    std::cout << "Declination: " << m_declination << std::endl;
    std::cout << "Apparent Magnitude: " << m_apparent_magnitude << std::endl;
    std::cout << "Redshift: " << m_redshift << std::endl;
    std::cout << "Distance from Earth: " << m_distance_from_earth << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
    std::cout << "Radius: " << m_radius << std::endl;
    std::cout << "Number of Moons: " << m_number_moons << std::endl;
    std::cout << "Orbital Period: " << m_orbital_period << std::endl;
    std::cout << "Rotation Period: " << m_rotation_period << std::endl;
    std::cout << "Orbital Eccentricity: " << m_orbital_eccentricity << std::endl;
    print_parent();
    print_children();
}

void StellarNebula::print_astro_info() const {
    std::cout << "Stellar Nebula: " << m_name << std::endl;
    std::cout << "Ascensions: " << m_ascension << std::endl;
    std::cout << "Declination: " << m_declination << std::endl;
    std::cout << "Apparent Magnitude: " << m_apparent_magnitude << std::endl;
    std::cout << "Redshift: " << m_redshift << std::endl;
    std::cout << "Distance from Earth: " << m_distance_from_earth << std::endl;
    print_parent();
    print_children();
}

void SolarSystem::print_astro_info() const {
    std::cout << "Solar System: " << m_name << std::endl;
    std::cout << "Ascensions: " << m_ascension << std::endl;
    std::cout << "Declination: " << m_declination << std::endl;
    std::cout << "Apparent Magnitude: " << m_apparent_magnitude << std::endl;
    std::cout << "Redshift: " << m_redshift << std::endl;
    std::cout << "Distance from Earth: " << m_distance_from_earth << std::endl;
    print_parent();
    print_children();
}
// Type,Name,Parent Name,Mass,Ascension,Declination,Apparent Magnitude,
// Redshift,Distance from Earth,Galaxy Type,Stellar Mass Fraction,Radius,T
// emperature,Metalicity,Number of Moons,Orbital Period,Rotation Period,Orbital Eccentricity
std::string Galaxy::get_info() const {
    std::string galaxy_info = std::string("Galaxy") + std::string(",") + m_name + std::string(",") +
                              m_parent_name + std::string(",") + std::string(",") +
                              std::to_string(m_ascension) + std::string(",") + std::to_string(m_declination) +
                              std::string(",") + std::to_string(m_apparent_magnitude) + std::string(",") +
                              std::to_string(m_redshift) + std::string(",") + std::to_string(m_distance_from_earth) +
                              std::string(",") + m_galaxy_type + std::string(",") + std::to_string(m_stellar_mass_fraction) +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",");
    return galaxy_info;
}

std::string Star::get_info() const {
    std::string star_info = std::string("Galaxy") + std::string(",") + m_name + std::string(",") +
                              m_parent_name + std::string(",") + std::to_string(m_mass) + std::string(",") +
                              std::to_string(m_ascension) + std::string(",") + std::to_string(m_declination) +
                              std::string(",") + std::to_string(m_apparent_magnitude) + std::string(",") +
                              std::to_string(m_redshift) + std::string(",") + std::to_string(m_distance_from_earth) +
                              std::string(",")+ std::string(",") +
                              std::string(",") + std::string(",") + std::to_string(m_temperature) +
                              std::string(",") + std::to_string(m_metalicity) + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",");
    return star_info;
}

std::string Planet::get_info() const {
    std::string planet_info = std::string("Galaxy") + std::string(",") + m_name + std::string(",") +
                              m_parent_name + std::string(",") + std::to_string(m_mass) + std::string(",") +
                              std::to_string(m_ascension) + std::string(",") + std::to_string(m_declination) +
                              std::string(",") + std::to_string(m_apparent_magnitude) + std::string(",") +
                              std::to_string(m_redshift) + std::string(",") + std::to_string(m_distance_from_earth) +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::to_string(m_radius) + std::string(",") +
                              std::string(",") + std::string(",") + std::to_string(m_number_moons) +
                              std::string(",") + std::to_string(m_orbital_period) + std::string(",") + std::to_string(m_rotation_period) +
                              std::string(",") + std::to_string(m_orbital_eccentricity);
    return planet_info;
}

std::string StellarNebula::get_info() const {
    std::string nebula_info = std::string("Galaxy") + std::string(",") + m_name + std::string(",") +
                              m_parent_name + std::string(",") + std::string(",") +
                              std::to_string(m_ascension) + std::string(",") + std::to_string(m_declination) +
                              std::string(",") + std::to_string(m_apparent_magnitude) + std::string(",") +
                              std::to_string(m_redshift) + std::string(",") + std::to_string(m_distance_from_earth) +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",");
    return nebula_info;
}

std::string SolarSystem::get_info() const {
    std::string solar_system_info = std::string("Galaxy") + std::string(",") + m_name + std::string(",") +
                              m_parent_name + std::string(",") + std::string(",") +
                              std::to_string(m_ascension) + std::string(",") + std::to_string(m_declination) +
                              std::string(",") + std::to_string(m_apparent_magnitude) + std::string(",") +
                              std::to_string(m_redshift) + std::string(",") + std::to_string(m_distance_from_earth) +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",") + std::string(",") +
                              std::string(",");
    return solar_system_info;
}