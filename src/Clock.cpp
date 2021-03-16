#include "Clock.hpp"

#include <chrono>

Clock::Clock() : startTime(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) {}
void Clock::reset() {
	auto now = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	startTime = duration.count();
}
unsigned long long int Clock::getElapsedTime() {
	unsigned long long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	return now - startTime;
}
