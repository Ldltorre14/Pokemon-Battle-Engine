#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>
#include <iostream>

//Declaration in advance of State for avoiding circular include errors when including StateManager at State
class State;


class StateManager
{
private:
	std::stack<State*> states;
	

public:
	StateManager(State* state = nullptr);
	~StateManager();

	bool noTasks();
	
	void pushState(State* state);
	void deleteState();
	void updateState(const float& dt);
	void renderState();
	
};


#endif

