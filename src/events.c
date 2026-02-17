#include "events.h"


size_t eventCount=0;
Event eventQueue[MAXEVENTS];

void ProcessEventQueue()
{
	for (size_t i = 0; i < eventQueue; i++)
	{

		switch (eventQueue[i])
		{
			

		}
	}

	eventCount = 0;
}

void PostEvent(Event event)
{
	eventQueue[eventCount] = event;
	eventCount++;
}