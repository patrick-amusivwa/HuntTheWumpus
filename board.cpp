/**********************************
 * Program: board.cpp
 *
 * Description: runs functions for board class and runs the game
 * Input: None
 * Output: None
 ****************************************/


#include"gold.hpp"
#include"board.hpp"

Board::Board(){
//	tables = 0;
	player_spot_x = 0;
	player_spot_y = 0;
	arrow = 3;
	wumpus_die = 0;
	take_gold = 0;
	
}




/**************************************
 * Function: Board(int size)
 * Description: initializeds the board for the player to play on
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************/





Board::Board(int size){
/*	size_of_table=size;
	std::vector<vector<int> > tables(size);
	for(int i = 0; i<size; i++){
		tables[i].resize(size);	
*/
/*	for(int r=0; r<size; r++){
		vector<vector<int> > tables(size);
		for(int c=0; c<size; c++){
			tables(size).push_back(new int);
		}
		*/	
//	}
/*
	size_of_table = size;

	tables = new Room*[size];
	for(int i = 0; i < size; i++){
		tables[i] = new Room[size];

	}
*/
	size_of_table = size;
	for(int r =0; r<size; r++){
		vector<Room*> row;
		for(int c = 0; c< size; c++){
			row.push_back(new Room);
		}
		tables.push_back(row);
		}
	

	player_spot_x = 0;
	player_spot_y = 0;
	arrow = 3;
	wumpus_die = 0;
	take_gold = 0;

}



/**************************************
 * Function: set_direction()
 * Description: moves the player around the board
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/






int Board::set_direction(){
	int place;
	
	cout<<"Which way to go?: "<<endl;
	cout<<"1 up"<<endl;
	cout<<"2 down"<<endl;
	cout<<"3 left"<<endl;
	cout<<"4 right"<<endl;
	cin >> place;

	if(place == 1){
		if(in_board(player_spot_x-1, player_spot_y)){
			player_spot_x--;
		}
		else{
			cout<<"not on board"<<endl;
	}
	}


        else if(place == 2){
                if(in_board(player_spot_x+1, player_spot_y)){
                        player_spot_x++;
                }
                else{
                        cout<<"not on board"<<endl;
        }
        }


        else if(place == 3){
                if(in_board(player_spot_x, player_spot_y-1)){
                        player_spot_y--;
                }
                else{
                        cout<<"not on board"<<endl;
        }
        }

        else if(place == 4){
                if(in_board(player_spot_x, player_spot_y+1)){
                        player_spot_y++;
                }
                else{
                        cout<<"not on board"<<endl;
        }
        }
	int check = 1;
	for(int i = 0; i < size_of_table; i++){
		for(int j = 0; j < size_of_table; j++){
			if(i == player_spot_x && j == player_spot_y){
				player_spot = check;
			}
			check++;
		}
	}

	cout<<	"Location: "<< player_spot <<endl;
	if(event_check() == 0){
		return 1;
	}
	area_check();

	if(win() == 1){
		cout<<"YOU WINNN MAN. NOW SLEEP."<<endl;
		return 1;
	}
	return 0;
}				



/**************************************
 * Function: arrow_move()
 * Description: arrow shoots out with at most 3 distance
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************/




int Board::arrow_move(){
	int spot;
	int checker = 1;
	int shoot;
	for(int i = 0; i < size_of_table; i++){
		for(int j = 0; j < size_of_table; j++){
			if(i == player_spot_x && j == player_spot_y){
				spot = checker;
			}
			checker++;
		}
	}

	cout<<"where do you want to shoot?: "<<endl;
	cout<<"1. up"<<endl;
	cout<<"2. down"<<endl;
	cout<<"3. left"<<endl;
	cout<<"4. right"<<endl;
	cin>>shoot;
	
	if(shoot == 1){
		arrow--;
		for(int i = 1; i<=3; i++){
			if(in_board(player_spot_x-i, player_spot_y)){
				cout<< spot - (size_of_table*i)<<endl;
				if(wumpus_die == 1){
					break;
				}

				if(spot - (size_of_table) == wumpus_1){
					cout<<"You killed the wumpus!!"<<endl;
					wumpus_die = 1;
					return 0;
				}
			}
		}
	if(arrow > 0 && wumpus_die == 1){
                        return 0;
                        }
                else if (arrow <=0 && wumpus_die == 1){
                        cout<< "Your arrows are gone and wumpus is dead. Stop wasting time and get out of there!"<<endl;
                }
	



}



        else if(shoot == 2){
                arrow--;
                for(int i = 1; i<=3; i++){
                        if(in_board(player_spot_x+i, player_spot_y)){
                                cout<< spot + (size_of_table*i)<<endl;
                                if (wumpus_die ==1){
					break;
				}			
				
				if(spot + (size_of_table*i) == wumpus_1){
                                        cout<<"You killed the wumpus!!"<<endl;
					wumpus_die = 1;
                                        return 0;
                                }
                        }
                }
        	if(arrow > 0 && wumpus_die == 1){
			return 0;
			}
		else if (arrow <=0 && wumpus_die == 1){
			cout<< "Your arrows are gone and wumpus is dead. Stop wasting time and get out of there!"<<endl;
		}
	}



        else if(shoot == 3){
                arrow--;
                for(int i = 1; i<=3; i++){
                        if(in_board(player_spot_x, player_spot_y-i)){
                                cout<< spot -i <<endl;
                                if(wumpus_die == 1){
					break;
				}
				if(spot - i  == wumpus_1){
                                        cout<<"You killed the wumpus!!"<<endl;
                                        wumpus_die = 1;
                                        return 0;
                                }
                        }
                }
        

	if(arrow > 0 && wumpus_die == 1){
                        return 0;
                        }
                else if (arrow <=0 && wumpus_die == 1){
                        cout<< "Your arrows are gone and wumpus is dead. Stop wasting time and get out of there!"<<endl;
                }



	}




        else if(shoot == 4){
                arrow--;
                for(int i = 1; i<=3; i++){
                        if(in_board(player_spot_x, player_spot_y+i)){
                                cout<< spot + i<<endl;
                                if(wumpus_die == 1){
				break;
				}

				if(spot + i == wumpus_1){
                                        cout<<"You killed the wumpus!!"<<endl;
                                        wumpus_die = 1;
                                        return 0;
                                }
                        /*	else{
					cout<<"You missed the wumpus"<<endl;
					int t = rand() % 4;
					if(t == 3){
						cout<<"The wumpus  woke up and moved."<<endl;
						for (int i  = 0; i<size_of_table;i++){
							for (int j = 0; j < size_of_table; j++){
						tables[i][j]->set_wumpus_event() ;
						//tables[i][j] = event_array[5];	
					}
					
				}
		//	tables[i][j] = wumpus_1;
			//wumpus_1 = event_array[5];
			}			
				
			}*/
                }
       		}
		 
	if(arrow > 0 && wumpus_die == 1){
                        return 0;
                        }
        else if (arrow <=0 && wumpus_die == 1){
                        cout<< "Your arrows are gone and wumpus is dead. Stop wasting time and get out of there!"<<endl;
                }
	//	wumpus_move();
	//	rand_events();
	//	start_event();	  
		
	}
	
	if(wumpus_die==0){
		//wumpus_move();
		//return 0;
	}
	else if(wumpus_die==1){
		return 0;
	}
	if(arrow <= 0 && wumpus_die == 0){
		cout<< "Ran out of arrows so you ran out of life :)"<<endl;
		arrow=3;
		return 1;
	}
/*	else if(arrow == 0 && wumpus_die == 1){
		cout<< "You ran out of arrows man and already killed the wumpus. Stop wasting time and get out of here!"<<endl;
		return 0;
	}*/
	else{
	
		return 0;
	}

}



/**************************************
 * Function: wumpus_move()
 * Description: moves wumpus if arrow shot 75%
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************/





void Board::wumpus_move(){
	int wump_move = rand() % 4;
	if(wump_move == 3){
		cout<<"You shot the arrow and nothing happened"<<endl;
	}
	else{ 
	
		cout<<"You hear a HUGE MONSTER move"<<endl;
/*		int t;	
		t = rand() % (size_of_table*size_of_table) +1;
		//if(t== player_spot||t == wumpus_1 || t == super_1 || t == super_2 ||t == pit_1 ||t==pit_2|| t== rope_1 || t == gold_1){
		while(t== player_spot||t == event_array[0] || t == event_array[1] || t == event_array[2] ||t ==event_array[3] || t== event_array[4] || t == event_array[6]){
			
			t = rand() % (size_of_table*size_of_table) +1;
				break;
		//	}
		}
//		else{
			
		event_array[5] = t; 	
		t= wumpus_1 ; 
//			}
	


	
        for(int i =0 ; i < 7; i++){
                cout << "Event array: " << event_array[i] << endl;
	
}

*/
int n_event = 1;
int if_sim = 0;
int t;
	while(n_event < 7){
                t = rand() % (size_of_table*size_of_table) + 1;
                for(int i = 1; i<n_event;i++){
                        if(t == event_array[i]){
                                if_sim = 1;
                                break;
                        }
                }
                if(if_sim == 1){
                        if_sim = 0;
                }
                else if(if_sim == 0){
                        event_array[n_event] = t;
                        n_event++;
                }
        }
for(int i = 0; i < 7;i++){
	cout<<"event array: " << event_array[i] << endl;
	}
//WORK ON THIS
				
/*	int place = wumpus_1;

        for(int i = 0; i < size_of_table; i++){
                for(int j = 0; j< size_of_table; j++){
                        if(place ==1){
                                tables[i][j]->set_wumpus_event();
                                }
                        place--;
                }

        }
		
*/

}
}




/**************************************
 * Function: rand_events()
 * Description: sets event to an array
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 **************************************/



void Board::rand_events(){
	int n_event = 1;
	int event[7];
	int if_sim = 0;
	int t;
	event[0] = rand () % (size_of_table*size_of_table) + 1;
	
	while(n_event < 7){
		t = rand() % (size_of_table*size_of_table) + 1;
		for(int i = 0; i<n_event;i++){
			if(t == event[i]){
				if_sim = 1;
				break;
			}
		}
		if(if_sim == 1){
			if_sim = 0;
		}
		else if(if_sim == 0){
			event[n_event] = t;
			n_event++;
		}
	}
	
	cout<<endl;

	rope_1 = event[0];
	super_1 = event[1];
	super_2 = event[2];
	pit_1 = event[3];
	pit_2 = event[4];
	wumpus_1 = event[5];
	gold_1 = event[6];

	for(int i =0; i < 7;i++){
		event_array[i] = event[i];
	}
	
//	for(int i =0 ; i < 7; i++){
//		cout << "Event array: " << event_array[i] << endl;
//}
}
	

/**************************************
 * Function: in_board()
 * Description: checks if persson is on board
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/

int Board::in_board(int r, int c){
	if(r<0||r>size_of_table-1|| c<0|| c>size_of_table-1){
		return 0;
}
	else{
		return 1;
}
}


/**************************************
 * Function: win()
 * Description: returns win when player gets all the win conditions
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/




int Board::win(){
	if(wumpus_die == 1 && take_gold == 1 && player_spot == event_array[0]){
		wumpus_die = 0;
		take_gold = 0;
		arrow = 3;
		return 1;
	
	}
	else{
		 return 0;
	}
}
void Board::area_check(){
	int spot;
	int checker = 1;
	
	for(int i = 0; i<size_of_table; i++){
		for(int j= 0; j< size_of_table; j++){
			if(i == player_spot_x && j == player_spot_y){
				spot = checker;
			}
			checker++;
		}	
	}
//	if(wumpus_die ==0){
	if(in_board(player_spot_x-1, player_spot_y)){
		for(int i = 1; i < 6; i++){
			if(spot-size_of_table == event_array[5] && wumpus_die ==1){
                        cout<<"he ded"<<endl;
				break;
                        }
	


			if(spot - size_of_table == event_array[i]){
				tables[player_spot_x-1][player_spot_y]->print_event_response();
}
		/*	if(spot- size_of_table == event_array[5] && wumpus_die ==1){
			cout<<"he ded"<<endl;
				
			}*/
		}
	}
	
        if(in_board(player_spot_x+1, player_spot_y)){
                for(int i = 1; i < 6; i++){
                  if(spot+size_of_table == event_array[5] && wumpus_die ==1){
                        cout<<"he ded"<<endl;
				break;
                        }
			

			 if(spot + size_of_table == event_array[i]){
                                tables[player_spot_x+1][player_spot_y]->print_event_response();
                        }
                       /* if(spot+size_of_table == event_array[5] && wumpus_die ==1){
                        cout<<"he ded"<<endl;

                        }*/

		
		}
        }


        if(in_board(player_spot_x, player_spot_y-1)){
                for(int i = 1; i < 6; i++){
               	if(spot-1 == event_array[5] && wumpus_die ==1){
                        cout<<"he ded"<<endl;
                                break;
                        }

		
			if(spot - 1 == event_array[i]){
                                tables[player_spot_x][player_spot_y-1]->print_event_response();
                        }
                }
        }


        if(in_board(player_spot_x, player_spot_y+1)){
                for(int i = 1; i < 6; i++){
                        if(spot+1 == event_array[5] && wumpus_die ==1){
                        cout<<"he ded"<<endl;
                                break;
                        }


			if(spot + 1 == event_array[i]){
                                tables[player_spot_x][player_spot_y+1]->print_event_response();
                        }
                }
        }
//}
/*	else if(wumpus_die == 1){
		if(in_board(player_spot_x-1, player_spot_y)){
                
                        if(spot - size_of_table == event_array[5]){
                                cout << "He's dead"<<endl;
                        }
                }
        
                if(in_board(player_spot_x+1, player_spot_y)){

                        if(spot +  size_of_table == event_array[5]){
                                cout << "He's dead"<<endl;
                        }
                }

                if(in_board(player_spot_x, player_spot_y-1)){

                        if(spot - 1 == event_array[5]){
                                cout << "He's dead"<<endl;
                        }
                }

                if(in_board(player_spot_x, player_spot_y+1)){

                        if(spot + 1 == event_array[5]){
                                cout << "He's dead"<<endl;
                        }
                }






	}

*/





}


void Board::print_map(){
	for(int i = 0; i<size_of_table; i++){
		for(int j = 0; j < size_of_table; j++){
			cout<< " | ";
			if( i == player_spot_x && j == player_spot_y){
				cout<< "$";
			}
			else{
			cout<< " ";
			}
		}
		cout<< " | "<< endl;
	}

	//cout<< Bat->event_response()<<endl;
}


/**************************************
 * Function: start_event()
 * Description: sets the event on the board
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************/




void Board::start_event(){
	int place = rope_1;
	for (int i = 0; i<size_of_table;i++){
		for(int j = 0; j<size_of_table;j++){
		if(place ==1){
			rope_spot_x = i;
			player_spot_x = i;
			player_spot_y= j;
			rope_spot_y=j;
			
			
			}
		place--;
		}
	}

	place = pit_1;

	for(int i = 0; i < size_of_table; i++){
		for(int j = 0; j< size_of_table; j++){
			if(place ==1){
				tables[i][j]->set_pit_event();
				}
			place--;
		}		

	}



        place = pit_2;

        for(int i = 0; i < size_of_table; i++){
                for(int j = 0; j< size_of_table; j++){
                        if(place ==1){
                                tables[i][j]->set_pit_event();
                                }
                        place--;
                }

        }

        place = super_1;

        for(int i = 0; i < size_of_table; i++){
                for(int j = 0; j< size_of_table; j++){
                        if(place ==1){
                                tables[i][j]->set_bat_event();
                                }
                        place--;
                }

        }

        place = super_2;

        for(int i = 0; i < size_of_table; i++){
                for(int j = 0; j< size_of_table; j++){
                        if(place ==1){
                                tables[i][j]->set_bat_event();
                                }
                        place--;
                }

        }

        place = wumpus_1;

        for(int i = 0; i < size_of_table; i++){
                for(int j = 0; j< size_of_table; j++){
                        if(place ==1){
                                tables[i][j]->set_wumpus_event();
                                }
                        place--;
                }

        }

        place = gold_1;

        for(int i = 0; i < size_of_table; i++){
                for(int j = 0; j< size_of_table; j++){
                        if(place ==1){
                                tables[i][j]->set_gold_event();
                                }
                        place--;
                }

        }

}


/**************************************
 * Function: event_check()
 * Description: checks if the player is on the event
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************/




int Board::event_check(){
//	Room r;
	if(player_spot == event_array[1] || player_spot == event_array[2]){
//		r.print_event_response();
		cout<<"Bats have took you up to another room"<<endl;
		player_spot = rand() % (size_of_table * size_of_table) + 1;
		
		int new_spot = player_spot;
		for(int i = 0; i< size_of_table; i++){
			for(int j=0;j < size_of_table; j++){
			if (new_spot == 1){
				player_spot_x = i;
				player_spot_y = j;
				}
			new_spot--;
			}
		}
		event_check();
			
	}
	else if(player_spot == event_array[3] || player_spot == event_array[4]){
		cout<<"You died from the pit :("<<endl;
		return 0;
	}
	else if(player_spot == event_array[6]){
		if(take_gold == 1){
			return 1;
		}
		else{
		cout<<"dun dun dun dunnnnn you got gold!!!!"<<endl;
		take_gold = 1;
	}
	}
	else if(player_spot == event_array[5]){
		if(wumpus_die == 1){
			return 1;
			}
		else{
		cout<<"You see the wumpus. now you see death"<<endl;
		arrow = 3;
		wumpus_die=0;
		take_gold=0;
		return 0;
	}
	}
	return 1;	



}





Board::~Board(){
/*	for(int i = 0; i<size_of_table; i++){
		 row[i];
		}
	delete [] row;
*/
	//tables.clear();
	//clear();
}
