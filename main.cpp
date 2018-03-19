//William Bryant
//In Class Project
//Text Based Adventure
//3-15-18

#include <iostream>
#include <string>

using namespace std;

//declare all functions being used
string get_text_from_user(string prompt);
int get_number_from_user(string prompt);
int display_user_commands(string option1, string option2, string option3);
void intro_to_story();

//functions for chapter one
void chapter_one();
bool read_letter();
void content_of_letter();
void display_inventory(string slot1, string slot2, string slot3, string slot4);

//functions for chapter two
void chapter_two();
bool at_wall();

//functions for chapter three
void chapter_three();
int engage_in_combat();
void first_door();
void you_won();

int main() {

    //game loop
    bool in_game = true;
    while (in_game)
    {
        //display the intro and first chapter
        intro_to_story();
        chapter_one();

        //ask what is the player's name
        string name = get_text_from_user("\nWhat is your name, Ninja?");
        cout << "\nNinja " << name << ", you have just received a letter\n";
        cout << "To your Temple deep in the forests of Japan.\n";
        //Ask if letter is read
        bool choice = read_letter();
        if (choice)
        {
            //if so, read it
            cout << "You decide to open the letter: \n";
            content_of_letter();
        }
        else
        {
            //if not, discard it
            cout << "You are sure it is not important.\n";
            cout << "[Throw's letter away]\n";
        }

        //train to look at inventory
        cout << "\nBefore leaving, you check your equipment.\n";
        cout << "\nPress Enter to open your inventory: \n";
        //wait for user to press enter
        system("Read");
        display_inventory("ninja stars", "rope", "smoke bomb", "short katana");

        cout << "\nEverything seems ready to go.\n";
        cout << "You leave the Temple to the Emperor's Palace\n\n";

        //The player can now die, so we through them into another
        //loop to test if the user is alive
        bool alive = true;
        while (alive == true)
        {
            //continue the story with chapter two
            chapter_two();

            cout << "you see two possible ways to enter the Palace.\n";
            cout << "From the West or South. What path do you choose?\n";
            //ask user what they want to do
            int chosen_path = display_user_commands("Enter from the West", "Enter form the South", "Run away (exit game)");
            if (chosen_path == 1)
            {
                cout << "You Approach a wall\n";

                //continue story
                alive = at_wall();

                //move into chapter 3
                chapter_three();
                //show user doors we can go into
                //and record their choice
                int chosen_door = display_user_commands("door 1", "door 2", "door 3");
                if (chosen_door == 1)
                {
                    cout << "\nYou go into the first door\n";
                    //call first door function
                    first_door();
                    //engage player in combat
                    int battle_action = engage_in_combat();
                    //do action according to their battle action
                    if (battle_action == 1)
                    {
                        cout << "\nYou throw a smoke bomb at your feet.\n";
                        cout << "The room fills with smoke. You leave the room.\n";
                        cout << "Last minute the Head Guard finds and stabs you.\n";
                        cout << "[You died]\n";
                        //kill player
                        alive = false;
                    }
                    else if (battle_action == 2)
                    {
                        cout << "\nYou throw three ninja stars.\n";
                        cout << "One hits him in the eye, deep\n";
                        cout << "He falls over and dies\n";
                        cout << "You find a note on his body and\n";
                        cout << "discover the correct door the\n";
                        cout << "the Emperor is in. You find it\n";
                        cout << "and see him sound asleep. Press Enter to sab him with your katana: \n";
                        cout << "\n";
                        system("read");
                        cout << "You stab him in the heart. He dies and you\n";
                        cout << "escape the Palace. You make sure to leave\n";
                        cout << "the sword in his heart, to let people know\n";
                        cout << "a ninja killed the Emperor of Japan...\n";
                        //display the win message
                        you_won();
                    }
                    else
                    {
                        cout << "You are to scared and run away...\n";
                        cout << "As you try to leave a Guard stabs yo.\n";
                        cout << "[You died]\n";
                        //kill player
                        alive = false;
                    }
                }
                else if (chosen_door == 2)
                {
                    cout << "\nYou go into door 2\n";
                    cout << "The door has a trap!\n";
                    cout << "[You died]\n";
                    //kill player
                    alive = false;
                }
                else
                {
                    cout << "\nYou got into door 3\n";
                    cout << "You made the right choice!\n";
                    cout << "You find the Emperor asleep in bed.\n";
                    cout << "\nPress Enter to sab him with your katana: \n";
                    //wait for Enter
                    system("read");
                    cout << "You stab him in the heart. He dies and you\n";
                    cout << "escape the Palace. You make sure to leave\n";
                    cout << "the sword in his heart, to let people know\n";
                    cout << "a ninja killed the Emperor of Japan...\n";
                    //display the win message
                    you_won();
                }
            }
            else if (chosen_path == 2)
            {
                //kill player
                cout << "You approach a wall\n";
                cout << "\nThere is a Guard!\n";
                cout << "He stabs you in the gut (you should have read the note)\n";
                cout << "[You died]\n";
                //set alive to false
                alive = false;
            }
            else
            {
                cout << "You are too scared and run away\n";
                //set alive to false
                alive = false;
            }
        }

        //ask the user if they wan to play again
        string play_again = get_text_from_user("you want to play again? ('yes' or 'no'): ");
        in_game = play_again == "yes";
    }

    //ending program
    cout << "\n\nThank you for playing!\n\n";

    return 0;
}




///functions///

//This function ask for an input text
//and returns it
string get_text_from_user(string prompt)
{
    string text;
    cout << prompt;
    cin >> text;
    return text;
}

//This function ask for an input number
//and returns it
int get_number_from_user(string prompt)
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

//This function controls the actions
//the player can make. It will display the
//desired actions, take in their choice, and
//return their choice in a form of a number
int display_user_commands(string option1, string option2, string option3)
{
    cout << "-1 " << option1 << endl;
    cout << "-2 " << option2 << endl;
    cout << "-3 " << option3 << endl;
    int choice = get_number_from_user("Please Enter a Number: ");
    switch (choice)
    {
        case 1: cout << "You choose to: " << option1 << "\n";
                return 1;
        case 2: cout << "You choose to: " << option2 << "\n";
                return 2;
        case 3: cout << "You choose to: " << option3 << "\n";
                return 3;
        default: cout << "Please provide a valid option\n";
                break;
    }
}

//This function shows the player
//their inventory. You can control
//waht will be displayed and it will
//put them in an array and display them.
void display_inventory(string slot1, string slot2, string slot3, string slot4)
{
    string arr[4] = {slot1, slot2, slot3, slot4};
    cout << "\nInventory: \n";
    for (const auto &i : arr) {
        cout << "- "<< i << "\n";
    }
    cout << "Press Enter to leave inventory: \n";
    //Wait for enter
    system("Read");
}

void intro_to_story()
{

    cout << "1574, Southern Japan.\n\n";
    cout << "Lord Naritsugu has been ruling Japan for over 20 years\n";
    cout << "with questionable rule among his people. Over the years,\n";
    cout << "he has developed many enemies. But none that would dare try\n";
    cout << "kill him, Lord Maritsugu, Emperor of Japan.\n\n";

    cout << "In the past few years, his actions have started to be considered\n";
    cout << "cruel, inhumane, and injustice. His enemies are growing tired, and\n";
    cout << "their fear of killing him is fading...\n\n";

}

void chapter_one()
{

    cout <<"\tThe Way of Ninjutsu\t" << endl;
    cout << "\tChapter One\t" << endl;

    cout << "One such samurai, Shinzaemon, has had enough of his cruel actions.\n";
    cout << "He needs him dead, but can't do it alone. So he has hired a Ninja.\n";
    cout << "Killing an Emperor is not easy, and there cannot be suspicion that\n";
    cout << "that a samurai would dare kill their Lord. That distrust could harm\n";
    cout << "the samurai status for decades. The death needed to be quick, and\n";
    cout << "needed to look like an assassin of Ninjutsu did it. This way people\n";
    cout << "could expect the death and not have distrust in their protectors.\n\n";

    cout << "This is your goal. You are hired to kill the Emperor of Japan, Lord\n";
    cout << "Maritsugu...";

}

//This function takes in the choice
//of reading the letter and returns
//their action
bool read_letter()
{
    string choice;
    choice = get_text_from_user("Do you read the letter? (type 'yes' or 'no')");
    return choice == "yes";
}

void content_of_letter()
{
    cout << "Here is all the information you need.\n";
    cout << "The Emperor will be arriving to his Palace\n";
    cout << "at sunset. Perfect timing. You will be able\n";
    cout << "go through the night and find him in his room\n";
    cout << "There will be guards, but they have gotten\n";
    cout << "stuck in routine. So they should be easy to\n";
    cout << "evade or kill with little problem. I only warn\n";
    cout << "you about the Head Guard. He is always with the\n";
    cout << "Emperor, or just a door or two away, at this time\n";
    cout << "of day. The only recommendation I have is to enter\n";
    cout << "the Palace from the West... Good Luck.\n";
    cout << "Samurai Shinzaemon\n";
    cout << "\nPress Enter to continue\n";
    //wait for Enter to be pressed
    system("Read");
}

void chapter_two()
{
    cout << "\tChapter Two\t" << endl;
    cout << "You arrive at the Palace just in time.\n";
    cout << "The Emperor has just entered the gate\n";
    cout << "and closed behind him. You head closer\n";
    cout << "to find a way in...\n";
}

//this function plays the wall
//simulation part of the story.
//It will return true or false
//depending on their action.
bool at_wall()
{
    cout << "\nYou are at the wall\n";
    cout << "You need to get over it, what should you use?\n";
    //display user commands
    int method_to_climb_wall = display_user_commands("Use the rope", "Throw a smoke bomb", "Stab the wall");
    //if the rope is picked, keep user alive
    if (method_to_climb_wall == 1)
    {
        cout << "\nYou quietly throw the rope on top of the wall and climb it.\n";
    }
    //if not, kill the player
    else
    {
        cout << "\nThat's silly but somehow you made it over.\n";
        cout << "\n";
        return false;
    }
}

void chapter_three()
{
    cout << "\tChapter 3\t";
    cout << "\nYou make it into the Palace.\n";
    cout << "you find three doors. You know\n";
    cout << "one is his room. What door do you choose?\n";
}

//this function allows the
//user to engage in combat
//and return their combative
//choice as a number
int engage_in_combat()
{
    cout << "\nYou make your stance.\n";
    cout << "You need to kill him or get\n";
    cout << "away. What do you do?\n";
    int choice = display_user_commands("Throw smoke bomb", "Throw ninja stars", "run away (exit game)");
    return choice;


}

//This function is used if the
//player chooses the first door
void first_door()
{
    cout << "You find the Head Guard! He draws his sword\n";
    cout << "Press Enter to engage in combat: \n";
    system("read");
}

void you_won()
{
    cout << "\nYou have successfully killed the cruel ruler\n";
    cout << "Japan is no longer under a injustice rule...\n";
}