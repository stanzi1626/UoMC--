#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>

const std::set<std::string> hubble_type {
    "E0", "E3", "E5", "E7", "S0", "Sa", "Sb", "Sc", "SBa", "SBb", "SBc", "Irr"
};

class AstroObject
{
public:
    AstroObject() {};
    virtual ~AstroObject() {};
};

class Galaxy : public AstroObject
{
private:
    std::string galaxy_type;
    double total_mass;
    double stellar_mass_fraction;
    double redshift;
    std::vector<Galaxy> satellites;
public:
    Galaxy() {};
    ~Galaxy() {};
};

class Star : public AstroObject
{
private:
    std::string name;
    double mass;
    double age;
    double radius;
    double temperature;

public:
    Star() {};
    virtual ~Star() {};

    void evolve();
};

class Planet : public AstroObject
{
private:
    double mass;
    double radius;
    double temperature;
public:
    Planet() {};
    ~Planet() {};
};

class StellarNebula : public AstroObject
{
private:
    double mass;
    double radius;
    std::vector<Star> stars;
public:
    StellarNebula() {};
    ~StellarNebula() {};
};

class SolarSystem : public AstroObject
{
private:
    std::vector<Planet> planets;
    std::vector<Star> stars;
public:
    SolarSystem() {};
    ~SolarSystem() {};
};