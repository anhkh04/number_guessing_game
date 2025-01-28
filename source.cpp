#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
    int random_number, number;
    char choice;
    cout << "Welcome to the number-guessing game!" << endl;
    cout << "The number is between 0 and 20. Can you guess it (UwU) ?" << endl;
    cout << "Rule: You only have 5 times to guess! Be careful and have a great time!" << endl;
    cout << "===================================================================" << endl;
    do
    {
        srand(time(0));
        random_number = rand() % 21;
        int round = 0;
        while (true)
        {
            round++;
            cout << "Guess a number (or enter -1 to exit): ";
            cin >> number;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please enter again!" << endl;
                continue;
            }

            if (number == -1)
            {
                cout << "Thank you for joining the game!" << endl;
                return 0;
            }

            if(number > random_number)
            {
                cout << "Lower!" << endl;
            }
            else if(number < random_number)
            {
                cout << "Higher!" << endl;
            }
            else if (number == -1)
            {
                return 0;
            }
            else
            {
                cout << "Bingo!!!" << endl;
                cout << "The number was " << random_number << "!" << endl;
                break;
            }

            if (round == 5)
            {
                cout << "You lost, try again!" << endl;
                return 0;
            } 
        }

        enter:
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    
            cout << "Invalid input, please enter again!" << endl;
            goto enter;
        }

        if (choice == 'n')
        {
            cout << "Thank you for joining the game!" << endl;
            return 0;
        }
        else if (choice == 'y' && choice == 'n')
        {
            cout << "Invalid input, please enter again!" << endl;
            goto enter;
        }
        else if (choice != 'y' && choice != 'n')
        {
            cout << "Invalid input, please enter again!" << endl;
            goto enter;
        }
    } while (choice == 'y');
}