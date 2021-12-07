#include "rocketLauncher.h"

int main()
{
	RocketLauncher rl;
	cout << "\n\n\t* * * * * Welcome to Rocket Launcher! * * * * *\n" << endl;
	cout << "\nYou're a Space Ranger at Mission Control.\n" << endl;
	cout << "Getting the Main Thread ID: " << this_thread::get_id() << " at mission control";
	cout << "Press enter to start launching rockets on the \"remote rocket launch Pad\" from \"Mission Control\" locally from main thread!" << endl;
	cin.get();

	int MissionControlRemoteRocketLaunchedCount = 0;
	MissionControlRemoteRocketLaunchedCount++;
	cout << "You Space Ranger have the lunch branch for the rockets from the main thread" << endl;
	cout << "\n\nMain thread is Launching Local Rocket # " << MissionControlRemoteRocketLaunchedCount << " at the \"Remote Rocket Launch Pad\" "<< endl;
	cout << "\nMain thread is launching Rocket # " << ++totalRocketsLaunchedFromAnywhereCount << " from Main thread.\n" << endl;

	cout << "Press enter to start launching rockets from spawn thread!" << endl;
	cin.get();
	thread myWorker(&RocketLauncher::LaunchRockets, RocketLauncher());
	cout << "Getting the Main Thread ID: " << this_thread::get_id() << endl;

	cout << "\nPress enter at Mission Control to stop rocket at";
	cout << " the \"Remote Rocket Launch Pad\" and reclaim rocket launch control to \"Mission Control\" using main thread !" << endl;
	cin.get();
	cout << "\nSpace Ranger at Mission Control has Pressed enter! Mission Control takes control back with Main Thread to reclaim";
	cout << "\nAbout to flip abort launches from the remote rocket launchpad by space cadet launch switch to true!" << endl;
	abortLaunch = true;
	rl.setAbort();
	cout << "Abort launch by space cadet at the remote rocket launch pad switch flipped to true!" << endl;

	//Blocks thread until we set abortLaunch to true
	cout << "\nPress enter at Mission Control to stop rocket launches at";
	cout << " the \"Remote Rocket Launch Pad\" and reclaim rocket launch control to \"Mission Control\" using main thread only!";
	cout << "Checking Main Thread ID: " << this_thread::get_id() << endl;

	cout << "\nAbout to Join thread, AKA start the waiting from spawn thread to stop." << endl;
	cout << "\n\nGetting Main Thread ID: " << this_thread::get_id() << endl;
	//WORKER JOIN
	if(myWorker.joinable()){
	   myWorker.join();
	}
	cout << "\nThread has been joined!" << endl;
	cout << "\nGetting Main Thread ID: " << this_thread::get_id() << endl;

	std::cout << "\nPress Enter to Exit Program" << endl;
	cin.get();
	return 0;
}
