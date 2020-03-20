#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
#include "NoteBook.h"

using namespace std;


int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));

	int size = 0;
	event_log* notebook = new event_log[size];

	notebook=init(notebook, &size);
	int action = 0;

	do
	{

		cout << "     Menu" << endl;
		cout << "1.Add new note" << endl;
		cout << "2.Show all note" << endl;
		cout << "3.Show category note" << endl;
		cout << "4.Exit" << endl;
		cout << endl;
		cout << "Select action:";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			cout << "    ADD NEW NOTE:" << endl;
			notebook=addNewNote(notebook, &size);
			break;
		case 2:
			cout << "    LIST ALL NOTE:" << endl;
			ShowAllNote(notebook, size);

			break;
		case 3:
			cout << "    LIST CATEGORY NOTE:" << endl;
			ShowCategoryNote(notebook, size);

			break;
			
		case 4:
			cout << "Bye" << endl;
			break;
		default:
			cout << "Please select action (1 - 3)" << endl;
			break;
		}
	} while (action != 4);




	system("pause");
	return 0;
}
