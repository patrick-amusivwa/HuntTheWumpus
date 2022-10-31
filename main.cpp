/**********************************
 * Program: main.cpp
 * 
 * Description: runs the game and loops it
 * Input: None
 * Output: None
 ****************************************/





#include<iostream>
#include<ctime>
#include<cstring>
#include"board.hpp"
#include<vector>


using namespace std;


int main(int argc, char** argv){
	
	
	int size= atoi(argv[1]);
	
	while(size < 4){
		if(size < 4){
		cout<<"That's too small please reinput size larger than 4"<<endl;
		cin>>size;
		}
		else{
			break;
	}
	}
//	cout<< "enter size of cave:";
//	cin >> size;

	
	bool over = false;
	int option, again=1, same;
	Board Play(size);
	
	Play.rand_events();
	Play.start_event();
	
	Play.print_map();
	Play.event_check();
	do{
		while(!over){
		cout<<"What to do in this cave?: "<<endl;
		cout<<"1. Move around or 2. Shoot an arrow or 0. to quit game: ";
		cin >>option;

		if(option ==1){
			if(Play.set_direction() == 1){
				
				break;
			}
		}
		else if(option == 2){
			if(Play.arrow_move() == 1){
				break;
			}	
		}
		else if(option == 0){
			over = true;
			again = 0;
			break;
		}
		Play.print_map();
	}
	if(option == 0){
		again = 0;
	}
	else{	
	cout << "Again? (1) or Stop (0): ";
	cin >>again;

	if(again == 1){
		cout<<"Same board? (1) or differnt(0): ";
		cin>> same;
		if(same == 1){
			Play.start_event();
			Play.print_map();
			
		}
		else if(same == 0){
			Play.rand_events();
			Play.start_event();
			Play.print_map();
		}
	}
}
	}while (again == 1);
	
	return 0;
}







/*
	std::vector<std::vector<int> > vec2d(7, std::vector<int>(4,1));
        for (int i = 0; i <10; i++){
		for(int j = 0; j<10; j++){
	vec2d[i][j] = 4;
		}


	}*/
       



