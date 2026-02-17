#ifndef UI_H
#define UI_H


enum UIState {
	ui_mainMenu,
	ui_gameplaydefault
}typedef UIState;

extern UIState currentUIState;

#endif