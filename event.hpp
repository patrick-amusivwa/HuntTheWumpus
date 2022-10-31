/**********************************
 * Program: evemt.hpp
 * 
 * Description: Holds functions for evemt class
 * Input: None
 * Output: None
 ****************************************/




#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>

using namespace std;

class Event{

	protected:
		string name_event;

	public:
		virtual void set_name_event() = 0;
	
		string get_name_event();

/**************************************
 * Function: event_response()
 * Description: uses polymorphism in other classes
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/

		virtual string event_response() =0;
		virtual string event_text() = 0;

};

#endif
