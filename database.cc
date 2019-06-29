#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<fstream>

#include <bits/stdc++.h> 

using namespace std;

class Passenger {
public:
	Passenger(string a, string b, string c = "") // string c = ""
	{
		first_name = a;
		last_name = b;
		destination = c;
	}
	// overload comparison operator
	bool operator==(const Passenger& rhs) const // we don't want comparison operator to modify data of lhs
	{
		// if two objects have the same first name and last this will return true
		return (first_name == rhs.first_name && last_name ==rhs.last_name ); 
	}
	// overload comparison operator
	bool operator<(const Passenger& rhs)
	{
		// if lhs < rhs - list is sorted in lexicographical order on the last name
		return (last_name < rhs.last_name);
	}

	string first_name;
	string last_name;
	string destination;
};

int menu()
{
	int option;
	cout << endl;
	cout << "Enter one of the following options:" << endl;
	cout << "1. load reservations from file:" << endl;
	cout << "2. reserve a ticket" << endl;
	cout << "3. cancel a reservation" << endl;
	cout << "4. check reservation" << endl;
	cout << "5. display passenger list" << endl; 
	cout << "6. save passenger list" << endl;
	cout << "7. exit" << endl << endl;
	cin >> option;
	cin.get();
	return option;
}

void read_from_file(list<Passenger>& flist, string filename)
{
	// read passenger list from file
	string passenger_details;

	ifstream input(filename.c_str());

	while (getline(input, passenger_details)) {
		// Vector of string to save tokens 
		vector <string> tokens; 
		// stringstream class check1 
		stringstream check1(passenger_details); 
		string intermediate; 

		// Tokenizing w.r.t. space ' ' 
		while(getline(check1, intermediate, ' ')) 
		{ 
			tokens.push_back(intermediate); 
		} 
		flist.push_back(Passenger(tokens[0], tokens[1], tokens[2]));
	}
	input.close();
}

void insert(list<Passenger>& flist, string fn, string ln, string ds)
{
	int i = 0;
	// if input for destination has a space - store with a hyphen -
	while (ds[i]) {
		if(ds[i] == ' ') {
			ds[i] = '-';
		}
		i++;
	}
	// insert Passenger in list
	flist.push_back(Passenger(fn, ln, ds));
}

void remove(list<Passenger>& flist, string fn, string ln)
{
	// remove Passenger from list
	flist.remove(Passenger(fn, ln));
}

bool check_reservation(const list<Passenger>& flist, string fn, string ln)
{
	// if passenger in list return true otherwise return false
	bool ticket_reserved = false;
	list<Passenger>::const_iterator p;
	for (p = flist.begin(); p != flist.end(); ++p) {
		if ( p->first_name == fn && p->last_name == ln ) {
			ticket_reserved = true;
		}
	}
	return ticket_reserved;
}

void display_list(list<Passenger>& flist)
{
	// display list of Passengers
	flist.sort();
	list<Passenger>::const_iterator p;

	for (p = flist.begin(); p != flist.end(); ++p) {
		cout << p->first_name << " " << p->last_name << " " << p->destination << endl;
	}
}

void save_to_file(list<Passenger>& flist, string filename)
{
	// save Passenger list to file
	flist.sort();
	list<Passenger>::const_iterator p; // i1, i2;
	ofstream output(filename.c_str());

	for (p = flist.begin(); p != flist.end(); ++p) {
		output << p->first_name << " " << p->last_name << " " << p->destination << endl;
	}
	
	output.close();	
}
