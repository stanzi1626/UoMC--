#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <memory>

#include "sections.h"

enum class SectionType
{
    GALAXY,
    NEBULA,
    SOLARSYSTEM,
    STAR,
    PLANET
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
    const Section* current_section() const;
    SectionType current_section_type() const { return m_current_section_type; };
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