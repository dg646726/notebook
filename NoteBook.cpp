#include "NoteBook.h"
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define CLEAR system("cls");
#define PAUSE system("pause");
#define ENDL cout<<endl;



list<event_log> notebook;
const string fileName = "NoteBook.txt";


void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();

	if (isOpen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		int data1;
		event_log oldNote;
		while (!fin.eof()) {
			currentString++;
			data1 = 0;
			data = "";
			if (currentString == 1) {
				getline(fin, data);

				oldNote.header = data;
			}
			else if (currentString == 2) {
				getline(fin, data);

				oldNote.description = data;

			}
			else if (currentString == 3) {
				fin >> data1;

				oldNote.time_event.minute = data1;

			}
			else if (currentString == 4) {
				fin >> data1;

				oldNote.time_event.hour = data1;

			}
			else if (currentString == 5) {
				fin >> data1;

				oldNote.time_event.day = data1;

			}
			else if (currentString == 6) {
				fin >> data1;

				oldNote.time_event.mounth = data1;

			}
			else {
				fin >> data1;

				oldNote.importance = data1;
				currentString = 0;
				notebook.push_back(oldNote);
				oldNote = event_log();
			}
		}
	}
}

void addNewNote()
{
	event_log newnote;
	cout << "Enter header for note:";
	cin >> newnote.header;
	cout << "Enter description for note:";
	cin.ignore();
	getline(cin, newnote.description);
	cout << "Enter time for note:" << endl;
	cout << "Enter minutes:";
	cin >> newnote.time_event.minute;
	cout << "Enter hours:";
	cin >> newnote.time_event.hour;
	cout << "Enter day:";
	cin >> newnote.time_event.day;
	cout << "Enter mounth:";
	cin >> newnote.time_event.mounth;
	cout << "Enter level importance:";
	cin >> newnote.importance;

	notebook.push_back(newnote);
	ofstream fout;
	fout.open(fileName, fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file" << endl;
	}
	else {
		fout << newnote.header << endl;
		fout << newnote.description << endl;
		fout << newnote.time_event.minute << endl;
		fout << newnote.time_event.hour << endl;
		fout << newnote.time_event.day << endl;
		fout << newnote.time_event.mounth << endl;
		fout << newnote.importance << endl;


	}
	fout.close();
	cout << "New contact succssful added..." << endl;
	PAUSE
	CLEAR
}

void ShowAllNote()
{
	for (event_log item : notebook)
	{

		if (item.importance == 1) {
			SetConsoleTextAttribute(color, FOREGROUND_GREEN);
			cout << "Header:" <<item.header << endl;
			cout << "Description:" << item.description << endl;
			cout << "Time:" << item.time_event.minute << ":" << item.time_event.hour << endl;
			cout << "Day:" << item.time_event.day << "." << item.time_event.mounth << endl;
			ENDL
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (item.importance == 2) {
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "Header:" << item.header << endl;
			cout << "Description:" << item.description << endl;
			cout << "Time:" << item.time_event.minute << ":" << item.time_event.hour << endl;
			cout << "Day:" << item.time_event.day << "." << item.time_event.mounth << endl;
			ENDL
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else {
			SetConsoleTextAttribute(color, FOREGROUND_RED);
			cout << "Header:" << item.header << endl;
			cout << "Description:" << item.description << endl;
			cout << "Time:" << item.time_event.minute << ":" << item.time_event.hour << endl;
			cout << "Day:" << item.time_event.day << "." << item.time_event.mounth << endl;
			ENDL
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}

	}
	PAUSE
	CLEAR
}
