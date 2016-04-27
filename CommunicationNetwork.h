//
//  CommunicationNetwork4.hpp
//  Assignment 4
//
//  Created by Jake Ursetta on 2/15/16.
//  Copyright © 2016 Jake Ursetta. All rights reserved.
//

#ifndef CommunicationNetwork_h
#define CommunicationNetwork_h

#include <stdio.h>
#include <iostream>
#include <vector>


// creation of strcture City
struct City{
    std::string cityName;
    std::string message;
    std::vector<std::string> previousMessagesPassed;
    std::vector<std::string> previousMessagesRecieved;
    int balance;
    City *next;
    City *previous;
    
    City(){}; // default constructor
    
    // creation of string names
    City(std::string initName, City *initNext, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }
    
};

// Class header creation
class CommunicationNetwork
{
public:
    // public functions
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(std::string, std::string);
    void buildNetwork();
    bool listBuilt();
    int checkPersonalBalance();
    void transmitMsgCoast(std::string);
    void transmitMsg(std::string,std::string);
    int checkCost(std::string);
    void printCityInfo(std::string);
    void printPreviousSent();
    void printNetwork();
    void deleteCity(std::string cityNameDelete);
    void clearNetwork();
    
    
    
protected:
private:
    // private variables for the address of head and tail.
    City *head;
    City *tail;
    int personalBalance;
    std::vector<std::string> previousMessagesSent;
};



#endif /* CommunicationNetwork4_hpp */
