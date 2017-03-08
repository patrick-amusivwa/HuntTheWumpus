/**********************************
 * Program: wumpus.cpp
 * Author: Sam Young
 * Date: 3/5/2017
 * Description: functions for wumpus
 * Input: None
 * Output: None
 *****************************************/



#include"wumpus.hpp"
#include<string>
using namespace std;
Wumpus::Wumpus(){
	set_name_event();
}

void Wumpus::set_name_event(){

	name_event = "Wumpus";
}

string Wumpus::event_response(){
	return "Wumpus ate you man sorry :(";
	}





/**************************************
 * Function: event_text()
 * Description: returns the event when the player is near it
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *****************************/

string Wumpus::event_text(){
	return "Something smells terrible here...";
}
