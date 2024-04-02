#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};
class linklist {
private:
    Node *first;
    stack<int>s;

public:
    linklist() {
        first = NULL;
    }

    void additem(int d);
    void display();
    void remove();
    void peek();
    void isempty();
};
void linklist::isempty(){
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
    cout<<"not empty"<<endl;
}}
void linklist::additem(int d){
    s.push(d);
}
void linklist::display() {
    stack<int> tempStack = s;

    cout << "Stack contents:" << endl;
    while (!tempStack.empty()) {
        cout << tempStack.top() << endl;
        tempStack.pop(); 
    }
}
void linklist::remove(){
    s.pop();
}
void linklist::peek() {
    if (!s.empty()) {
        cout << "Top element: " << s.top() << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

int main() {
    linklist list;
    list.additem(5);
    list.additem(6);
    list.additem(7);
    list.additem(34);
    list.additem(78);
    list.additem(90);
    list.peek();
    list.remove();
    list.display();
    list.isempty();
    

}