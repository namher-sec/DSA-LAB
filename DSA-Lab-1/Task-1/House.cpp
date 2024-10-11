#include "House.h"

House::House(){

}

House::~House(){

}

void House::set_owner(const std::string& owner)
{
   this->owner = owner;
}

void House::set_address(const std::string& address)
{
   this->address = address;
}

void House::set_bedrooms(int bedrooms)
{
   this->bedrooms = bedrooms;
}

void House::set_price(float price)
{
   this->price = price;
}

std::string House::get_owner() const {
   return owner;
}

std::string House::get_address() const
{
   return address;
}

int House::get_bedrooms() const
{
   return bedrooms;
}

float House::get_price() const
{
   return price;

}

void House::input_data()
{

   std::cout << "Enter Owner: ";
   std::cin.ignore();
   std::getline(std::cin, owner);

   std::cout << "Enter Address: ";
   std::getline(std::cin, address);

   std::cout << "Enter Number of Bedrooms: ";
   std::cin >> bedrooms;

   std::cout << "Price: ";
   std::cin >> price;

   std::cout << '\n';
}

void House::display() const
{

  std::cout << "Owner: " << owner << '\n';
  std::cout << "Address: " << address << '\n';
  std::cout << "Number of Bedrooms: " << bedrooms << '\n';
  std::cout << "Price: " << price << '\n';
}

