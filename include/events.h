#ifndef EVENTS_H
#define EVENTS_H

#include "core.h"

#define MAXEVENTS 256

struct Event
{
	float x;
	float y;


}typedef Event;

extern Event eventQueue[MAXEVENTS];

void ProcessEventQueue();

void PostEvent(Event e);

#endif