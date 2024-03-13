#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>

//Declaration in advance of State for avoiding circular include errors when including StateManager at State
class State;


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

