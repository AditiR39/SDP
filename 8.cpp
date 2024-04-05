#include<iostream>
#include<stack>
using namespace std;
struct link
{
	int data;
	link *next; //pointer to a structure 
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
        //void add_at_end(int d);
        void displayReverse(int k);
};

void linklist::display()
{
	link *current=first;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
}

void linklist::additem(int d)
{
	link *newlink=new link;
	newlink->data=d;
	newlink->next=first;
	first=newlink;
}

void linklist::displayReverse(int k) {
    stack<int> nodeStack;  
    link* current = first;
    int count = 0;
    while (current != NULL) {
        nodeStack.push(current->data);
        count++;
        if (count % k == 0 || current->next == NULL) {
            while (!nodeStack.empty()) {
                cout << nodeStack.top() << " ";
                nodeStack.pop();
            }
        }
        current = current->next;
    } 
}

int main()
{
	linklist obj;
	obj.additem(10);
	obj.additem(20);
	obj.additem(30);
	obj.additem(40);
	obj.additem(50);
	obj.additem(60);
	obj.additem(70);
	obj.additem(80);
	obj.additem(90);
	obj.additem(100);
	obj.display();
	cout<<endl;
	obj.displayReverse(3);
	cout<<endl;

}