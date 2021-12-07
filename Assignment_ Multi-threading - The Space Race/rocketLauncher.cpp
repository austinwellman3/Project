
#include "rocketLauncher.h"

void RocketLauncher::setAbort(){
	abortLaunch = true;
}
//Void Launch Rockets Function which keeps the function going.
void RocketLauncher::LaunchRockets()
{
	using namespace std::literals::chrono_literals;

	std::cout << "\nThread ID " << this_thread::get_id() << " has been spawned to launch rockets!" << endl;

	// Local Rocket launched count
	int localRocketPadLaunchCount = 0;

	// Loop until we flip the abortLaunch to true
	while(!abortLaunch)
	{
		localRocketPadLaunchCount++;
		cout << "\n\n*** Spawn thread is Launching Local Rocket #" << localRocketPadLaunchCount << " from the rocket spawned pad" << endl;
		cout << "\nGetting the current spawned Thread ID:" << this_thread::get_id() << endl;
		cout << "\nSpawn thread is Launching Local Rocket #" << ++totalRocketsLaunchedFromAnywhereCount << " from the rocket spawned pad" << endl;
		cout << "\n\tPress Enter to stop launching rockets from this spawn thread at the local rocket pad....\n";
		this_thread::sleep_for(3s);
	}
}

