#pragma once
#include "Intersection.h"
#include "Movement.h"

using namespace moveOptions;


class Intersection;


class IntersectionState
{
private:
	Movement* movement;
	string stateName;
	Turn leftTurnEnum;
	Turn rightTurnEnum;
	Approach approachEnum;
	BackwardApproach backwardApproachEnum;
	IntersectionState* leftState = nullptr;
	IntersectionState* rightState = nullptr;
	IntersectionState* transitionState = nullptr;
	IntersectionState* backwardTransitionState = nullptr;
	Intersection* container = nullptr;
protected:
	
public:
	IntersectionState(Movement* move, Intersection* intersection, string name);
	// setters
	void setLeftTurn(Turn enumVal, IntersectionState* state) { leftTurnEnum = enumVal; leftState = state; };
	void setRightTurn(Turn enumVal, IntersectionState* state) { rightTurnEnum = enumVal; rightState = state; };
	void setTransitionTo(IntersectionState* state) { transitionState = state; };
	void setBackwardTransitionTo(IntersectionState* state) { backwardTransitionState = state; };
	void setApproach(Approach enumVal) { approachEnum = enumVal; };
	void setBackwardApproach(BackwardApproach enumVal) { backwardApproachEnum = enumVal; };
	void setContainer(Intersection* intersection) { container = intersection; };
	// getters
	string getName() { return stateName; };
	string getFullName();
	IntersectionState* getSelf() { return this; };
	// other functions
	IntersectionState* connectedState = nullptr;
	IntersectionState* backwardConnectedState = nullptr;
	void connectTo(IntersectionState& state); // creates one-way link
	void connectBackwardTo(IntersectionState& state); // create one-way link
	IntersectionState* turnLeft();
	IntersectionState* turnRight();
	IntersectionState* goForward();
	IntersectionState* goBackward();
	// perform approaches
	IntersectionState* performApproach();
	IntersectionState* performBackwardApproach();

	~IntersectionState();
};

