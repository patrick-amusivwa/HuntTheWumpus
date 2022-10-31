/**********************************
 * Program: wumpus.hpp

 * Description: Holds functions for wumpus class
 * Input: None
 * Output: None
 * ***************************************/



#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include<iostream>
#include"event.hpp"
#include<string>
using namespace std;

class Wumpus:public Event{
		private:	
		public:
			Wumpus();
			void set_name_event();
			
			string event_response();
			string event_text();


};

#endif
