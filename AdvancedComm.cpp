//
//  main.cpp
//  Assignment 4
//
//  Created by Jake Ursetta on 2/15/16.
//  Copyright © 2016 Jake Ursetta. All rights reserved.
//
// This is the main function which calls the header function files for the class communication network
// This function runs the menu for the entire program

#include <iostream>
#include "CommunicationNetwork.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // declare input and instance of class
    string input = "0";
    CommunicationNetwork city1;
    
    // run through while loop for menu
    while(input != "12"){
        cout << "======Main Menu======" << endl;
        cout << "1.  Build Network" << endl;
        cout << "2.  Print Network Path" << endl;
        cout << "3.  Display Peronsal Balance" << endl;
        cout << "4.  Check Cost" << endl;
        cout << "5.  Transmit Message Coast-To-Coast" << endl;
        cout << "6.  Transmit Message To Specific City" << endl;
        cout << "7.  Print City Info" << endl;
        cout << "8.  Display Previously sent messages" << endl;
        cout << "9.  Add City" << endl;
        cout << "10. Delete City" << endl;
        cout << "11. Clear Network" << endl;
        cout << "12. Quit" << endl;
        
        
        getline(cin,input);
        
        
        
        // build network
        if(input == "1"){
            if(!city1.listBuilt()){
                // Check for build list
                city1.buildNetwork();
            }
            else{
                cout << "Please clear the network before re-building." << endl;
            }
        }
        
        // Print netowrk
        else if(input == "2"){
            // Check for build list
            if(city1.listBuilt()){
                city1.printNetwork();
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
            
        }
        
        // Check personal balance
        else if (input == "3"){
            cout << "Personal Balance: $" << city1.checkPersonalBalance() << endl;
        }
        
        // Check cost to send message
        else if (input == "4"){
            // Check for build list
            if(city1.listBuilt()){
                string city;
                cout << "Enter city to send a message to: " << endl;
                getline(cin,city);
                int cost = city1.checkCost(city);
                
                if(cost != 0) cout << "Cost to send message: " << city1.checkCost(city) << endl;
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
        }
        
        // Transmit message coast to coast...
        else if(input == "5"){
            // Check for build list
            if(city1.listBuilt()){
                string message;
                cout << "Please enter message to transmit across the coast: " << endl;
                getline(cin,message);
                city1.transmitMsgCoast(message);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
        }
        
        // Transmit to a specific city
        else if (input == "6"){
            // Check for build list
            if(city1.listBuilt()){
                string message;
                string city;
                cout << "Please select a city to send a message to: " << endl;
                getline(cin,city);
                cout << "Please enter message to transmit: " << endl;
                getline(cin,message);
                city1.transmitMsg(city, message);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
        }
        
        // Print city info
        else if(input == "7"){
            // Check for build list
            if(city1.listBuilt()){
                cout << "Please enter a city name: " << endl;
                string name;
                getline(cin,name);
                city1.printCityInfo(name);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
        }
        
        // Print previously sent messgeas
        else if (input == "8"){
                city1.printPreviousSent();
        }
        
        // add city in command window
        else if(input == "9"){
            // Check for build list
            if(city1.listBuilt()){
            string cityNew;
            string cityPrevious;
            cout << "Enter a city name: " << endl;
            getline(cin,cityNew);
            cout << "Enter a previous city name: " << endl;
            getline(cin,cityPrevious);
            city1.addCity(cityPrevious, cityNew);
            }
            else{
                cout << "Please Build Network before adding cities." << endl;
            }
            
        }
        
        // delete city
        else if(input == "10"){
            // Check for build list
            if(city1.listBuilt()){
            string cityDelete;
            cout << "Enter a city name: " << endl;
            getline(cin,cityDelete);
            //cin >> cityDelete;
            city1.deleteCity(cityDelete);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
            
        }
        
        // Clear out network
        else if(input == "11"){
            // Check for build list
            if(city1.listBuilt()){
            city1.clearNetwork();
            }
            else{
                std::cout << "Empty list, " << "Current Balance: $" << city1.checkPersonalBalance() << std::endl;
            }
        }
        
        else if(input != "12"){
            cout << "Please enter a valid number" << endl;
        }
        
    }
    // leave program
    cout << "Goodbye!" << endl;
    return 0;
}
