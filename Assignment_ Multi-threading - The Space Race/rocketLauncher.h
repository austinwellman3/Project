#include <iostream>
#include <thread>
using namespace std;
static bool abortLaunch = false;
static int totalRocketsLaunchedFromAnywhereCount = 0;
class RocketLauncher{
public:
   void LaunchRockets();
   void setAbort();
};

