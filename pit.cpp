/**********************************
 * Program: pit.cpp
 * 
 * Description: Holds functions for pit class
 * Input: None
 * Output: None
 ****************************************/





#include"pit.hpp"

Pit::Pit(){
	set_name_event();
}

void Pit::set_name_event(){

	name_event = "Pitfall of death";
}

string Pit::event_response(){
	return "Oh no, you fell in the pitfall of death :(";
	}



/**************************************
 * Function: event_text()
 * Description: returns the event when the player is near it
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/


string Pit::event_text(){
	return "You feel a cool breeze.";
}
