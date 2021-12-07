// Work3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Traveller.h"
using namespace std;

int main()
{
    char option;
    cout << "We have 3 travellers. Traveller 1 cannot go out of town-1 neither can be revived (unique).Traveller 2(shared) can have two lives, before leaving town 2 you can decide to revive him or not.He can leave town 1 and town 2 but cannot leave town 3. Traveller 3(shared-to-weak) cannot go out of town 3, if he does, only his body remains without soul.\n";
    weak_ptr<Traveller> traveller3_weak; // Lost soul of traveller 3
    {//Town-3
        shared_ptr<Traveller> traveller2_shared;
        shared_ptr<Traveller> traveller3 = make_shared <Traveller>("Traveller-3");
        traveller3_weak = traveller3;
        {//Town-2
            shared_ptr<Traveller> traveller2 = make_shared <Traveller>("Traveller-2");
            traveller3_weak = traveller3; // Will only remain alive in town-2 even it is present in town-3
            {//Town-1
                unique_ptr<Traveller> traveller1= make_unique <Traveller>("Traveller-1");
                while (true)
                {
                    cout <<traveller1->getName()+ ", " + traveller2->getName() + " and " + traveller3->getName() + " are in town-1" << endl;
                    cout << "Do you want to leave Town-1: Y or N" << endl;
                    cin >> option;
                    if (option == 'Y')
                        break; // Unique pointer is automatically destroyed when it goes out of town 1
                }
                cout << "Leaving town 1" << endl;
            }
            while (true)
            {
                cout <<traveller2->getName() + " and " + traveller3->getName() + " are in town-2" << endl;
                cout << "Do you want to leave Town-2: Y or N" << endl;
                cin >> option;
                if (option == 'Y')
                    break; // Shared pointer is automatically destroyed when it goes out of town 2 but it depends on the input of user
                            // Whether he wants to keep it alive or not by sharing the memory with another shared pointer
            }
            cout << "Leaving town 2" << endl;
            cout << "Do you want to revive traveller-2: Y or N" << endl;
            cin >> option;
            if (option == 'Y')
                traveller2_shared = traveller2;
        }

        while (true)
        {

            if (traveller2_shared != nullptr)
                cout << traveller2_shared->getName() + " and " + traveller3->getName() + " are in town-3" << endl;
            else
                cout << traveller3->getName() + " is in town-3" << endl;
            cout << "Do you want to leave Town-3: Y or N" << endl;
            cin >> option;
            if (option == 'Y')
                break; // Shared pointer is automatically destroyed when it goes out of town 2 but it depends on the input of user
                        // Whether he wants to keep it alive or not by sharing the memory with another shared pointer
                        //Also the reference of weak pointer to the shared pointer will be destroyed
        }
    }
    // if weak ptr is expired or not!
    if (auto tmp = traveller3_weak.lock())
        std::cout << tmp->getName() << '\n'; // Pointer still exists
    else
        std::cout << "Only Lost body of traveller 3 exists without soul.!\n"; // Reference of weak ptr to shared ptr is destroyed
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
