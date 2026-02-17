#include "level.h"
#include "ui.h"

wchar_t* currentLevelName;

void GotoMainMenu()
{
	currentUIState = ui_mainMenu;
	currentLevelName = NULL;
};

bool SaveLevel(wchar_t* relativeFileName)
{

}


void LoadLevel(wchar_t* relativeFileName)
{


}
