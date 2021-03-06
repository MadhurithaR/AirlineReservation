// AirlineReservation.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include  <string>
using namespace std;

// The Total number of seats on the flight
int totalSeats = 10;
int availableSeat[10];


string DisplayInfo(string Name, string Last)
{
	return Name +" "+ Last;
}

int currentTotalSeats(int seatsBooked)
{
	totalSeats = totalSeats - seatsBooked;

	return totalSeats;
}

void printMenuOptions()
{
	cout << "*********************" << endl;
	cout << "**Welcome to AIRKAL!**" << endl;
	cout << "Please choose one of the menu options." << endl;
	cout << "1. Choose a Seat." << endl;
	cout << "2. Reserve any Seat." << endl;
	cout << "3. Find flight Schedule." << endl;
	cout << "4. Display passenger info." << endl;
	cout << "5. Flight details." << endl;
	cout << "6. User ticket information." << endl;
	cout << "7. Exit the program." << endl;
	cout << "*********************" << endl <<endl;
}

bool availableSeats(int choosenSeat)
{	
	if (availableSeat[choosenSeat] == 0 && choosenSeat >= 0)
	{
		cout << "THE CHOSEN SEAT IS NOT AVAILABLE PLEASE CHOOSE A DIFFERENT SEAT" << endl << endl;
		return false;
	}

	if (availableSeat[choosenSeat] > 0)
	{
		cout << "THE CHOSEN SEAT IS AVAILABLE PLEASE CHOOSE MORE SEATs." << endl << endl;
		availableSeat[choosenSeat] = 0; // set element at location i to i + 100
	}	
	
	cout << "AVAILABLE SEATS ARE:"<< endl;

	for (int j = 0; j < 10; j++) 
	{
		if(availableSeat[j] != 0)
		{
			cout << j << endl;
		}
	}
	return true;	
}

int main()
{	
	int option = 0;
	string name;
	string last;
	string FullName;
	int seatsToBook;
	
	// initialize elements of array n to 0          
	for (int i = 0; i < 10; i++) {
		availableSeat[i] = 1; // set element at location i to i + 100
	}

	//cout << "Hello World!";// << endl;// << std::endl;
			
	while (true)
	{
		printMenuOptions();
		cout << "The option chosen is:";
		cin >> option;
		switch (option)
		{	
		case 1:
			bool avail;
			cout << " *** WELCOME TO RESERVING SEATS AT AIRKAL. *** " << endl;
			availableSeats(-1);
			cout << " PLEASE ENTER THE SEAT NUMBER YOU NEED = " ;
			int choosenSeat;
			cin >> choosenSeat;			
			avail = availableSeats(choosenSeat);
			break;
		case 2:
			cout << " *** WELCOME TO RESERVING SEATS AT AIRKAL. *** " << endl;
			cout << " PLEASE ENTER THE NUMBER OF SEATS YOU NEED = " ;
			cin >> seatsToBook;
			//Reserve a seat
			if (totalSeats >= seatsToBook)
			{
			totalSeats = currentTotalSeats(seatsToBook);
			cout << " THE NUMBER OF SEATS REMAINING ARE = " << totalSeats << endl;
			}
			else
			{
			cout << " *** SORRY WE DO NO HAVE THE REQUESTED NUMBER OF SEATS. *** " << endl;
			cout << " *** PLEASE CHOOSE A DIFFERENT TIME/DATE ON AIRKAL. ***" << endl;
			}
			break;
		case 3:
			cout << "Print Flight Schedule";
			break;
		case 4:
			//cin << "First Name : " name;
			//cin << "Last Name : " last;
			cout << "Display Passenger Info";
			FullName = DisplayInfo("Ma", "Su");
			cout << "The Passenger Full Name  is " << FullName << endl;
			break;
		case 5:
			cout << "Display Flight Details" << endl;
			break;
		case 6:
			cout << "User Ticket Information" << endl;
			break;
		case 7:
			cout << "Thank you for visiting AIRKAL" << endl;
			return 0;
		}
	}

	return 0;
}
