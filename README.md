PROJECT SUMMARY:

This program is an extension off of the Assignment 4 communication network. The program is a menu style program similar to the other assignments from the semester.
The following includes a list of new additions to the assignment;

* Messages can be sent to specific cities as well as across the coast. Messages fall into two categories for cities. Either the message is being "Passed", meaning it was not meant for the city but will be passed on to the next city in the linked list. Or they are "received", meaning they were intended for the city.

* The user has an initial personal balance to send messages with. Every city that must pass or send a message charges $1. The cities do not charge for recieved messages. These cities collect this money from the personal balance and record it in their city balance. If the user does not have enough balance to send the message, the message will not be sent.

* Each city records the messages it has passed as well as the messages that it has received. These are stored as vectors which contain strings.
	- Passed messages are messages that a city has received and then continued to send down the linked list.
	- Received messages are messages that a city was specifically sent and did not pass on.

* City records of messages passed and received can be accessed at any time.

* Messages which are sent are also recorded and stored after they are sent in a vector and can be accessed at any time.


The following list includes the options of the menu and their description.

Menu Items:

1.	Build Network: This method imports a linked list containing cities. The linked list is represented as the following,
		NULL <- Los Angeles <-> Phoenix <-> Denver <-> Dallas <-> St.Louis <-> Chicago <-> Atlanta <-> Washington, D.C. <-> New York <-> Boston -> NULL
	The method is REQUIRED for any other operation. Calling the other methods except for exit and check personal balance will result in an error message.

2.	Print Network: This method prints the linked list after is has been created. This print looks very similar to the build network example shown above. However, It will show changes in newly added or deleted cities.

3.	Display Personal Balance: This method simply prints the users current balance.

4.	Check Cost: This method checks the cost of sending a message to any city in the linked list.

5.	Transmit Message Coast-To-Coast: This method sends a message through the entire linked list, given that the user has sufficient funds to do so.

6.	Transmit Message to Specific city: This method sends a message through the linked list to a specific city, given that the user has sufficient funds to do so and the city exists. The message will not be passed any further than the specified city.

7.	Print City Info: This method prints out the following information of each city
	City Name
	City Balance
	City next in the linked list
	City Previous in the linked list
	Messages Passed
	Messages Received

8.	Display Previously Sent Messages: This method displays all messages that have been sent over the programs lifetime.

9.	Add City: This method adds another node to the linked list. All that is required is the name of the new city and the city that it will be placed in front of.

10.	Delete City: This method deletes a city from the linked list given a city name.

11.	Clear Network: This method deletes the entire linked list of cities.

-------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN:

In order to run this program, Please download the following files:

AdvancedComm.cpp
CommunicationNewtwork.h
CommunicationNewtwork.cpp

The AdvancedComm.cpp is equivalent to the main.cpp file which runs the menu driven program. After downloading, use any c++ application that you have been using for the duration of CSCI 2270 to build and run the AdvancedComm.cpp file. Please insure all files are in the same directory so that they can find eachother. The program does NOT require any command line arguments or additional read in files. This means the only requirements are the 2 cpp files, the header file, and a c++ application such as xcode or code blocks, in order to run the program. After the program is running, The user will be prompted with a menu that will look like the following.

======Main Menu======
1.  Build Network
2.  Print Network Path
3.  Display Personal Balance
4.  Check Cost
5.  Transmit Message Coast-To-Coast
6.  Transmit Message To Specific City
7.  Print City Info
8.  Display Previously sent messages
9.  Add City
10. Delete City
11. Clear Network
12. Quit

The user will then type in a number corresponding to the desired action in the menu. For example, the User will want to build the network before preforming other operations. to do this, they will type in '1' , followed by pressing the return key on the keyboard. The menu will reprint after each method has finished and the user can choose the next option. The User can then send messages, add or delete cities, and check info on cities or previous actions. Final messages from each method will be printed above the menu after they execute. for example. Calling Print City Info will show the following. Notice that the menu reprints after the info has been printed.

- 7
Please enter a city name: 
- Denver
City: Denver
Balance: $0
City Previous: Phoenix
City Next:  Dallas
Previous Messages Passed: None
Previous Messages Received: None
======Main Menu======
1.  Build Network
2.  Print Network Path
3.  Display Peronsal Balance
4.  Check Cost
5.  Transmit Message Coast-To-Coast
6.  Transmit Message To Specific City
7.  Print City Info
8.  Display Previously sent messages
9.  Add City
10. Delete City
11. Clear Network
12. Quit

-------------------------------------------------------------------------------------------------------------------------------------
DEPENDENCIES:

No Third Party libraries are required for this program to run. Only the standard Library, and vector Library.

-------------------------------------------------------------------------------------------------------------------------------------
SYSTEM REQUIREMENTS:

No other requirements are needed other than a C++ application for building and running the program.

-------------------------------------------------------------------------------------------------------------------------------------
GROUP MEMBERS:
* Jake Ursetta

-------------------------------------------------------------------------------------------------------------------------------------
CONTRIBUTORS:
* Tristan Hustrulid - Monetary System Concept

-------------------------------------------------------------------------------------------------------------------------------------
Open issues/ Bugs:

No known issues or bugs reported from 4/27/2016
