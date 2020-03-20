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

#define CLEAR system("cls")
#define PAUSE system("pause")
#define ENDL cout<<endl


list<event_log> list_notebook;
const string fileName = "NoteBook.txt";


event_log* init(event_log* array, int *size)
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
		int size_list = 0;
		while (!fin.eof()) {
			currentString++;
			data1 = 0;
			data = "";
			int index = 0;
			if (currentString == 1) {
				getline(fin, data);

				oldNote.category = data;
			}
			else if (currentString == 2) {
				getline(fin, data);

				oldNote.header = data;
			}
			else if (currentString == 3) {
				getline(fin, data);

				oldNote.description = data;

			}
			else if (currentString == 4) {
				getline(fin, data);
				data1 = stoi(data);
				oldNote.time_event.minute = data1;

			}
			else if (currentString == 5) {
				getline(fin, data);
				data1 = stoi(data);

				oldNote.time_event.hour = data1;

			}
			else if (currentString == 6) {
				getline(fin, data);
				data1 = stoi(data);

				oldNote.time_event.day = data1;

			}
			else if (currentString == 7) {
				getline(fin, data);
				data1 = stoi(data);

				oldNote.time_event.mounth = data1;

			}
			else {
				getline(fin, data);
				data1 = stoi(data);

				oldNote.importance = data1;
				currentString = 0;

				list_notebook.push_back(oldNote);
				oldNote = event_log();
			}
		}
		*size = list_notebook.size();
		event_log* new_array = new event_log[*size];
		int index_array = 0;
		for (event_log item : list_notebook)
		{
			new_array[index_array] = item;
			index_array++;
		}

		delete[]array;
		return new_array;
	}
}

event_log* addNewNote(event_log* array, int *size)
{
	CLEAR;
	event_log newnote;
	cout << "Enter category for note:";
	cin >> newnote.category;
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

	event_log* new_array = new event_log[++*size];
	if (*size > 1) {
		for (int i = 0; i < *size - 1; i++)
		{
			new_array[i].category = array[i].category;
			new_array[i].header = array[i].header;
			new_array[i].description = array[i].description;
			new_array[i].time_event.minute = array[i].time_event.minute;
			new_array[i].time_event.hour = array[i].time_event.hour;
			new_array[i].time_event.day = array[i].time_event.day;
			new_array[i].time_event.mounth = array[i].time_event.mounth;
			new_array[i].importance = array[i].importance;
		}
		delete[]array;
		new_array[*size - 1] = newnote;

	}
	else {
		new_array[0] = newnote;
		delete[]array;
	}

	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file" << endl;
	}
	else {

		fout << newnote.category << endl;
		fout << newnote.header << endl;
		fout << newnote.description << endl;
		fout << newnote.time_event.minute << endl;
		fout << newnote.time_event.hour << endl;
		fout << newnote.time_event.day << endl;
		fout << newnote.time_event.mounth << endl;
		fout << newnote.importance << endl;


	}
	fout.close();
	cout << "New note succssful added..." << endl;
	PAUSE;
	CLEAR;
	return new_array;
}

void ShowAllNote(event_log* array, int size)
{
	CLEAR;
	for (int i = 0; i < size-1; i++)//Sortyvannya
	{
		for (int j = 0; j < size-1; j++)
		{
			if (array[j].time_event.mounth > array[j+1].time_event.mounth) {
				swap(array[j], array[j + 1]);
			}
			else if (array[j].time_event.mounth == array[j + 1].time_event.mounth) {
				if (array[j].time_event.day > array[j + 1].time_event.day) {
					swap(array[j], array[j + 1]);
				}
				else if (array[j].time_event.day == array[j + 1].time_event.day) {
					if (array[j].time_event.hour > array[j + 1].time_event.hour) {
						swap(array[j], array[j + 1]);
					}
					else if (array[j].time_event.hour == array[j + 1].time_event.hour) {
						if (array[j].time_event.minute > array[j + 1].time_event.minute) {
							swap(array[j], array[j + 1]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < size; i++) {

		if (array[i].importance == 1) {
			SetConsoleTextAttribute(color, FOREGROUND_GREEN);
			cout << "Category:" << array[i].category << endl;
			cout << "Header:" << array[i].header << endl;
			cout << "Description:" << array[i].description << endl;
			cout << "Hour:" << array[i].time_event.hour << " Minute:" << array[i].time_event.minute << endl;
			cout << "Day:" << array[i].time_event.day << " Mounth:" << array[i].time_event.mounth << endl;
			ENDL;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (array[i].importance == 2) {
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "Category:" << array[i].category << endl;
			cout << "Header:" << array[i].header << endl;
			cout << "Description:" << array[i].description << endl;
			cout << "Hour:" << array[i].time_event.hour << " Minute:" << array[i].time_event.minute << endl;
			cout << "Day:" << array[i].time_event.day << " Mounth:" << array[i].time_event.mounth << endl;
			ENDL;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else {
			SetConsoleTextAttribute(color, FOREGROUND_RED);
			cout << "Category:" << array[i].category << endl;
			cout << "Header:" << array[i].header << endl;
			cout << "Description:" << array[i].description << endl;
			cout << "Hour:" << array[i].time_event.hour << " Minute:" << array[i].time_event.minute << endl;
			cout << "Day:" << array[i].time_event.day << " Mounth:" << array[i].time_event.mounth << endl;
			ENDL;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}

	}
	PAUSE;
	CLEAR;
}

void ShowCategoryNote(event_log* array, int size)
{
	CLEAR;
	for (int i = 0; i < size - 1; i++)//Sortyvannya
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (array[j].time_event.mounth > array[j + 1].time_event.mounth) {
				swap(array[j], array[j + 1]);
			}
			else if (array[j].time_event.mounth == array[j + 1].time_event.mounth) {
				if (array[j].time_event.day > array[j + 1].time_event.day) {
					swap(array[j], array[j + 1]);
				}
				else if (array[j].time_event.day == array[j + 1].time_event.day) {
					if (array[j].time_event.hour > array[j + 1].time_event.hour) {
						swap(array[j], array[j + 1]);
					}
					else if (array[j].time_event.hour == array[j + 1].time_event.hour) {
						if (array[j].time_event.minute > array[j + 1].time_event.minute) {
							swap(array[j], array[j + 1]);
						}
					}
				}
			}
		}
	}
	string categ;
	cout << "Enter category:";
	cin >> categ;
	for (int i = 0; i < size; i++) {
		if (categ == array[i].category) {
			if (array[i].importance == 1) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN);
				cout << "Header:" << array[i].header << endl;
				cout << "Description:" << array[i].description << endl;
				cout << "Hour:" << array[i].time_event.hour << " Minute:" << array[i].time_event.minute << endl;
				cout << "Day:" << array[i].time_event.day << " Mounth:" << array[i].time_event.mounth << endl;
				ENDL;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (array[i].importance == 2) {
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
				cout << "Header:" << array[i].header << endl;
				cout << "Description:" << array[i].description << endl;
				cout << "Hour:" << array[i].time_event.hour << " Minute:" << array[i].time_event.minute << endl;
				cout << "Day:" << array[i].time_event.day << " Mounth:" << array[i].time_event.mounth << endl;
				ENDL;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else {
				SetConsoleTextAttribute(color, FOREGROUND_RED);
				cout << "Header:" << array[i].header << endl;
				cout << "Description:" << array[i].description << endl;
				cout << "Hour:" << array[i].time_event.hour << " Minute:" << array[i].time_event.minute << endl;
				cout << "Day:" << array[i].time_event.day << " Mounth:" << array[i].time_event.mounth << endl;
				ENDL;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
		}
	}
	PAUSE;
	CLEAR;
}
