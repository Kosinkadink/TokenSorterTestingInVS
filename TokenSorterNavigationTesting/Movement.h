#pragma once
#include <stdio.h>
#include <iostream>

namespace moveOptions {
	enum Turn { Left45=1, Right45, Left90, Right90, Left135, Right135, Left180, Right180 };
	enum Approach {
		NoFollowUntilPerpendicularLine=1, FollowUntilPerpendicularLine, FollowUntilTokenSlot,
		FollowOnLeftUntilPerpendicularLine, FollowOnRightUntilPerpendicularLine,
		FollowOnLeftUntilCrossesLine, FollowOnRightUntilCrossesLine,
		FollowUntilCrossingY, FollowUntilSeparatingY,
		MoveIntoStart, MoveIntoDropPosition
	};
	enum BackwardApproach {
		BackwardLeaveDropPosition=1,
		BackwardFollowUntilCrossingY, BackwardFollowUntilSeparatingY
	};
}

using namespace moveOptions;
using namespace std;

class Movement
{
public:
	Movement();
	~Movement();
	void performTurn(Turn turnType);
	void performApproach(Approach approachType);
	void performBackwardApproach(BackwardApproach approachType);
	// Turn methods
	void turnLeft45() { cout << "Turning 45 deg to the left" << endl; };
	void turnRight45() { cout << "Turning 45 deg to the right" << endl; };
	void turnLeft90() { cout << "Turning 90 deg to the left" << endl; };
	void turnRight90() { cout << "Turning 90 deg to the right" << endl; };
	void turnLeft135() { cout << "Turning 135 deg to the left" << endl; };
	void turnRight135() { cout << "Turning 135 deg to the right" << endl; };
	void turnLeft180() { cout << "Turning 180 deg to the left" << endl; };
	void turnRight180() { cout << "Turning 180 deg to the right" << endl; };
	// Approach functions
	void approachNoFollowUntilPerpendicularLine() { cout << "Not following line until perpendicular line is hit" << endl; };
	void approachFollowUntilPerpendicularLine() { cout << "Following line until perpendicular line is hit" << endl; };
	void approachFollowUntilTokenSlot() { cout << "Following line until token slot is hit" << endl; };
	void approachFollowOnLeftUntilPerpendicularLine() { cout << "Following line on its left until perpendicular line is hit on the left" << endl; };
	void approachFollowOnRightUntilPerpendicularLine() { cout << "Following line on its right until perpendicular line is hit on the right" << endl; };
	void approachFollowOnLeftUntilCrossesLine() { cout << "Following line on its left until some line is hit on the left" << endl; };
	void approachFollowOnRightUntilCrossesLine() { cout << "Following line on its right until some line is hit on the left" << endl; };
	void approachFollowUntilCrossingY() { cout << "Following line until two lines of Y start to cross" << endl; };
	void approachFollowUntilSeparatingY() { cout << "Following line until two liens of Y start to separate" << endl; };
	void approachMoveIntoStart() { cout << "Go forward some amount to be in center of start square" << endl; };
	void approachMoveIntoDropPosition() { cout << "Go forward some amount to be in center of start square" << endl; };
	// Backward Approach functions
	void approachBackwardLeaveDropPosition() { cout << "Go backward some amount to leave drop position" << endl; };
	void approachBackwardFollowUntilCrossingY() { cout << "Go backward until two lines of Y start to cross" << endl; };
	void approachBackwardFollowUntilSeparatingY() { cout << "Go backward until two lines of Y start to separate" << endl; };
};

