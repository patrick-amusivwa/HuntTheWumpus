/**********************************
 * Program: gold.cpp
 * Author: Sam Young
 * Date: 3/5/2017
 * Description: runs functions for gold class
 * Input: None
 * Output: None
 ***************************************/



#include"gold.hpp"

Gold::Gold(){
	set_name_event();
}

void Gold::set_name_event(){

	name_event = "Gold";
}

string Gold::event_response(){
	return "There's the gold!!!!!!";
	}



/**************************************
 * Function: event_text()
 * Description: returns the event when the player is near it
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/

string Gold::event_text(){
	return "You see a glimmer nearby";
}
