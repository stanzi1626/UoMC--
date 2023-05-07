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
    virtual void add_object(std::unique_ptr<AstroObject> objPtr) = 0;
    virtual void print_all_objects() = 0;
};

class GalaxySection : public Section, public Galaxy{
private:
    std::vector<std::unique_ptr<AstroObject>> galaxies;
public:
    GalaxySection() {};
    ~GalaxySection() {};

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        galaxies.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& galaxy : galaxies) {
            galaxy->print();
        }
    }

    void print() override {
        std::cout << "I am a GalaxySection\n";
    }
};

class NebulaSection : public Section, public StellarNebula{
private:
    std::vector<std::unique_ptr<AstroObject>>  nebulae;
public:
    NebulaSection() {};
    ~NebulaSection() {};

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        nebulae.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& nebula : nebulae) {
            nebula->print();
        }
    }

    void print() override {
        std::cout << "I am a NebulaSection\n";
    }
};

class SolarSystemSection : public Section, public SolarSystem{
private:
    std::vector<std::unique_ptr<AstroObject>> solarSystems;
public:
    SolarSystemSection() {};
    ~SolarSystemSection() {};

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        solarSystems.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& solarSystem : solarSystems) {
            solarSystem->print();
        }
    }

    void print() override {
        std::cout << "I am a SolarSystemSection\n";
    }
};

class StarSection : public Section, public Star{
private:
    std::vector<std::unique_ptr<AstroObject>> stars;
public:
    StarSection() {};
    ~StarSection() {};

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        stars.push_back(std::move(objPtr));
    }


    void print_all_objects() override {
        for (auto& star : stars) {
            star->print();
        }
    }

    void print() override {
        std::cout << "I am a StarSection\n";
    }
};

class PlanetSection : public Section, public Planet{
private:
    std::vector<std::unique_ptr<AstroObject>> planets;
public:
    PlanetSection() {};
    ~PlanetSection() {};

    void add_object(std::unique_ptr<AstroObject> objPtr) override {
        planets.push_back(std::move(objPtr));
    }

    void print_all_objects() override {
        for (auto& planet : planets) {
            planet->print();
        }
    }

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
    std::unique_ptr<AstroObject> make_object(const std::string& line);
    void add_object(std::string sectionName, std::unique_ptr<AstroObject> object);

    void print_current_section();
    void printSections();
    void read_file();
    // void sort();
    // void search();
    // void add();
    // void remove();
    // void save();
};