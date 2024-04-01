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
        void search(int key);
        void add_at_end(int d);
        void delete_at_begin();
        void delete_at_end();
        void delete_value(int key);
        void count();
        void delete_position(int index);
        void displayReverse();
};
void linklist::additem(int d)
{
	link *newlink=new link;
	newlink->data=d;
	newlink->next=first;
	first=newlink;
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
void linklist::search(int key){
    link *current=first;
if(current!=NULL){
    while(current->data==key){
        cout<<key<< "key is found position"<<endl;
        current=current->next;
    }

    
}
}
void linklist::add_at_end(int d){
    link *prev=NULL;
    link *current=first;
    if(current!=NULL){
        while(current->next!=NULL){
            
            prev=current;
        current=current->next; 
        }
       
        link *nn=new link;
            nn->data=d;
            current->next=nn;
            nn->next=NULL;
    }
}
void::linklist::delete_at_begin(){
    link *current=first;
    first=first->next;
    free(current);
    cout<<"deleted"<<endl;
}
void linklist::delete_at_end(){
    link *current=first;
    link *prev=NULL;
    if(current!=NULL){
        while(current->next!=NULL){
            prev=current;
            current=current->next;
        }
    free(current);
    }
prev->next=NULL;
}
void linklist::delete_value(int key){
    link *current=first;
    link *prev=NULL;
    if(current !=NULL){
        while(current->data!=key){
            prev=current;
            current=current->next;
        }
        prev->next=current->next;
        free(current);
        
    }
    
}
void linklist::count(){
    link * current=first;
    int z=1;
    if(current!=NULL){
        while(current->next!=NULL){
            current=current->next;
            z+=1;
        }
    }
    cout<<"there are "<<z<<"nodes"<<endl;
}

void linklist::delete_position(int index) {
    link *current=first;
    if(current!=NULL) {
        if(index < 0) cout << "Invalid index\n";
        else {
            int i = 0;
            link *preptr = nullptr, *ptr = current;
            while(ptr && i != index) {
                ++i;
                preptr = ptr;
                ptr = ptr -> next;
            }
            if(ptr) {
                if (!preptr) current = current -> next;
                else preptr -> next = ptr -> next;
                delete ptr;
                cout << "Node deleted successfully!!\n";
            } 
            else cout << "Invalid index\n";
        }
    }
    else cout << "List is empty\n";
}
void linklist::displayReverse() {
    std::stack<int> nodeStack;  
    link* current = first;
    while (current != NULL) {
        nodeStack.push(current->data);
        current = current->next;
    }
    while (!nodeStack.empty()) {
        std::cout << nodeStack.top() << std::endl;
        nodeStack.pop();
    }
}

int main()
{
	linklist obj;
	obj.additem(20);
	obj.additem(30);
	obj.additem(40);
	obj.add_at_end(50);
	obj.display();
	cout<<endl;
	cout<<"-------------searching value-------------"<<endl;
	obj.search(30);
	cout<<endl;
	cout<<"--------------deleting begining value--------"<<endl;
    obj.delete_at_begin();
    obj.display();
    
    cout<<endl;
    cout<<"-------------deleting end value------------"<<endl;
    obj.delete_at_end();
    obj.display();
    cout<<endl;
    cout<<"---------delete value 30---------"<<endl;
    obj.additem(40);
    obj.additem(90);
    obj.add_at_end(60);
    obj.delete_value(30);
    obj.display();
    cout<<endl;
    
    cout<<"counting"<<endl;
    obj.count();
    obj.display();
    cout<<endl;
    
    cout<<"deleting position"<<endl;
    obj.display();
    cout<<endl;
    obj.delete_position(2);
    obj.display();
    
    cout<<endl;
    cout<<"displaying in reverse"<<endl;
    obj.displayReverse();
  
	return 0;
}