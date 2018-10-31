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
		this->i = 0;
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
		this->i++;
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




	void del(T val,bool ALL=false)
	{
		
		

			if (this->head == nullptr)
			{
				return;
			}
			if ((this->head->value == val) && (this->head == this->tail))
			{
				this->head = nullptr;
				this->tail = nullptr;
				this->i = 0;
				return;
			}
			if ((!ALL) && (this->head->next==this->tail) && (this->head->value==val))
			{
				
				this->head = this->tail;
				this->i--;
				return;
			}
		


			Node<T>*H = this->head;
			if (this->head->value == val)
			{
				this->head = this->head->next;

				this->i--;

				
				if(!ALL) 
				{
					return;
				}
			}
			while (H != nullptr)
			{
				
				
				if ((H->next != nullptr) && (H->next->value == val))
				{
					
					if (H->next->next == nullptr)
					{
						this->i--;
						this->tail = H;
						this->tail->next = nullptr;
						return;
					}
					this->i--;
					H->next = H->next->next;
					
					if (!ALL) { return; }

					
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

	void add_in_position(Node<T>*position, Node<T>*value)
	{
		value->next = position->next;
		position->next = value;
	}

	LinkedList<T> findall(T val)
	{

		LinkedList<T> robg;
		Node<T> *H = this->head;
		Node<T> *p = nullptr;
		while(H!=nullptr)
		{

			if (H->value == val) 
			{
				p = new Node<T>(val);
				robg.add_in_tail(p);
			}
			H = H->next;
		}
		return robg;
	}




	void printstr() {
		Node<T>* H = this->head;
		while (H != nullptr)
		{
			cout << H->value << endl;
			H = H->next;
		}
	}

	unsigned int getsize() {
		return this->i;
	}

	friend LinkedList<T> list_add_list(LinkedList<T> *val1, LinkedList<T> *val2)
{

	LinkedList<T> res;
	if (val1->i == val2->i)
	{
		Node<T>*H1 = val1->head;

		Node<T>*H2 = val2->head;
		Node<T>*P;

		while (H1 != nullptr)
		{
			P = new Node<T>(H1->value + H2->value);
			res.add_in_tail(P);
			H1 = H1->next;
			H2 = H2->next;
		}



	}
	return res;
}


private:
	unsigned int i;
	Node<T> *head;
	Node<T> *tail;
};









int main()
{
	Node<int> *pa = new Node<int>(2);
	Node<int> *pb = new Node<int>(2);
	Node<int> *pc = new Node<int>(2);
	Node<int> *pd = new Node<int>(2);
	Node<int> *p1 = new Node<int>(2);
	Node<int> *p2 = new Node<int>(2);
	Node<int> *p3 = new Node<int>(2);
	Node<int> *p4 = new Node<int>(2);
	Node<int> *p5 = new Node<int>(2);
	Node<int> *p6 = new Node<int>(2);

	LinkedList<int> obg;
	obg.add_in_tail(pa);
	obg.add_in_tail(pb);
	obg.add_in_tail(pc);
	obg.add_in_tail(pd);
	


	LinkedList<int> obg2;

	obg2.add_in_tail(p1);
	obg2.add_in_tail(p2);
	obg2.add_in_tail(p3);
	obg2.add_in_tail(p4);

	LinkedList<int> obg3;
	obg3 = list_add_list(&obg, &obg2);
	obg3.printstr();


	return 0;
}
