#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Display
    stack<int> temp = s;
    cout << "Stack elements: " << endl;

    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }

    // Peek
    cout << "Top element: " << s.top() << endl;

    // Pop
    cout << "Popping the top element: " << s.top() << endl;
    s.pop();

    // Peek after pop
    cout << "Top element after pop: " << s.top() << endl;

    return 0;
}
