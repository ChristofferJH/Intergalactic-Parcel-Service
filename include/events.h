#ifndef EVENTS_H
#define EVENTS_H

#define MAXEVENTS 256

enum Event
{
	event_none,
	event_a
}typedef Event;

extern Event eventQueue[MAXEVENTS];

void ProcessEventQueue();
void PostEvent(Event event)

#endif