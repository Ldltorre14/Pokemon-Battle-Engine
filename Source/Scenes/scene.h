#ifndef SCENE_H
#define SCENE_H

#include "../UI Components/RectButton.h"

class Scene {
private:
	UI::Button* button;

protected:

public:
	Scene();
	~Scene();
	void render(sf::RenderTarget* target);
};

#endif 

