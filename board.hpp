/**********************************
 * Program: board.hpp
 * Author: Sam Young
 * Date: 3/5/2017
 * Description: Holds functions for board class
 * Input: None
 * Output: None
 ****************************************/





#ifndef BOARD_HPP
#define BOARD_HPP
#include<iostream>
#include<cstdlib>
#include<vector>
#include"event.hpp"
#include"room.hpp"
#include"gold.hpp"
#include"bat.hpp"
#include"wumpus.hpp"
#include"pit.hpp"
#include<ctime>

using namespace std;

class Board{
	private: 
		vector<vector<Room*> > tables;
		int size_of_table;
		int direction;
		int player_spot_x;
		int player_spot_y;	
		int player_spot;
		
		int rope_spot_x;
		int rope_spot_y;

		int event_array[7];
		int pit_1;
		int pit_2;
		int super_1;
		int super_2;
		int wumpus_1;
		int rope_1;
		int gold_1;

		int arrow;
		int wumpus_die;
		int take_gold;
		 





	public:
		Board();
		Board(int size);
		int set_direction();
		void rand_events();
		int in_board(int r, int c);	
		int win();	
		void area_check();
		int event_check();			
		void start_event();	
		void print_map();	
		int arrow_move();	
		void wumpus_move();		


		~Board();



};

#endif
