#pragma once
#include <string>
#include "Movement.h"
#include "IntersectionState.h"

class IntersectionState;

class Intersection
{
protected:
	IntersectionState* stateA[2];
	IntersectionState* stateB[2];
	IntersectionState* stateC[2];
	IntersectionState* stateD[2];
	string intersectName;
	bool hasToken;
	Movement* movement;
public:
	Intersection(Movement* move, string name);
	~Intersection();

	enum Direction { To = 0, From = 1 };
	void createConnection(IntersectionState* localStateArr, IntersectionState* externalStateArr);
	void createBackwardConnection(IntersectionState* localStateArr, IntersectionState* dropStateArr);
	// shortcut functions to connect using certain states
	void createConnectionUsingStateA(IntersectionState* externalStateArr) { createConnection(*stateA, externalStateArr); };
	void createConnectionUsingStateB(IntersectionState* externalStateArr) { createConnection(*stateB, externalStateArr); };
	void createConnectionUsingStateC(IntersectionState* externalStateArr) { createConnection(*stateC, externalStateArr); };
	void createConnectionUsingStateD(IntersectionState* externalStateArr) { createConnection(*stateD, externalStateArr); };
	void createBackwardConnectionUsingStateA(IntersectionState* dropStateArr) { createBackwardConnection(*stateA, dropStateArr); };
	void createBackwardConnectionUsingStateB(IntersectionState* dropStateArr) { createBackwardConnection(*stateB, dropStateArr); };
	void createBackwardConnectionUsingStateC(IntersectionState* dropStateArr) { createBackwardConnection(*stateC, dropStateArr); };
	void createBackwardConnectionUsingStateD(IntersectionState* dropStateArr) { createBackwardConnection(*stateD, dropStateArr); };
	// getters
	string getName() { return intersectName; };
	IntersectionState* getStateA() { return *stateA; };
	IntersectionState* getStateB() { return *stateB; };
	IntersectionState* getStateC() { return *stateC; };
	IntersectionState* getStateD() { return *stateD; };
};

// Type Start intersection
class IntersectionStart : public Intersection {
public:
	IntersectionStart(Movement* move, string name);
};

// Type I intersection
class IntersectionI : public Intersection {
public:
	IntersectionI(Movement* move, string name);
};

// Type II intersection
class IntersectionII : public Intersection {
public:
	IntersectionII(Movement* move, string name);
};

// Type III intersection
class IntersectionIII : public Intersection {
public:
	IntersectionIII(Movement* move, string name);
};

// Type IV intersection
class IntersectionIV : public Intersection {
public:
	IntersectionIV(Movement* move, string name);
};

// Type V intersection
class IntersectionV : public Intersection {
public:
	IntersectionV(Movement* move, string name);
};

// Type DropToken intersection
class IntersectionDropToken : public Intersection {
public:
	IntersectionDropToken(Movement* move, string name);
};

