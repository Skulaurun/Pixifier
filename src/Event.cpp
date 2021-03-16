#include "Event.hpp"

Event::Event() : type(Event::Null), mouse({ Mouse::Null, 0 }) {}
Event Event::pop() {
	Event temp = *this;
	type = Event::Null;
	return temp;
}
Event::operator bool() {
	return type != Event::Null;
}
