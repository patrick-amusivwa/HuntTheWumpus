/**********************************
 * Program: gold.hpp
 * 
 * Description: Holds functions for gold class
 * Input: None
 * Output: None
 ****************************************/




#ifndef GOLD_HPP
#define GOLD_HPP
#include<iostream>
#include"event.hpp"

using namespace std;

class Gold:public Event{
		private:	
		public:
			Gold();
			void set_name_event();
			
			string event_response();
			string event_text();


};

#endif
