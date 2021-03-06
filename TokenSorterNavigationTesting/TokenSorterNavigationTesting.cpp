// TokenSorterNavigationTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Movement.h"
#include "Navigation.h"
#include <string>

Movement robotMovement = Movement();
Navigation navigation = Navigation();

using namespace moveOptions;

int main()
{
	//robotMovement.performTurn(Left180);
	//robotMovement.performApproach(FollowUntilCrossingY);
	//robotMovement.performBackwardApproach(BackwardFollowUntilCrossingY);

	navigation = Navigation(1, robotMovement);
	string user_input = "";
	
	cout << navigation.getCurrentStateInfo() << endl;

	while (true) {
		getline(cin, user_input);
		if (user_input == "l") {
			navigation.turnLeft();
			cout << navigation.getCurrentStateInfo() << endl;
		}
		else if (user_input == "r") {
			navigation.turnRight();
			cout << navigation.getCurrentStateInfo() << endl;
		}
		else if (user_input == "f") {
			navigation.goForward();
			cout << navigation.getCurrentStateInfo() << endl;
		}
		else if (user_input == "b") {
			navigation.goBackward();
			cout << navigation.getCurrentStateInfo() << endl;
		}
		else if (user_input == "exit") {
			break;
		}
	}
	//system("pause");
    return 0;
}

