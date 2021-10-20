// Copyright (c) 2020 Rohnin Barrette All rights reserved.
//
// Created by: Rohnin Barrette
// Created on: Sep 2021
// this program calculates the volume of a cylinder

#include <algorithm>

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <sstream>


std::string AdressFormater(std::string full_name,
                            std::string apartment_answer,
                            std::string street_number,
                            std::string street_name,
                            std::string city_name,
                            std::string province_name,
                            std::string postal_code,
                            std::string apartment_number  ) {
    // this function formats your adress to a mailing adress

    std::string apt_street_num = "";
    std::string adress;
    std::stringstream ss;
    std::stringstream ssupper;
    std::locale loc;
    std::string str;

    ss << "\n" << full_name << "\n";
    if (apartment_answer == "y") {
        ss  << apartment_number << "-" << street_number;
    } else {
        ss << street_number;
    }
    ss << " " << street_name << std::endl;
    ss << city_name << " " << province_name << "  " << postal_code;

    str = ss.str();
    std::for_each(str.begin(), str.end(), [](char & c) { c = ::toupper(c);});



    return str;
}



int main() {
    // this function gets adress, full_name, apartment_answer, street_number,
    //   street_name, city_name, province_name, postal_code, apartment_number

    std::string apartment_number = "";
    std::string street_number;
    std::string street_name;
    std::string city_name;
    std::string province_name;
    std::string postal_code;
    std::string full_name;
    std::string apartment_answer;
    std::string adress_formated;

    // input
    std::cout << "Enter your full name: ";
    getline(std::cin, full_name);
    std::cout << "Do you live in an apartment (y/n): ";
    getline(std::cin, apartment_answer);

    if (apartment_answer == "y") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, apartment_number);
    } else {
     std::cout<<   std::endl;
    }

    std::cout << "Enter your street number :";
    getline(std::cin, street_number);

    std::cout << "Enter your street name AND type ex: Main St:";
    getline(std::cin, street_name);

    std::cout << "Enter your city name:";
    getline(std::cin, city_name);

    std::cout << "Enter your province (as an abreviation ex: ON, BC ect.):";
    getline(std::cin, province_name);

    std::cout << "Enter your postal code (ex: A1B 2C3):";
    getline(std::cin, postal_code);

    try {
        int test_int = std::stoi(street_number);

        if (apartment_number != "") {
            int test_int = std::stoi(street_number);
        }

        adress_formated = AdressFormater(
            full_name,
            apartment_answer,
            street_number,
            street_name,
            city_name,
            province_name,
            postal_code,
            apartment_number);
        // std::cout << uppercase(adress_formated) << std::endl;
        std::cout << adress_formated << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid Input" << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
