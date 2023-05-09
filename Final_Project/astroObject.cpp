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
    m_mass = std::stof(field);

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
    m_mass = std::stof(field);

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
    m_mass = std::stof(field);

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

    // Read the mass column and convert to float
    std::getline(ss, field, ',');
    m_mass = std::stof(field);

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

    // Read the mass column and ignore
    std::getline(ss, field, ',');

    // Read the age column and convert to float
    std::getline(ss, field, ',');
    m_age = std::stof(field);

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
    std::cout << "Total Mass: " << m_mass << std::endl;
    print_parent();
    print_children();
}

void Star::print_astro_info() const {
    std::cout << "Star: " << m_name << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
    print_parent();
    print_children();
}

void Planet::print_astro_info() const {
    std::cout << "Planet: " << m_name << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
    print_parent();
    print_children();
}

void StellarNebula::print_astro_info() const {
    std::cout << "Stellar Nebula: " << m_name << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
    print_parent();
    print_children();
}

void SolarSystem::print_astro_info() const {
    std::cout << "Solar System: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
    print_parent();
    print_children();
}

std::string Galaxy::get_info() const {
    // Type, Name, Parent name, Mass, Age
    std::string galaxy_info = std::string("Galaxy") + std::string(",") + m_name + std::string(",") \
                              + m_parent_name + std::string(",") + std::to_string(m_mass) + std::string(",");
    return galaxy_info;
}

std::string Star::get_info() const {
    // Type, Name, Parent name, Mass, Age
    std::string star_info = std::string("Star") + std::string(",") + m_name + std::string(",") \
                              + m_parent_name + std::string(",") + std::to_string(m_mass) + std::string(",");
    return star_info;
}

std::string Planet::get_info() const {
    // Type, Name, Parent name, Mass, Age
    std::string planet_info = std::string("Planet") + std::string(",") + m_name + std::string(",") \
                              + m_parent_name + std::string(",") + std::to_string(m_mass) + std::string(",");
    return planet_info;
}

std::string StellarNebula::get_info() const {
    // Type, Name, Parent name, Mass, Age
    std::string nebula_info = std::string("Stellar Nebula") + std::string(",") + m_name + std::string(",") \
                              + m_parent_name + std::string(",") + std::to_string(m_mass) + std::string(",");
    return nebula_info;
}

std::string SolarSystem::get_info() const {
    // Type, Name, Parent name, Mass, Age
    std::string solar_system_info = std::string("Solar System") + std::string(",") + m_name + std::string(",") \
                              + m_parent_name + std::string(",") + std::string(",") + std::to_string(m_age);
    return solar_system_info;
}