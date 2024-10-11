#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>

class House
{
public:
    House(); // Constructor
    ~House(); // Destructor

    void set_owner(const std::string&);
    void set_address(const std::string&);
    void set_bedrooms(int);
    void set_price(float);

    std::string get_owner() const;
    std::string get_address() const;
    int get_bedrooms() const;
    float get_price() const;

    void input_data();
    void display() const;

private:
    std::string owner;
    std::string address;
    int bedrooms;
    float price;
};

#endif // HOUSE_H
