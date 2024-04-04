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
};
void linklist::additem(int d)
{   
    link *temp = first;
    int z = d % 2;
    
    if(first == NULL) {
        link *newlink = new link;
        newlink->data = d;
        newlink->next = first;
        first = newlink;
    }
    else if(z == 0) {
        link *nn = new link;
        nn->data = d;

        nn->next = first;
        first = nn;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        link *nn = new link;
        nn->data = d;
        nn->next = NULL;
        temp->next = nn;
    }
}


void linklist::display()
{
	link *current=first;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
}




int main()
{
	linklist obj;
	obj.additem(20);
	obj.additem(30);
	obj.additem(33);
	obj.additem(22);
	obj.additem(35);
	obj.additem(40);
	obj.display();
	
}