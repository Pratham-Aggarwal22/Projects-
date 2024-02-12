#include<sstream>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Option{
    public:
    int Pexit, Fexit;
    string choice, stat, pass, fail, damage;
};

class Room{
    public:
    int room_num;
    string description;
    vector <Option> options;
};

class World{
    public:
    bool loadedProperly = false;
    vector <Room> rooms;
     
    World(){
        ifstream inFS;
        string line, temp;

        inFS.open("rooms.txt");
        if(!inFS.is_open())
        {
            loadedProperly = false;
        }
        loadedProperly = true;
        while(!inFS.eof())
        {
            getline(inFS,line);
            istringstream inSS(line);
            inSS>>temp;
            if(temp == "Room:")
            {
                Room room;
                inSS>>room.room_num;
                room.room_num = room.room_num-1;
                rooms.push_back(room);

            }
            else if(temp == "Desc:")
            {
                rooms.at(rooms.size()-1).description = line.erase(0,6);
            }
            else if (temp == "Option:")
            {
                Option option;
                inSS>>option.choice;
                rooms.at(rooms.size()-1).options.push_back(option);
            }
            else if (temp == "Stat:")
            {
                int currRoom = rooms.size()-1;
                int currOption = rooms.at(currRoom).options.size()-1;
                inSS >> rooms.at(currRoom).options.at(currOption).stat;
            }
            else if (temp == "Pass:")
            {
                int currRoom = rooms.size()-1;
                int currOption = rooms.at(currRoom).options.size()-1;
                inSS >> rooms.at(currRoom).options.at(currOption).pass; 
            }
            else if (temp == "Pexit:")
            {
                int currRoom = rooms.size()-1;
                int currOption = rooms.at(currRoom).options.size()-1;
                inSS >> rooms.at(currRoom).options.at(currOption).Pexit;
            }   
            else if (temp == "Fail:")
            {
                int currRoom = rooms.size()-1;
                int currOption = rooms.at(currRoom).options.size()-1;
                inSS >> rooms.at(currRoom).options.at(currOption).fail;
            }
            else if (temp == "Fexit:")
            {
                int currRoom = rooms.size()-1;
                int currOption = rooms.at(currRoom).options.size()-1;
                inSS >> rooms.at(currRoom).options.at(currOption).Fexit;
            }
            else if (temp == "Damage: ")
            {
                int currRoom = rooms.size()-1;
                int currOption = rooms.at(currRoom).options.size()-1;
                inSS >> rooms.at(currRoom).options.at(currOption).damage;
            }
        }
    };
};



int main()
{
    World world;
    Room roomObj;
    int i=0,curRoom=0;
    int strength, dexterity, intelligence, charisma, max_Health, curr_Health_Stat, dex, str, damage, temp_Finish;
    string user_Response,input;

    if(world.loadedProperly == true)
    {
        strength = rand()%16+3;
        dexterity = rand()%16+3;
        intelligence = rand()%16+3;
        charisma = rand()%16+3;
        max_Health = rand()%6+3;
        curr_Health_Stat = max_Health;

        cout<<"\nType Begin to start the game:";
        cin>>input;
        for(int i=0;i<input.length();i++)
        {
            input.at(i) = tolower(input.at(i));
        }

        if(input == "begin")
        {
            cout<<"\n\n   Current Stats       "<<endl<<endl;
            cout<<"1. Strength = "<<strength<<endl;
            cout<<"2. Dexterity = "<<dexterity<<endl;
            cout<<"3. Intelligence = "<<intelligence<<endl;
            cout<<"4. Charisma = "<<charisma<<endl;
            cout<<"5. Current Health = "<<curr_Health_Stat<<endl;


            while(curRoom!=9998)
            {
                cout<<"\n   Current Room: "<<curRoom +1 << endl;

                roomObj = world.rooms.at(curRoom);
                cout <<"\n" << roomObj.description << endl;
                cin>>user_Response;
            
                for(int j=0;j<user_Response.length();j++)
                {
                    user_Response.at(j) = tolower(user_Response.at(j));
                }

                for(i=0;i<roomObj.options.size();++i)
                {
                    if(user_Response == world.rooms.at(curRoom).options.at(i).choice)
                    {
                        if(world.rooms.at(curRoom).options.at(i).stat == "dex")
                        {
                            dex = rand()%20 + 1;
                            cout<<"\n\nYou rolled "<<dex<<" against a Dex of "<<dexterity<< ".\n"<<endl;
                            if (dex<=dexterity)
                            {
                                cout<<world.rooms.at(curRoom).options.at(i).pass; // print information at pass
                                curRoom = (world.rooms.at(curRoom).options.at(i).Pexit)-1;
                                break;  
                            }
                            else
                            {
                                damage = rand()%4 + 1;
                                cout<<world.rooms.at(curRoom).options.at(i).fail; // print information at fail
                                curRoom = (world.rooms.at(curRoom).options.at(i).Fexit)-1;
                                cout<<"\nHP: "<<curr_Health_Stat<<"/"<<max_Health<<endl;
                                break;
                            }
                        }
                        else if(world.rooms.at(curRoom).options.at(i).stat == "str")
                        {
                            str = rand()%20 + 1;
                            cout<<"\n\nYou rolled "<<str<<" against a Dex of "<<strength<< "."<<endl;
                            if (str<=strength)
                            {
                                cout<<world.rooms.at(curRoom).options.at(i).pass; // print information at pass
                                curRoom = (world.rooms.at(curRoom).options.at(i).Pexit)-1;
                                break;
                            }
                            else
                            {
                                damage = rand()%4 + 1;
                                curr_Health_Stat = curr_Health_Stat-damage;
                                cout<<world.rooms.at(curRoom).options.at(i).fail; // print information at fail
                                curRoom = (world.rooms.at(curRoom).options.at(i).Fexit)-1;
                                cout<<"HP: "<<curr_Health_Stat<<"/"<<max_Health<<endl;
                                break;
                            }
                        }
                        else if(world.rooms.at(curRoom).options.at(i).stat == "none")
                        {
                            curRoom = (world.rooms.at(curRoom).options.at(i).Pexit)-1;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            cout<<"\nThanks for playing our demo. We hope you have enjoyed it.";
            cin>>temp_Finish;// For user to press anything to quit.
        }
        cout<<"\n\n Current Room: "<<curRoom+1;
        cout<<"\n\n\nThanks for playing our demo. We hope you have enjoyed it."<<endl;
        cin>>temp_Finish;  // For user to press anything to quit.
        return 0;
    }
    else
    {
        cout<<"Could not open the file.";
        return 0;
    }

}
