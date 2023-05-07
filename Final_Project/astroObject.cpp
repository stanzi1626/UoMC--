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