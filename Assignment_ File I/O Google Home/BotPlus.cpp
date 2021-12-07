#include "BotPlus.h"

void BotPlus::CreateFile()
{
    string line;
    ifile.open("BotMemory.txt");
    if (ifile.is_open())
    {
        cout << "Memory already exists" << endl;
        while (getline(ifile, line))
        {
            row_number++;
        }
    }
    else
    {
        ofstream ofile("BotMemory.txt");
        cout << "New Memory created" << endl;
        ofile.close();
    }
    ifile.close();
}

void BotPlus::DisplayAllContent()
{
    string line;
    ifile.open("BotMemory.txt");
    if (ifile.is_open())
    {
        cout << "Displaying All Items Location!" << endl;;
        while (getline(ifile, line))
        {
            cout << line << endl;
        }
        ifile.close();
    }
    else
    {
        cout << "Memory doesn't exist" << endl;
    }
}

void BotPlus::SearchFile(string item_name)
{
    string line;
    string details [3];
    int check = 0;
    int index;
    ifile.open("BotMemory.txt");
    if (ifile.is_open())
    {
        while (getline(ifile, line))
        {
            index = 0;
            for (int i = 0; i < line.length(); i++)
                if (line[i] == ' ')
                {
                    index++;
                    continue;
                }
                else
                    details[index]+=line[i];
            if (details[1].compare(item_name) == 0)
            {
                check = 1;
                cout << "Item found at: " << details[2] << endl;
            }

            for (int i = 0; i < 3; i++) //Looping through the details array
                details[i].clear(); //Clearing each element              
        }
        if (check == 0)
            cout << "Item doesn't exist in my memory" << endl;
        ifile.close();
    }
    else
    {
        cout << "Memory doesn't exist" << endl;
    }
}

void BotPlus::WriteFile(string item_name, string location)
{
    ofstream ofile("BotMemory.txt", ios::app);
    ofile <<'\n' << row_number + 1 << " " << item_name << " " << location;
    cout << "New record entered successfully!" << endl;
    ofile.close();
}
