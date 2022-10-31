/**********************************
 * Program: pit.hpp
 * 
 * Description: Holds functions for pit  class
 * Input: None
 * Output: None
 ****************************************/






#ifndef PIT_HPP
#define PIT_HPP
#include<iostream>
#include"event.hpp"

using namespace std;

class Pit:public Event{
	
		public:
			Pit();
			void set_name_event();
			
			string event_response();
			string event_text();


};

#endif
