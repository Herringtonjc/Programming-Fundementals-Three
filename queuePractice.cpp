#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<string> names;
    names.push("Danny");
    names.push("Kayleigh");
    names.push("Joe");

    cout << "There are currently " << names.size() << " people in the queue." << endl;
    cout << "The person at the front of the queue is " << names.front() << endl;
    cout << "The person at the back of the queue is " << names.back() << endl;
    cout << names.front() << " has been served!" << endl;
    names.pop();
    cout << "There are currently " << names.size() << " people in the queue." << endl;
    cout << "The person at the front of the queue is " << names.front() << endl;
    cout << names.back() << " is still at the back!" << endl;

    cin.get();
    return 0;
}
