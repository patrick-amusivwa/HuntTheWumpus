/**********************************
 * Program: bat.hpp
 * Author: Sam Young
 * Date: 3/5/2017
 * Description: Holds functions for bat class
 * Input: None
 * Output: None
 ****************************************/





#ifndef BAT_HPP
#define BAT_HPP
#include<iostream>
#include"event.hpp"

using namespace std;

class Bat:public Event{
	
		public:
			Bat();
			void set_name_event();
			
			string event_response();
			string event_text();


};

#endif
