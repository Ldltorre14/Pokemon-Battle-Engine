#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <map>
#include "../UI Components/Button.h"

class UIManager
{
	private:
		std::map <std::string, std::map<std::string, UI::Button*>> Buttons;
		
		//<<<<<<<<<<<INITIALIZERS>>>>>>>>>>>
		void initButtons();
	public:
		UIManager();
		~UIManager();

		void setButton(std::string category, std::string buttonKey);
		UI::Button* getButton();
};

#endif

