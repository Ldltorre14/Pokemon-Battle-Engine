#include "StateManager.h"

StateManager::StateManager(State* state)
{
	
	this->states.push(state);

}

StateManager::~StateManager()
{
	while (!this->states.empty()) {
		this->deleteState();
	}
}

bool StateManager::noTasks()
{
	if (this->states.empty())
		return true;
}



void StateManager::deleteState()
{
	delete this->states.top();
	this->states.pop();
}

void StateManager::updateState(const float& dt)
{
	if (!this->states.empty()) {
		this->states.top()->update(dt);
		if (this->states.top()->getQuit()) {
			this->deleteState();
		}
	}
	
}

void StateManager::renderState()
{
	this->states.top()->render();
}
