#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> cards;

    cards.push("King of Hearts");
    cards.push("King of Clubs");
    cards.push("King of Diamonds");
    cards.push("King of Spades");

    cout << "There are " << cards.size() << " cards in the stack." << endl;
    cout << "The card on top of the stack is " << cards.top() << endl;
    cards.pop();
    cout << "The new card on top of the stack is " << cards.top() << endl;
    cout << "There are now " << cards.size() << " cards in the stack" << endl;

    cin.get();
    return 0;
}
