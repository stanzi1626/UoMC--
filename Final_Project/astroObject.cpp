#include <string>
#include <sstream>

#include "astroObject.h"

Galaxy::Galaxy(const std::string& line)
{
    // Initialize a stringstream with the CSV line
    std::stringstream ss(line);
    std::string field;

    // Ignore the first column
    std::getline(ss, field, ',');

    // Read the name column
    std::getline(ss, m_name, ',');

    // Read the mass column and convert to float
    std::getline(ss, field, ',');
    m_total_mass = std::stof(field);

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

    // Read the mass column and ignore
    std::getline(ss, field, ',');

    // Read the age column and convert to float
    std::getline(ss, field, ',');
    m_age = std::stof(field);

    // Ignore the rest of the line
    ss.ignore();
    ss.clear();
}

void Galaxy::print_astro_info() const {
    std::cout << "Galaxy: " << m_name << std::endl;
    std::cout << "Total Mass: " << m_total_mass << std::endl;
}

void Star::print_astro_info() const {
    std::cout << "Star: " << m_name << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
}

void Planet::print_astro_info() const {
    std::cout << "Planet: " << m_name << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
}

void StellarNebula::print_astro_info() const {
    std::cout << "Stellar Nebula: " << m_name << std::endl;
    std::cout << "Mass: " << m_mass << std::endl;
}

void SolarSystem::print_astro_info() const {
    std::cout << "Solar System: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
}