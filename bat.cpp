/**********************************
 * Program: bat.cpp
 *
 * Description: runs functions for bat class
 * Input: None
 * Output: None
 ****************************************/




#include"bat.hpp"

Bat::Bat(){
	set_name_event();
}

void Bat::set_name_event(){

	name_event = "Super Bats";
}

string Bat::event_response(){
	return "The bats take you to another room!";
	}



/**************************************
 * Function: event_text()
 * Description: returns the event when the player is near it
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/



string Bat::event_text(){
	return "You hear the sound of wings flapping.";
}
