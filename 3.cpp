#include<iostream>
#include<stack>
using namespace std;

struct link {
    int data;
    link *left;
    link *right;
};

class linklist {
private:
    link *first;

public:
    linklist() {
        first = NULL;
    }

    void additem(int d);
    void display();
};

void linklist::display() {
    if (first == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    link *temp = first;
    do {
        cout << temp->data << endl;
        temp = temp->right;
    } while (temp != first);
}

void linklist::additem(int d) {
    link *nn = new link;
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;

    if (first == NULL) {
        first = nn;
        first->left = first;
        first->right = first;
    } else {
        link *temp = first;

        while (temp->right != first && temp->right->data < d) {
            temp = temp->right;
        }

        nn->right = temp->right;
        nn->left = temp;
        temp->right = nn;
        nn->right->left = nn;

        if (nn->data < first->data) {
            first = nn;
        }
    }
}

int main() {
    linklist l;
    l.additem(20);
    l.additem(40);
    l.additem(30);
    l.additem(2);
    l.additem(90);
    l.additem(36);
    l.display();

    return 0;
}
