#include"room.hpp"

Room::Room(){
		array_spot = 0;
		event = 0;
}

void Room::set_array_spot(int array_spot){
	this -> array_spot = array_spot;
}

int Room::get_array_spot(){
	return array_spot;
}



/**************************************
 * Function: set_wumpus_event()
 * Description: sets the wumpus and creates a new Wumpus object. 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ****************************/

void Room::set_wumpus_event(){
	if(event != 0){
		delete event;
	}
	event = new Wumpus;
}

void Room::set_gold_event(){
        if(event != 0){
                delete event;
        }
        event = new Gold;
}

void Room::set_pit_event(){
        if(event != 0){
                delete event;
        }
        event = new Pit;
}

void Room::set_bat_event(){
        if(event != 0){
                delete event;
        }
        event = new Bat;
}


/**************************************
 * Function: print_event_response()
 * Description: uses the event class's polymorphic virtual funciton and prints out the event text set in the type of classes.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/

void Room::print_event_response(){

	cout<< event->event_text()<<endl;

}

void Room::print_event_text(){

	cout<< event->event_response()<<endl;
}


Room::~Room(){
	delete event;
}
