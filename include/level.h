#ifndef LEVEL_H
#define LEVEL_H
#include "core.h"
#include "filehandling.h"
#include "ui.h"


void GotoMainMenu();
bool SaveLevel(wchar_t* relativeFileName);
void LoadLevel(wchar_t* relativeFileName);

#endif