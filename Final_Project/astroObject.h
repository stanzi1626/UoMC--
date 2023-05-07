#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>

const std::set<std::string> hubble_type {
    "E0", "E3", "E5", "E7", "S0", "Sa", "Sb", "Sc", "SBa", "SBb", "SBc", "Irr"
};

class AstroObject
{
protected:
    std::string m_name;
public:
    virtual ~AstroObject() = default;
    virtual std::string get_astro_name() { return m_name; }
};

class Galaxy : public AstroObject{
private:
    // std::string m_galaxy_type;
    double m_total_mass;
    // double m_stellar_mass_fraction;
    // double m_redshift;
    // std::vector<Galaxy> m_satellites;
public:
    Galaxy() {};
    Galaxy(const std::string& line);
    ~Galaxy() {};
};

class Star : public AstroObject{
private:
    double m_mass;
    // double m_age;
    // double m_radius;
    // double m_temperature;

public:
    Star() {};
    Star(const std::string& line);
    virtual ~Star() {};
};

class Planet : public AstroObject
{
private:
    double m_mass;
    // double m_radius;
    // double m_number_moons;
public:
    Planet() {};
    Planet(const std::string& line);
    ~Planet() {};
};

class StellarNebula : public AstroObject
{
private:
    double m_mass;
    // double m_radius;
    // std::vector<Star> m_stars;
public:
    StellarNebula() {};
    StellarNebula(const std::string& line);
    ~StellarNebula() {};
};

class SolarSystem : public AstroObject
{
private:
    double m_age;
    // std::vector<Planet> planets;
    // std::vector<Star> stars;
public:
    SolarSystem() {};
    SolarSystem(const std::string& line);
    ~SolarSystem() {};
};