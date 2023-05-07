#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <memory>

#include "astroObject.h"

enum class SectionType
{
    GALAXY,
    NEBULA,
    SOLARSYSTEM,
    STAR,
    PLANET
};

class Section {
public:
    virtual ~Section() = default;
    virtual void print() = 0;
};

class GalaxySection : public Section, public Galaxy{
private:
    std::vector<Galaxy> galaxies;
public:
    GalaxySection() {};
    ~GalaxySection() {};

    void print() override {
        std::cout << "I am a GalaxySection\n";
    }
};

class NebulaSection : public Section, public StellarNebula{
private:
    std::vector<StellarNebula> nebulae;
public:
    NebulaSection() {};
    ~NebulaSection() {};

    void print() override {
        std::cout << "I am a NebulaSection\n";
    }
};

class SolarSystemSection : public Section, public SolarSystem{
private:
    std::vector<SolarSystem> solarSystems;
public:
    SolarSystemSection() {};
    ~SolarSystemSection() {};

    void print() override {
        std::cout << "I am a SolarSystemSection\n";
    }
};

class StarSection : public Section, public Star{
private:
    std::vector<Star> stars;
public:
    StarSection() {};
    ~StarSection() {};

    void print() override {
        std::cout << "I am a StarSection\n";
    }
};

class PlanetSection : public Section, public Planet{
private:
    std::vector<Planet> planets;
public:
    PlanetSection() {};
    ~PlanetSection() {};

    void print() override {
        std::cout << "I am a PlanetSection\n";
    }
};

class StarCatalogue
{
protected:
    std::map<std::string, std::unique_ptr<Section>> m_catalogue;
    SectionType m_current_section_type;
    
public:
    StarCatalogue();
    ~StarCatalogue();

    void move_up();
    void move_down();
    Section* current_section();
    void addSection(const std::string& name, std::unique_ptr<Section> section);
    void print_current_section();
    void printSections();
    // void sort();
    // void search();
    // void add();
    // void remove();
    // void save();
    // void load();
};