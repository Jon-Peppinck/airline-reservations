# airline-reservations
STL Linked List and Operator Overloading for an airline-reservation program in C++
-----
About
-----
Simple text database for an airline reservation program.

Uses C++ Standard Template Library (STL) that stores a linked list of Passenger objects (firstName, lastName, destination)
List sorted by lexicographical order. Operator Overloading is required to make use of the STL functions.
   
-------------
Configuration
-------------
Recommended Operating System: Linux

----
Menu
----
1. load reservations from file:
2. reserve a ticket
3. cancel a reservation
4. check reservation
5. display passenger list
6. save passenger list
7. exit


--------------------------
**Operating Instructions**
--------------------------
1. Make the file utilising makefile
   *make
              
2. Run the program
    * ./demo
    
3. Example use
   * select option [2] - enter a first name, last name, and destination (No spaces) - repeat (optional)
   * select option [6] - saves passenger list to ticket_reservations.dat
   * select option [7] - exits the prompt menu
   * ./demo
   * select option [1] - loads reservations from file (sorted order)
   * select option [5] - displayes list of reservations
   * select option [3] - cancels (deletes) reservation
   * select option [6] - saves passenger list
   * select option [7] - exits the prompt menu
           
-------------
File manifest
-------------
Includes README.md, makefile, database.cc, demo.cc, unit_test.cc, ticket_reservations.dat

-----------------------------------
Copyright and Licensing information
-----------------------------------
makefile, database.cc, demo.cc, and unit_test.cc, ticket_reservations.dat are public domain software - free and open source

----------------
Troubleshooting
----------------
Please ensure all entered Passenger data (firstName, lastName, destination) is one word only. This is a simply application only 
intended to learn about operator overloading and the practicality of linked list and hence not all trivial edge cases are considered

-------
Queries
-------
For any queries please contact Jon Peppinck at mrjonpeppinck@gmail.com


