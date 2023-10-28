#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"

class StateManager
{
private:
	std::stack<State*> states;

public:
	StateManager(State* state);
	~StateManager();

	bool noTasks();

	void deleteState();
	void updateState(const float& dt);
	void renderState();
	
};


#endif

