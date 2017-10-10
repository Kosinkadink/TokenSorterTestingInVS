#include "stdafx.h"
#include "Navigation.h"


Navigation::Navigation(int round_n, Movement& move)
{
	movement = &move; //save pointer
	//IntersectionStart intersectionStart = IntersectionStart(movement, "Test Intersection");
	//currentState = &intersectionStart.getStateA()[Intersection::To];
	gameboard = &Gameboard(round_n, movement); //create gameboard
	currentState = gameboard->getStartState(); //set current state as start state
}


Navigation::~Navigation()
{
}

bool Navigation::turnLeft()
{
	return false;
}

bool Navigation::turnRight()
{
	return false;
}

bool Navigation::goForward()
{
	return false;
}

bool Navigation::goBackward()
{
	return false;
}

string Navigation::getCurrentStateInfo()
{
	return "Currently at " + currentState->getFullName();
}
