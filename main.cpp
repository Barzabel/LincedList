#include<iostream>
using namespace std;



template<class T>
class Node {
public:
Node(T value)
{
	this->value = value;
	this->next = nullptr;
}
	Node<T> *next;
	T value;

private:
	
};



template<class T>
class LinkedList {
public:
	LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	void add_in_tail(Node<T> *item) {
	if(this->head==nullptr)
		{
			this->head = item;
			this->tail = item;
			this->tail -> next = nullptr;
		}
	



	else
		{
			this->tail->next = item;
			this->tail = item;
			this->tail -> next = nullptr;
		}
	

		
		



	}
	T getvalhead() 
	{
		return this->head->getvalue();
	}
	T getvaltail()
	{
		return this->tail->getvalue();
	}
	Node<T>* find(T val) {
		Node<T> (*H) = this->head;
		while (H!=nullptr){
			if(H->value==val )
			{
				return H;
			}
			H = H->next;
			
		} 
		
		return nullptr;
	}
	//óäàëåíèå ýëåìåíòà
	void del(T val) {
		if (this->head->value == val)
		{
			this->head = this->head->next;
			return;
		}

		Node<T>(*H) = this->head;
		if (H->value == val) {
			this->head = this->head->next;
		}
		while (H != nullptr){ 
			
			if (H->next !=nullptr)
			{
				if (H->next->value==val) {
					
					H->next = H->next->next;
					return;
				}
			}
			if ((H->next != nullptr) && (H->next->next == nullptr) && (H->next->value == val))
			{
				H->next = nullptr;
			}
			H = H->next;
		} 
	}
	void delall(T val) {
		while((this->head!=nullptr)&&(this->head->value==val))
		{
			this->head = this->head->next;
		}
		Node<T>(*H) = this->head;
		while (H != nullptr) {
		
			if (H->next != nullptr)
			{
				if (H->next->value == val) {
					H->next = H->next->next;
					continue;
				}
			}
			if ((H->next != nullptr) && (H->next->next == nullptr) && (H->next->value == val))
			{
				H->next = nullptr;
			}
			H = H->next;
		}
	}
	void printstr() {
		Node<T>* H = this->head;
		while (H != nullptr) 
		{
			cout << H->value<<endl;
			H = H->next;
		}
	}

private:
	Node<T> *head;
	Node<T> *tail;

};








int main() 
{
	Node<int> *pa = new Node<int>(10);
	Node<int> *pb = new Node<int>(11);
	Node<int> *pc = new Node<int>(12);
	Node<int> *pd = new Node<int>(13);
	Node<int> *pn = new Node<int>(14);
	
	LinkedList<int> obg;
	obg.add_in_tail(pa);
//	obg.add_in_tail(pb);
//	obg.add_in_tail(pc);
//	obg.add_in_tail(pd);
//	obg.add_in_tail(pn);
	Node<int>*P;
	P = obg.find(0);

	//13 ýëåìåíò
	obg.del(13);
	obg.printstr();


}
