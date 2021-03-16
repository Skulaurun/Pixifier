#pragma once

class Clock {

private:
	unsigned long long int startTime;

public:
	Clock();

	void reset();
	unsigned long long int getElapsedTime();

};
