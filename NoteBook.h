#pragma once
#include<string>
using namespace std;

struct date {

	int minute;
	int hour;
	int day;
	int mounth;



};


struct event_log {
	string category;
	string header;
	string description;
	date time_event;
	int importance;


};

event_log* init(event_log* array, int *size);
event_log* addNewNote(event_log* array, int *size);
void ShowAllNote(event_log* array, int size);
void ShowCategoryNote(event_log* array, int size);