#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    // wskaznik
    Resource* resource_ptr;

public:
    // konstruktor domy�lny
    ResourceManager() { resource_ptr = new Resource(); }

    // destruktor
    ~ResourceManager() { delete resource_ptr; }

    // konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& other)
    {
        resource_ptr = new Resource(*(other.resource_ptr));
    }

    // operator przypisania kopiuj�cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            Resource* new_resource = new Resource(*(other.resource_ptr));
            delete resource_ptr;
            resource_ptr = new_resource;
        }
        return *this;
    }

    // konstruktor przenosz�cy
    ResourceManager(ResourceManager&& other) noexcept // segestia vs
    {
        resource_ptr = other.resource_ptr;
    }

    // operator przypisania przenosz�cy
    ResourceManager& operator=(ResourceManager&& other) noexcept // segestia vs
    {
        if (this != &other) {
            delete resource_ptr;
            resource_ptr = other.resource_ptr;
        }
        return *this;
    }

    // metoda get()
    double get() const { return resource_ptr->get(); }
};
