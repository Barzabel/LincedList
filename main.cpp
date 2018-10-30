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
		if (this->head == nullptr)
		{
			this->head = item;
			this->tail = item;
			this->tail->next = nullptr;
		}
		else
		{
			this->tail->next = item;
			this->tail = item;
			this->tail->next = nullptr;
		}
	}

	T getvalhead()
	{
		return this->head->value;
	}

	T getvaltail()
	{
		return this->tail->value;
	}

	Node<T>* find(T val) {
		Node<T>(*H) = this->head;
		while (H != nullptr) {
			if (H->value == val)
			{
				return H;
			}
			H = H->next;
		}
		return nullptr;
	}




	void del(T val)
	{

		if (this->head == nullptr)
		{
			return;
		}
		if ((this->head->value == val) && (this->head == this->tail))
		{
			this->head = nullptr;
			this->tail = nullptr;
			return;
		}
		if (this->head->next != nullptr)
		{
			if (this->head->value == val)
			{
				this->head = this->head->next;
				return;
			}
		}

		Node<T>(*H) = this->head;
		while (H != nullptr) {

			if ((H->next != nullptr) && (H->next->next != nullptr))
			{
				if (H->next->value == val) {

					H->next = H->next->next;
					return;
				}
			}
			if ((H->next != nullptr) && (H->next->next == nullptr))
			{
				if (H->next->value == val) {

					this->tail = H;
					this->tail->next = nullptr;
					return;
				}
			}
			H = H->next;
		}
	}

	void delall(T val) {

		if (this->head == nullptr)
		{
			return;
		}
		if ((this->head->value == val) && (this->head == this->tail))
		{
			this->head = nullptr;
			this->tail = nullptr;
			return;
		}
		Node<T>*H = this->head;
		if(this->head->value == val)
		{
			this->head = this->head->next;
		}
		while(H!=nullptr)
		{
			if((H->next!=nullptr)&&(H->next->value==val))
			{
				if(H->next->next==nullptr)
				{
					this->tail = H;
				}

				H->next = H->next->next;
			}
			else
			{
			H = H->next;
			}
		}
		if ((this->head != nullptr) && (this->head->next == nullptr))
		{
			this->tail = this->head;
		}
		if (this->head == nullptr)
		{
			this->tail = nullptr;
		}
	}

	void dellist() 
	{
		this->head = nullptr;
		this->tail = nullptr;
	}



	void printstr() {
		Node<T>* H = this->head;
		while (H != nullptr)
		{
			cout << H->value << endl;
			H = H->next;
		}
	}

private:
	Node<T> *head;
	Node<T> *tail;
};




int main()
{
	Node<int> *pa = new Node<int>(2);
	Node<int> *pb = new Node<int>(1);
	Node<int> *pc = new Node<int>(2);
	Node<int> *pd = new Node<int>(1);
	Node<int> *p1 = new Node<int>(1);
	Node<int> *p2 = new Node<int>(1);
	Node<int> *p3 = new Node<int>(2);
	Node<int> *p4 = new Node<int>(1);
	Node<int> *p5 = new Node<int>(1);


	LinkedList<int> obg;
	obg.add_in_tail(pa);
	obg.add_in_tail(pb);
	//obg.add_in_tail(pc);
	//obg.add_in_tail(pd);
	//obg.add_in_tail(p1);
	//obg.add_in_tail(p2);
	//obg.add_in_tail(p3);
	//obg.add_in_tail(p4);
	//obg.add_in_tail(p5);

	Node<int>*P;
	P = obg.find(0);

	obg.printstr();
	cout << endl;
	obg.delall(1);

	obg.printstr();

	cout <<"\n"<< obg.getvalhead();


	return 0;
}
