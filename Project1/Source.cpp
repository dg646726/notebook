#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

struct date{

	int day;
	int month;
	string time;


};


struct event_log {

	string header;
	string description;
	date time_event;
	int importance;


};


int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));
	int size = 0;
	event_log* notebook = new event_log[size];







	system("pause");
	return 0;
}