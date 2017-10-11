#include "stdafx.h"
#include "Intersection.h"

using namespace moveOptions;

Intersection::Intersection(Movement* move, string name)
{
	// initialize state pairs
	stateA = new IntersectionStatePair;
	stateB = new IntersectionStatePair;
	stateC = new IntersectionStatePair;
	stateD = new IntersectionStatePair;
	// assign states to state pairs
	stateA->To = new IntersectionState(move, this, "A[To]");
	stateA->From = new IntersectionState(move, this, "A[From]");
	stateB->To = new IntersectionState(move, this, "B[To]");
	stateB->From = new IntersectionState(move, this, "B[From]");
	stateC->To = new IntersectionState(move, this, "C[To]");
	stateC->From = new IntersectionState(move, this, "C[From]");
	stateD->To = new IntersectionState(move, this, "D[To]");
	stateD->From = new IntersectionState(move, this, "D[From]");
	movement = move;
	intersectName = name;
}

/*IntersectionStatePair* Intersection::getStateA() {
	IntersectionStatePair* pair = new IntersectionStatePair;
	pair->To = stateA[To];
	pair->From = stateA[From];
	return pair;
}

IntersectionStatePair* Intersection::getStateB() {
	IntersectionStatePair* pair = new IntersectionStatePair;
	pair->To = stateB[To];
	pair->From = stateB[From];
	return pair;
}

IntersectionStatePair* Intersection::getStateC() {
	IntersectionStatePair* pair = new IntersectionStatePair;
	pair->To = stateC[To];
	pair->From = stateC[From];
	return pair;
}

IntersectionStatePair* Intersection::getStateD() {
	IntersectionStatePair* pair = new IntersectionStatePair;
	pair->To = stateC[To];
	pair->From = stateC[From];
	return pair;
}*/

void Intersection::createConnection(IntersectionStatePair* localStateArr, IntersectionStatePair* externalStateArr) {
	// create a bidirectional connection between To and From versions of given ItersectionStates
	localStateArr->To -> connectTo(*externalStateArr->From);
	externalStateArr->To -> connectTo(*localStateArr->From);
}

void Intersection::createBackwardConnection(IntersectionStatePair* localStateArr, IntersectionStatePair* dropStateArr) {
	// create a regular forward connection, but special backward connection
	localStateArr->To -> connectTo(*dropStateArr->From);
	dropStateArr->To -> connectBackwardTo(*localStateArr->From);
}


Intersection::~Intersection()
{
}


IntersectionStart::IntersectionStart(Movement* move, string name) : Intersection(move, name) {
	/*
	+---------------------------------+
	|                                 |
	|                A                |
	|                                 |
	|                ^                |
	|               /|\               |
	|                |                |
	|              Start              |
	|                |                |
	|                |                |
	|                |                |
	|                                 |
	|                B                |
	|                                 |
	+---------------------------------+
	*/
	// This intersection CANNOT be approached from B 
	// setup states To/From A
	stateA->To -> setLeftTurn(Left180, stateB->To);
	stateA->To -> setRightTurn(Right180, stateB->To);
	stateA->From -> setApproach(MoveIntoStart);
	// setup states To/From B
	stateB->To -> setLeftTurn(Left180, stateA->To);
	stateB->To -> setRightTurn(Right180, stateA->To);
	// set appropriate transitions
	stateA->From -> setTransitionTo(stateB->To);
}


IntersectionI::IntersectionI(Movement* move, string name) : Intersection(move, name) {
	/*

	A
	|
	|
	|
	t
	/ | \
	/   |   \
	/     |     \
	B /        C       \ D
	*/
	// setup states To/From A
	stateA->To -> setLeftTurn(Left135, stateB->To);
	stateA->To -> setRightTurn(Right135, stateD->To);
	stateA->From -> setApproach(FollowUntilTokenSlot);
	stateA->From -> setBackwardApproach(BackwardFollowUntilSeparatingY);
	// setup states To/From B
	stateB->To -> setLeftTurn(Left45, stateC->To);
	stateB->To -> setRightTurn(Right135, stateA->To);
	stateB->From -> setLeftTurn(Left45, stateA->To);
	stateB->From -> setRightTurn(Right90, stateD->To);
	stateB->From -> setApproach(FollowUntilTokenSlot);
	// setup states To/From C
	stateC->To -> setLeftTurn(Left45, stateD->To);
	stateC->To -> setRightTurn(Right45, stateB->To);
	stateC->From -> setApproach(FollowUntilTokenSlot);
	stateC->From -> setBackwardApproach(BackwardFollowUntilCrossingY);
	// setup states To/From D
	stateD->To -> setLeftTurn(Left135, stateA->To);
	stateD->To -> setRightTurn(Right45, stateC->To);
	stateD->From -> setLeftTurn(Left90, stateB->To);
	stateD->From -> setRightTurn(Right45, stateA->To);
	stateD->From -> setApproach(FollowUntilTokenSlot);
	// set appropriate transitions
	stateA->From -> setTransitionTo(stateC->To);
	stateA->From -> setBackwardTransitionTo(stateA->To);
	stateC->From -> setTransitionTo(stateA->To);
	stateC->From -> setBackwardTransitionTo(stateC->To);
}


IntersectionII::IntersectionII(Movement* move, string name) : Intersection(move, name) {
	/*

	A
	|
	|
	|
	B --------t-------- D
	|
	|
	|
	C
	*/
	// setup state To A
	stateA->To -> setLeftTurn(Left90, stateB->To);
	stateA->To -> setRightTurn(Right90, stateD->To);
	stateA->From -> setApproach(FollowUntilTokenSlot);
	// setup state To B
	stateB->To -> setLeftTurn(Left90, stateC->To);
	stateB->To -> setRightTurn(Right90, stateA->To);
	stateB->From -> setApproach(FollowUntilTokenSlot);
	// setup state To C
	stateC->To -> setLeftTurn(Left90, stateD->To);
	stateC->To -> setRightTurn(Right90, stateB->To);
	stateC->From -> setApproach(FollowUntilTokenSlot);
	// setup state To D
	stateD->To -> setLeftTurn(Left90, stateA->To);
	stateD->To -> setRightTurn(Right90, stateC->To);
	stateD->From -> setApproach(FollowUntilTokenSlot);
	// set appropriate transitions
	stateA->From -> setTransitionTo(stateC->To);
	stateA->From -> setBackwardTransitionTo(stateA->To);
	stateC->From -> setTransitionTo(stateA->To);
	stateC->From -> setBackwardTransitionTo(stateC->To);
	stateB->From -> setTransitionTo(stateD->To);
	stateD->From -> setTransitionTo(stateB->To);
}


IntersectionIII::IntersectionIII(Movement* move, string name) : Intersection(move, name) {
	/*

	A
	|
	|
	|
	|
	/   \
	/       \
	/           \
	B /       C       \ D
	*/
	// This intersection CANNOT be approached from C
	// setup states To/From A
	stateA->To -> setLeftTurn(Left135, stateB->To);
	stateA->To -> setRightTurn(Right135, stateD->To);
	stateA->From -> setApproach(FollowUntilSeparatingY);
	//stateC->To -> setBackwardApproach(BackwardLeaveDropPosition);
	// setup states To/From B
	stateB->To -> setLeftTurn(Left45, stateC->To);
	stateB->To -> setRightTurn(Right135, stateA->To);
	stateB->From -> setLeftTurn(Left45, stateA->To);
	stateB->From -> setRightTurn(Right90, stateD->To);
	stateB->From -> setApproach(FollowOnLeftUntilCrossesLine);
	// setup states To/From C
	stateC->To -> setLeftTurn(Left45, stateD->To);
	stateC->To -> setRightTurn(Right45, stateB->To);
	stateC->To -> setBackwardState(stateA->To);
	stateC->From -> setBackwardApproach(BackwardLeaveDropPosition);
	// setup states To/From D
	stateD->To -> setLeftTurn(Left135, stateA->To);
	stateD->To -> setRightTurn(Right45, stateC->To);
	stateD->From -> setLeftTurn(Left90, stateB->To);
	stateD->From -> setRightTurn(Right45, stateA->To);
	stateD->From -> setApproach(FollowOnRightUntilCrossesLine);
	// set appropriate transitions
	stateA->From -> setTransitionTo(stateC->To);
	stateC->From -> setBackwardTransitionTo(stateC->To);
}


IntersectionIV::IntersectionIV(Movement* move, string name) : Intersection(move, name) {
	/*

	A
	|
	|
	|
	B ----------------- D



	C
	*/
	// This intersection CANNOT be approached from C
	// setup state To A
	stateA->To -> setLeftTurn(Left90, stateB->To);
	stateA->To -> setRightTurn(Right90, stateD->To);
	stateA->From -> setApproach(FollowUntilPerpendicularLine);
	// setup state To B
	stateB->To -> setLeftTurn(Left90, stateC->To);
	stateB->To -> setRightTurn(Right90, stateA->To);
	stateB->From -> setApproach(FollowOnLeftUntilPerpendicularLine);
	// setup state To C
	stateC->To -> setLeftTurn(Left90, stateD->To);
	stateC->To -> setRightTurn(Right90, stateB->To);
	stateC->To -> setBackwardState(stateA->To);
	stateC->From -> setBackwardApproach(BackwardLeaveDropPosition);
	// setup state To D
	stateD->To -> setLeftTurn(Left90, stateA->To);
	stateD->To -> setRightTurn(Right90, stateC->To);
	stateD->From -> setApproach(FollowOnRightUntilPerpendicularLine);
	// set appropriate transitions
	stateA->From -> setTransitionTo(stateC->To);
	stateC->From -> setTransitionTo(stateA->To);
	stateC->From -> setBackwardTransitionTo(stateC->To);
	stateB->From -> setTransitionTo(stateD->To);
	stateD->From -> setTransitionTo(stateB->To);
}


IntersectionV::IntersectionV(Movement* move, string name) : Intersection(move, name) {
	/*

	A



	B ----------------- D



	C
	*/
	// setup state To A
	stateA->To -> setLeftTurn(Left90, stateB->To);
	stateA->To -> setRightTurn(Right90, stateD->To);
	stateA->From -> setApproach(NoFollowUntilPerpendicularLine);
	// setup state To B
	stateB->To -> setLeftTurn(Left90, stateC->To);
	stateB->To -> setRightTurn(Right90, stateA->To);
	stateB->From -> setApproach(FollowUntilPerpendicularLine);
	// setup state To C
	stateC->To -> setLeftTurn(Left90, stateD->To);
	stateC->To -> setRightTurn(Right90, stateB->To);
	stateC->From -> setApproach(NoFollowUntilPerpendicularLine);
	// setup state To D
	stateD->To -> setLeftTurn(Left90, stateA->To);
	stateD->To -> setRightTurn(Right90, stateC->To);
	stateD->From -> setApproach(FollowUntilPerpendicularLine);
	// set appropriate transitions
	stateA->From -> setTransitionTo(stateC->To);
	stateC->From -> setTransitionTo(stateA->To);
	stateB->From -> setTransitionTo(stateD->To);
	stateD->From -> setTransitionTo(stateB->To);
}


IntersectionDropToken::IntersectionDropToken(Movement* move, string name) : Intersection(move, name) {
	/*
	A



	nothing    drop     nothing



	B

	*/
	// There are only 2 states A and B that matter here
	// No turns allowed, can only go back to previous tate
	// Transitions from A From to A To
	stateA->From -> setApproach(MoveIntoDropPosition);
	stateA->From -> setTransitionTo(stateB->To);
	
	stateB->To->setBackwardState(stateA->To);
}

