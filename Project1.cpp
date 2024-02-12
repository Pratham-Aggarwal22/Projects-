#include<iostream>
#include<string.h>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int strength, dexterity, intelligence, charisma, max_Health, curr_Health_Stat, dex, str, damage, temp_Finish, attempt_Counter=0;
    string input,user_Response;
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

        cout<<"\n\nYou are standing in front of the gate to a large mysterious mansion.\nThe gate's rusted lock seems ready to fall off.\nMaybe if you bashed the gate hard enough, you could get through it.\nOr, you could try to climb over the gate.\n\n\nWould you like to CLIMB or BASH the gate?"<<endl;
        cout<<"\nPlease enter your response:";
        cin>>user_Response;

        for(int j=0;j<user_Response.length();j++)
        {
            user_Response.at(j) = tolower(user_Response.at(j));
        }


        while(attempt_Counter<2)
        {
            if(user_Response == "climb")    
            {
                dex = rand()%20 + 1;
                cout<<"\n\nYou rolled "<<dex<<" against a Dex of "<<dexterity<< "."<<endl;
                if (dex<=dexterity)
                {
                    cout<<"\n'Success'\n"<<"You carefully climb over the old rusted gate.\nYou land safely on your feet inside the grounds of the mysterious mansion.";
                    break;  
                }
                else
                {
                    damage = rand()%4 + 1;
                    curr_Health_Stat = curr_Health_Stat-damage;
                    cout<<"\n'Fail'\n"<<"As you make your way over the rusted gate, the finial you are using for support snaps and you land hard on the ground below.\nYou take "<<damage<<" damage and are a little shaken.\nNevertheless, you have made it inside the grounds of the mysterious mansion.\n\n";
                    cout<<"HP: "<<curr_Health_Stat<<"/"<<max_Health;
                    break;
                }
            }
            else if(user_Response == "bash")
            {
                str = rand()%20 + 1;
                cout<<"\n\nYou rolled "<<str<<" against a Dex of "<<strength<< "."<<endl;
                if (str<=strength)
                {
                    cout<<"\n'Success'\n"<<"You put all your weight into a massive assault on the gate.\nAs you suspected, the lock was not up to the challenge and gave way easily.\nYou hear a large thud as the gate crashes open.\nYou have made it inside the grounds of the mysterious mansion.";
                    break;
                }
                else
                {
                    damage = rand()%4 + 1;
                    curr_Health_Stat = curr_Health_Stat-damage;
                    cout<<"\n'Fail'\n"<<"You put all your weight into a massive assault on the gate.\nAt first, the lock resists your attack, and the collision with the gate bites into your shoulder.\nYou take "<<damage<<" damage.\nAfter a moment's hesitation, the lock gives, and the gate swings open with a thud.\nYou have made it inside the grounds of the mysterious mansion.\n\n";
                    cout<<"HP: "<<curr_Health_Stat<<"/"<<max_Health;
                    break;
                }
            }
            else
            {
                attempt_Counter++;
                cout<<"Attempt "<<attempt_Counter<<": I'm sorry I did not understand that response. Please try again.\n";
                cin>>user_Response;
            }
        }
    }
    else
    {
        cout<<"\nThanks for playing our demo. We hope you have enjoyed it.";
        cin>>temp_Finish;  // For user to press anything to quit.
    }

    cout<<"\n\n\nThanks for playing our demo. We hope you have enjoyed it."<<endl;
    cin>>temp_Finish;  // For user to press anything to quit.
    return 0;
}

