#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;
    int rearElement;

public:
    QueueUsingStacks() {
        rearElement = -1;
    }

    // Enqueue
    void enqueue(int x) {
        s1.push(x);
        rearElement = x;
        cout << x << " enqueued\n";
    }

    // Dequeue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued\n";
        s2.pop();

        if (s1.empty() && s2.empty())
            rearElement = -1;
    }

    // Front
    void front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front element: " << s2.top() << endl;
    }

    // Rear
    void rear() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Rear element: " << rearElement << endl;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();  // 10
    q.rear();   // 30

    q.dequeue(); // removes 10
    q.front();   // 20
    q.rear();    // 30

    q.dequeue(); // removes 20
    q.dequeue(); // removes 30
    q.rear();    // empty

    return 0;
}
