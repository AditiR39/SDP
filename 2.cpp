#include<iostream>
#include<stack>
using namespace std;
struct link
{
	int data;
	link *left;
	link *right;//pointer to a structure 
};
class linklist
{
	private:
		link *first;//members are private
		
	public:
		linklist()//constructor
		{
			first=NULL;
		}
		void additem(int d);
		void display();
        void search(int key);
};
void linklist::additem(int d) {
    link *temp = new link; // Create a new node
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;

    if (first == NULL) {
        first = temp; // If the list is empty, set temp as the first node
    } else {
        temp->right = first; // Otherwise, link temp to the current first node
        first->left = temp;
        first = temp; // Make temp the new first node
    }
}

void linklist::display()
{
	link *temp=first;
	while(temp!=NULL){
	    cout<<temp->data;
	    cout<<endl;
	    temp=temp->right;
}
}
void linklist::search(int key) {
    link *temp = first;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Key is found" << endl;
            return; 
        }
        temp = temp->right;
    }
    cout << "Key is not found" << endl; 
}

int main(){
    linklist l;
    l.additem(20);
    l.additem(30);
    l.display();
    
    cout<<endl;
    l.search(80);
    return 0;
}


