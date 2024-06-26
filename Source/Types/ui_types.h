#ifndef UI_TYPES_H
#define UI_TYPES_H

namespace UI {
	enum class buttonState : int {
		IDLE_BTN = 0,
		HOVER_BTN = 1,
		ACTIVE_BTN = 2
	};
	enum class textAlignment : int {
		TOP_LEFT = 0,
		TOP_CENTER = 1,
		TOP_RIGHT = 2,
		LEFT = 3,
		CENTER = 4,
		RIGHT = 5,
		BOTTOM_LEFT = 6,
		BOTTOM_CENTER = 7,
		BOTTOM_RIGHT = 8
	};
}

#endif