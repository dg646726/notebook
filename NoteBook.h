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

	string header;
	string description;
	date time_event;
	int importance;


};

void init();
void addNewNote();
void ShowAllNote();