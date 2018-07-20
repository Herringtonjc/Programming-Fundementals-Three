#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Each card is a struct
struct cardType
{
    int hiddenValue;
    string value;
    string suit;
    string name;
};

//Function prototypes
void createDeck(vector<cardType>& deckList);
void menu(vector<cardType>& deckList);
void guessSuit(vector<cardType>& deckList);
void guessValue(vector<cardType>& deckList);
void guessBoth(vector<cardType>& deckList);

int main()
{
    //Create a vector of the structs
    vector<cardType> deckList;

    //Build the deck & push it into the vector
    createDeck(deckList);

    //Shuffle the vector
    random_shuffle(deckList.begin(), deckList.end());

    //Gives the user three chances
    int userGuess = 1;
    while(userGuess < 4)
    {
        menu(deckList);
        userGuess++;
    }

    return 0;
}

void createDeck(vector<cardType>& deckList)
{
    for(int k = 1; k < 53; k++)
    {
        for(int i = 14; i > 1; i--)
        {
            cardType card;
            card.hiddenValue = i;

            switch(card.hiddenValue)
            {
            case 2:
                card.name = "Two of";
                card.value = "two";
                break;
            case 3:
                card.name = "Three of";
                card.value = "three";
                break;
            case 4:
                card.name = "Four of";
                card.value = "four";
                break;
            case 5:
                card.name = "Five of";
                card.value = "five";
                break;
            case 6:
                card.name = "Six of";
                card.value = "six";
                break;
            case 7:
                card.name = "Seven of";
                card.value = "seven";
                break;
            case 8:
                card.name = "Eight of";
                card.value = "eight";
                break;
            case 9:
                card.name = "Nine of";
                card.value = "nine";
                break;
            case 10:
                card.name = "Ten of";
                card.value = "ten";
                break;
            case 11:
                card.name = "Jack of";
                card.value = "jack";
                break;
            case 12:
                card.name = "Queen of";
                card.value = "queen";
                break;
            case 13:
                card.name = "King of";
                card.value = "king";
                break;
            case 14:
                card.name = "Ace of";
                card.value = "ace";
                break;
            default:
                cout <<  "Something Broke...";
            }

            for(int j = 0; j < 4; j++)
            {
                if(j == 0)
                {
                    card.suit = "spades";
                }
                else if(j == 1)
                {
                    card.suit = "clubs";
                }
                else if(j == 2)
                {
                    card.suit = "diamonds";
                }
                else
                {
                    card.suit = "hearts";
                }

                deckList.push_back(card);
            }
        }
    }
}

void menu(vector<cardType>& deckList)
{
    int menuChoice;

    cout << "Would you like to guess the: \n";
    cout << "1. Suit \n";
    cout << "2. Value \n";
    cout << "3. Both \n";
    cout << "\n";
    cin >> menuChoice;
    cout << "\n";

    switch(menuChoice)
    {
    case 1:
        guessSuit(deckList);
        break;
    case 2:
        guessValue(deckList);
        break;
    case 3:
        guessBoth(deckList);
        break;
    default:
        cout << "That is not a valid choice!\n";
        cout << "\n";
        menu(deckList);
        break;
    }
}

void guessSuit(vector<cardType>& deckList)
{
    string suitChoice;

    cout << "What suit do you think the card is? \n";
    cout << "Clubs, Spades, Diamonds, Hearts";
    cout << "\n";
    cin >> suitChoice;
    transform(suitChoice.begin(), suitChoice.end(), suitChoice.begin(), ::tolower);
    cout << "\n";

    if(suitChoice == deckList.front().suit)
    {
        cout << "Correct! \n";
    }
    else
    {
        cout << "Incorrect! \n";
        cout << "The card is " << deckList.front().suit;
        cout << "\n\n";
    }

    random_shuffle(deckList.begin(), deckList.end());
}

void guessValue(vector<cardType>& deckList)
{
    string valueChoice;

    cout << "What value do you think the card is \n";
    cout << "2-10, Jack, Queen, King, Ace";
    cout << "\n";
    cin >> valueChoice;
    transform(valueChoice.begin(), valueChoice.end(), valueChoice.begin(), ::tolower);
    cout << "\n";

    if(valueChoice == deckList.front().value)
    {
        cout << "Correct! \n";
    }
    else
    {
        cout << "Incorrect! \n";
        cout << "The card is " << deckList.front().value;
        cout << "\n\n";
    }

    random_shuffle(deckList.begin(), deckList.end());
}

void guessBoth(vector<cardType>& deckList)
{
    string suitChoice, valueChoice;

    cout << "What suit do you think the card is? \n";
    cout << "Clubs, Spades, Diamonds, Hearts";
    cout << "\n";
    cin >> suitChoice;
    transform(suitChoice.begin(), suitChoice.end(), suitChoice.begin(), ::tolower);
    cout << "\n";

    cout << "What value do you think the card is \n";
    cout << "2-10, Jack, Queen, King, Ace";
    cout << "\n";
    cin >> valueChoice;
    transform(valueChoice.begin(), valueChoice.end(), valueChoice.begin(), ::tolower);
    cout << "\n";

    if(suitChoice == deckList.front().suit && valueChoice == deckList.front().value)
    {
        cout << "Correct! \n";
    }
    else if(suitChoice == deckList.front().suit || valueChoice == deckList.front().value)
    {
        cout << "Close! \n";
        cout << "The card was " << deckList.front().name << deckList.front().value;
        cout << "\n\n";
    }
    else
    {
        cout << "Incorrect! \n";
        cout << "The card is " << deckList.front().name << " " << deckList.front().suit;
        cout << "\n\n";
    }

    random_shuffle(deckList.begin(), deckList.end());
}