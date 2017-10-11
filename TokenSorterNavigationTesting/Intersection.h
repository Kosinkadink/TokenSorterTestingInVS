#pragma once
#include <string>
#include "Movement.h"
#include "IntersectionState.h"

class IntersectionState;


struct IntersectionStatePair {
	IntersectionState* To;
	IntersectionState* From;
};

class Intersection
{
protected:
	IntersectionStatePair* stateA;
	IntersectionStatePair* stateB;
	IntersectionStatePair* stateC;
	IntersectionStatePair* stateD;
	string intersectName;
	bool hasToken;
	Movement* movement;
public:
	Intersection(Movement* move, string name);
	~Intersection();

	enum Direction { To = 0, From = 1 };
	void createConnection(IntersectionStatePair* localStateArr, IntersectionStatePair* externalStateArr);
	void createBackwardConnection(IntersectionStatePair* localStateArr, IntersectionStatePair* dropStateArr);
	// shortcut functions to connect using certain states
	void createConnectionUsingStateA(IntersectionStatePair* externalStateArr) { createConnection(stateA, externalStateArr); };
	void createConnectionUsingStateB(IntersectionStatePair* externalStateArr) { createConnection(stateB, externalStateArr); };
	void createConnectionUsingStateC(IntersectionStatePair* externalStateArr) { createConnection(stateC, externalStateArr); };
	void createConnectionUsingStateD(IntersectionStatePair* externalStateArr) { createConnection(stateD, externalStateArr); };
	void createBackwardConnectionUsingStateA(IntersectionStatePair* dropStateArr) { createBackwardConnection(stateA, dropStateArr); };
	void createBackwardConnectionUsingStateB(IntersectionStatePair* dropStateArr) { createBackwardConnection(stateB, dropStateArr); };
	void createBackwardConnectionUsingStateC(IntersectionStatePair* dropStateArr) { createBackwardConnection(stateC, dropStateArr); };
	void createBackwardConnectionUsingStateD(IntersectionStatePair* dropStateArr) { createBackwardConnection(stateD, dropStateArr); };
	// getters
	string getName() { return intersectName; };
	IntersectionStatePair* getStateA() { return stateA; };
	IntersectionStatePair* getStateB() { return stateB; };
	IntersectionStatePair* getStateC() { return stateC; };
	IntersectionStatePair* getStateD() { return stateD; };
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

