//
//  CommunicationNetwork4.cpp
//  Assignment 4
//
//  Created by Jake Ursetta on 2/15/16.
//  Copyright © 2016 Jake Ursetta. All rights reserved.
//
//  Contains all methods needs for the header file to run and access

#include "CommunicationNetwork.h"

#include <fstream>
#include <sstream>
#include <vector>

// Creation of communicationNetwork
CommunicationNetwork::CommunicationNetwork(){
    personalBalance = 40;
    head = NULL;
    tail = NULL;
}

// desctructor
CommunicationNetwork::~CommunicationNetwork(){
    
}


// add city function
void CommunicationNetwork::addCity(std::string previousCity, std::string newCity){
    
    // set current to head of list
    City *current = head;
    City *addedCity = new City;
    addedCity -> balance = 0;
    
    // check if adding node to replace head
    if(previousCity == "First"){
        addedCity -> cityName = newCity;
        addedCity -> message = "";
        addedCity -> next = head;
        addedCity -> previous = NULL;
        head -> previous = addedCity;
        head = addedCity;
        return;
        
    }
    
    // search for previous city otherwise
    while(current != NULL){
        if(current -> cityName == previousCity){
            break;
        }
        // set current equal to the next city
        current = current -> next;
    }
    
    if(current != NULL){
        // check if the node goes on the tail
        if(current == tail){
            addedCity -> cityName = newCity;
            addedCity -> message = "";
            addedCity -> next = NULL;
            addedCity -> previous = tail;
            tail -> next = addedCity;
            tail = addedCity;
            
        }
        // check if the node goes in the middle
        else{
            addedCity -> cityName = newCity;
            addedCity -> message = "";
            addedCity -> next = current -> next;
            addedCity -> previous = current;
            addedCity -> next -> previous = addedCity;
            current -> next = addedCity;
        }
    }
}


// build net work
void CommunicationNetwork::buildNetwork(){
    std::string cities[10] = {"Los Angeles","Phoenix","Denver","Dallas","St.Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
    
    // create head node
    head = new City;
    head -> cityName = cities[0];
    head -> message = "";
    head -> next = NULL;
    head -> previous = NULL;
    head -> balance = 0;
    
    std::cout << "NULL <- " << head -> cityName;
    
    // create current node
    City *current = head;
    
    
    // build network based on string array and set next addresses accordingly
    int i = 1;
    while(i<10){
        City *temp = new City;
        temp -> cityName = cities[i];
        temp -> message = "";
        temp -> next = NULL;
        temp -> previous = current;
        temp -> balance = 0;
        
        std::cout << " <-> " << temp -> cityName;
        
        current -> next = temp;
        current = temp;
        
        i++;
    }
    
    tail = current;
    
    std::cout << " -> NULL" << std::endl;
    
}


// transmit message
void CommunicationNetwork::transmitMsgCoast(std::string message){
    int cost = checkCost(tail->cityName);
    if(cost > personalBalance){
        std::cout << "Insufficient Funds" << std::endl;
        std::cout << "Cost to Transmit: $" << cost << std::endl;
        std::cout << "Personal Balance: $" << personalBalance << std::endl;
        return;
    }
    City *sender = head;
    sender -> message = message;
    previousMessagesSent.push_back(message);
    while(sender != NULL){
        // print message, save message, and finally delete from sender
        // check to make sure not on tail node
        if(sender -> next != NULL){
            std::cout<< sender->cityName<<" sent "<<sender->message << " to " << sender -> next -> cityName<< std::endl;
            sender -> next -> message = sender -> message;
            sender -> previousMessagesPassed.push_back(sender -> message);
            sender -> message = "";
            sender -> balance ++;
            sender = sender -> next;
            personalBalance --;
        }
        // prints the received line if it is the tail
        else{
            std::cout<< sender->cityName<<" received "<<sender->message<< " from " << sender -> previous -> cityName <<std::endl;
            sender -> previousMessagesRecieved.push_back(sender -> message);
            sender -> message = "";
            sender = sender -> next;
        }
    }
    // checks balances and deductions and prints them
    std::cout << "-----------------------" <<  std::endl;
    std::cout << "Balance Deducted: $" << cost << std::endl;
    std::cout << "New Personal Balance: $" << personalBalance << std::endl;
    
}

void CommunicationNetwork::transmitMsg(std::string cityRecieved, std::string message){
    City *sender = head;
    City * recieved = sender;
    int cost = checkCost(cityRecieved);
    if (cost == 0){
        return;
    }
    if(cost > personalBalance){
        std::cout << "Insufficient Funds" << std::endl;
        std::cout << "Cost to Transmit: $" << cost << std::endl;
        std::cout << "Personal Balance: $" << personalBalance << std::endl;
        return;
    }
    
    while(recieved -> cityName != cityRecieved){
        recieved = recieved -> next;
    }
    
    // check to make sure the list has been build
    sender -> message = message;
    previousMessagesSent.push_back(message);
    while(sender != recieved -> next){
        // print message, save message, and finally delete from sender
        // check to make sure not on tail node
        if(sender != recieved){
            std::cout<< sender->cityName<<" sent "<<sender->message << " to " << sender -> next -> cityName<< std::endl;
            sender -> next -> message = sender -> message;
            sender -> previousMessagesPassed.push_back(sender -> message);
            sender -> message = "";
            sender -> balance ++;
            sender = sender -> next;
            personalBalance --;
        }
        // printe received info and treats the received city as a tail
        else{
            std::cout<< sender->cityName<<" received "<<sender->message<< " from " << sender -> previous -> cityName <<std::endl;
            sender -> previousMessagesRecieved.push_back(sender -> message);
            sender -> message = "";
            sender = sender -> next;
        }
    }
    // checks balances and deductions and prints them
    std::cout << "-----------------------" <<  std::endl;
    std::cout << "Balance Deducted: $" << cost << std::endl;
    std::cout << "New Personal Balance: $" << personalBalance << std::endl;
}

// print the network
void CommunicationNetwork::printNetwork(){
    City *current = head;
    if (current == NULL) return;
    // access each node
    std::cout << "NULL <- " << current -> cityName;
    current = current -> next;
    while(current != NULL){
        std::cout << " <-> " << current -> cityName;
        current = current -> next;
    }
    std::cout << " -> NULL" << std::endl;
    
}

// delete city from list

void CommunicationNetwork::deleteCity(std::string cityDelete){
    
    City * current = head;
    City * temp = head;
    
    // Find city to delete
    while(current != NULL){
        if(cityDelete == current->cityName){
            break;
        }
        current = current->next;
        temp = current;
    }
    if(current!=NULL){
        // if city is the head
        if(current == head){
            head = current->next;
            head -> previous = NULL;
            delete temp;
        }
        // if city is the tail
        else if(current == tail){
            tail = current ->previous;
            tail -> next = NULL;
            delete temp;
        }
        
        // if city is in the middle
        else{
            current->previous->next = current -> next;
            current -> next -> previous = current -> previous;
            delete temp;
        }
    }
}

// finds info on city and prints it
void CommunicationNetwork::printCityInfo(std::string name){
    City *temp = head;
    // while loop looks for city name
    while(temp != NULL){
        if(temp -> cityName == name){
            break;
        }
        temp = temp -> next;
    }
    // if not found, prints city not found
    if(temp == NULL){
        std::cout << "City Not Found" << std::endl;
    }
    // if found prints all information needed from the pointer to the city which was requested
    else{
        std::cout << "City: " << temp -> cityName << std::endl;
        std::cout << "Balance: $" << temp -> balance << std::endl;
        // checks for head case
        if(temp != head){
            std::cout << "City Previous: " << temp -> previous -> cityName << std::endl;
        }
        else{
            std::cout << "City Previous: None" << std::endl;
        }
        // checks for tail case
        if(temp != tail){
            std::cout << "City Next:  " << temp -> next -> cityName << std::endl;
        }
        else{
            std::cout << "City Next: None" << std::endl;
        }
        // checks if any messages have been passed and prints accordingly
        if(temp->previousMessagesPassed.size() == 0){
            std::cout << "Previous Messages Passed: None" <<  std::endl;
        }
        else{
            std::cout << "Previous Messages Passed" <<  std::endl;
            for(int i = 0 ; i < temp->previousMessagesPassed.size() ; i ++){
                std::cout << i+1 << ". " << temp -> previousMessagesPassed[i] << std::endl;
            }
            std::cout << "---------------------------" <<  std::endl;
        }
        // checks if any messages have been received and prints accordingly
        if(temp->previousMessagesRecieved.size() == 0){
            std::cout << "Previous Messages Received: None" <<  std::endl;
        }
        else{
            std::cout << "Previous Messages Received" <<  std::endl;
            for(int i = 0 ; i < temp->previousMessagesRecieved.size() ; i ++){
                std::cout << i+1 << ". " << temp -> previousMessagesRecieved[i] << std::endl;
            }
            std::cout << "---------------------------" <<  std::endl;
        }
    }
}


// Prints all messages that have been sent
void CommunicationNetwork::printPreviousSent(){
    // checks if any messages have been sent yest and prints accordingly
    if(previousMessagesSent.size() == 0){
        std::cout << "No messages have been sent" << std::endl;
    }
    else{
        std::cout << "Previously Sent Message" << std::endl;
        std::cout << "-----------------------" << std::endl;
        for(int i = 0 ; i < previousMessagesSent.size() ; i++){
            std::cout << previousMessagesSent[i]<< std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }
}

// Clearing entire Network
void CommunicationNetwork::clearNetwork(){
    City * current = head;
    City * temp = head;
    
    //run through each item and delete it
    while(current != NULL){
        current = current->next;
        std::cout << "deleting " << temp -> cityName << std::endl;
        delete temp;
        temp = current;
    }
    
    head = current;
    
}

// helper function to check if the city is built or not
bool CommunicationNetwork::listBuilt(){
    if(head == NULL) return false;
    else return true;
}

// Returns personal balance due to the fact that it is a private variable
int CommunicationNetwork::checkPersonalBalance(){
    return personalBalance;
}


// helper and public method. This method is called before any tranmission to insure that the user has enough funcds. It is also used for the user to check the cost of sending a mission before they decide to send it.
int CommunicationNetwork::checkCost(std::string cityRecieved){
    City * temp = head;
    int cost = 0;
    // insures user is not passing the message to the sender
    if(head -> cityName == cityRecieved){
        std::cout << "Cannot send message from sender city to sender city" << std::endl;
        return cost;
    }
    // looks for city
    while(temp != NULL){
        if(temp -> cityName == cityRecieved){
            return cost;
        }
        cost ++;
        temp = temp -> next;
    }
    // returns error if it is not found
    if (temp == NULL){
        std::cout << "City Not found" << std::endl;
        return 0;
    }
    else{
        return cost;
    }
}
