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
    std::shared_ptr<AstroObject> make_object(const std::string& line);
    void make_usr_object();
    void add_object(const std::string& sectionName, std::shared_ptr<AstroObject>& object);

    void print_current_section();
    void printSections();
    std::shared_ptr<AstroObject> get_object(const std::string& object_name) const;
    void set_object_relationships();
    void remove_object(std::shared_ptr<AstroObject> object_ptr);
    void read_file(const std::string& filename);
    void save_to_csv(const std::string& filename) const;
};