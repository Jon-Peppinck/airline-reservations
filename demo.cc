#include "database.cc"

int main()
{
	list<Passenger> p_flight_list;
	string name;
	string fname;
	string lname;
	string dest;

	while (true) 
	{
		switch (menu())
		{
			case 1:	
				{
					read_from_file(p_flight_list, "ticket_reservations.dat");
					break;
				}

			case 2: 
				{
					cout << "first name of passenger:" << endl; 
					cin >> fname;
					cout << "last name of passenger:" << endl; 
					cin >> lname;
					cout << "name of destination:" << endl; 
					cin >> dest;
					insert(p_flight_list, fname, lname, dest);
					break;
				}

			case 3: 
				{
					cout << "first name of passenger:" << endl;
					cin >> fname;
					cout << "first name of passenger:" << endl;
					cin >> lname;
					remove(p_flight_list, fname, lname);
					break;
				}

			case 4: 
				{
					cout << "first name of passenger:" << endl;
					cin >> fname;
					cout << "last name of passenger:" << endl;
					cin >> lname;
					if (check_reservation(p_flight_list, fname, lname))
						cout << "this passenger has a ticket reservation" << endl;
					else
						cout << "this passenger does not have a ticket reservation" << endl;
					break;
				}

			case 5:	
				{
					display_list(p_flight_list);
					break;
				}

			case 6: 
				{
					save_to_file(p_flight_list, "ticket_reservations.dat");
				}
				break;

			case 7:
				return 0;
		}
	}
	
	return 0;
}

