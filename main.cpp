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
		this->count = 0;
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
		this->count++;
	}

	Node<T>* gethead()
	{
		return this->head;
	}

	Node<T>* gettail()
	{
		return this->tail;
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
				this->count= 0;
				return;
			}
			if ((!ALL) && (this->head->next==this->tail) && (this->head->value==val))
			{
				
				this->head = this->tail;
				this->count--;
				return;
			}
		


			Node<T>*H = this->head;
			if (this->head->value == val)
			{
				this->head = this->head->next;

				this->count--;

				
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
						this->count--;
						this->tail = H;
						this->tail->next = nullptr;
						return;
					}
					this->count--;
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
		this->count = 0;
	}

	void add_in_position(Node<T>*position, Node<T>*value)
	{
		if (position->next == nullptr) 
		{
			position->next = value;
			value->next = nullptr;
			this->tail = value;
		}else{
		value->next = position->next;
		position->next = value;
		}
		this->count++;
	}

	LinkedList<T>* findall(T val)
	{

		LinkedList<T>* robg=new LinkedList<T>;
		Node<T> *H = this->head;
		Node<T> *p;
		while(H!=nullptr)
		{

			if (H->value == val) 
			{
				p = new Node<T>(val);
				robg->add_in_tail(p);
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
		return this->count;
	}

	friend LinkedList<T>* list_add_list(LinkedList<T> *val1, LinkedList<T> *val2)
{

	LinkedList<T> *res= new LinkedList<T>;
	if (val1->count == val2->count)
	{
		Node<T>*H1 = val1->head;

		Node<T>*H2 = val2->head;
		Node<T>*P;

		while (H1 != nullptr)
		{
			P = new Node<T>(H1->value + H2->value);
			res->add_in_tail(P);
			H1 = H1->next;
			H2 = H2->next;
		}



	}
	return res;
}


private:
	unsigned int count;
	Node<T> *head;
	Node<T> *tail;
	
};









int main()
{
	// test 1 class Node
	cout << "test 1 class Node" << endl;
	Node<int> *p =new Node<int>(1);
	if ((p->next == nullptr) && (p->value = 1)){
		cout << "true \n"<<endl;}
	else {
		cout << "false \n" << endl;
	}

	delete p;
	p = nullptr;
	// test 2 class LinkedList
	cout << "test 2 class LinkedList" << endl;
	LinkedList<int>*obg= new LinkedList<int>;
	if ((obg->gethead() == nullptr) && (obg->gettail() == nullptr)&&(obg->getsize()==0)) {
		cout << "true \n" << endl;
	}
	else {
		cout << "false \n" << endl;
	}
	obg->~LinkedList();
	obg=nullptr;
	// test 3 class LinkedList. void add_in_tail(Node<T> *item)


	cout << "test 3 class LinkedList add_in_tail ferst element" << endl;
	obg = new LinkedList<int>;
	p = new Node<int>(1);
	obg->add_in_tail(p);
	if ((obg->gethead() == obg->gettail())  && (obg->getsize() == 1)) {
		cout << "true \n" << endl;
	}
	else {
		cout << "false \n" << endl;
	}
	// test 4 class LinkedList. void add_in_tail(Node<T> *item)

	cout << "test 4 class LinkedList add_in_tail too element" << endl;
	Node<int> *p2 = new Node<int>(2);
	obg->add_in_tail(p2);
	if ((obg->gethead() != obg->gettail()) && (obg->getsize() == 2)&&(obg->gettail()->value==2)&&(obg->gettail()->next==nullptr)) {
		cout << "true \n" << endl;
	}
	else {
		cout << "false \n" << endl;
	}


	// test 5 class LinkedList. void add_in_position(Node<T>*position, Node<T>*value)
	cout << "test 5 class LinkedList add_in_position" << endl;
	Node<int> *p3 = new Node<int>(3);
	obg->add_in_position(obg->gethead(), p3);

	if((obg->gethead()->next==p3)&&(p3->next==obg->gettail())&&(obg->getsize()==3))
	{
		cout << "true \n" << endl;
	}
	else 
	{
		cout << "false \n" << endl;
	}


	// test 6 class LinkedList. void add_in_position(Node<T>*position, Node<T>*value) in taill
	cout << "test 6 class LinkedList add_in_position in tail" << endl;
	Node<int> *p4 = new Node<int>(4);
	obg->add_in_position(obg->gettail(), p4);

	if ((obg->gettail() == p4) && (p4->next == nullptr) && (obg->getsize() == 4))
	{
		cout << "true \n" << endl;
	}
	else
	{
		cout << "false \n" << endl;
	}
	// test 7 class LinkedList.find
	cout << "test 6 class LinkedList  find()" << endl;
	Node<int> *p5 = obg->find(4);
	if ((obg->gettail() == p5) && (p5->next == nullptr) && (p5->value== 4))
	{
		cout << "true \n" << endl;
	}
	else
	{
		cout << "false \n" << endl;
	}
	//  test 7 class LinkedList.findall
	Node<int> *p6 =new Node<int>(4);
	obg->add_in_tail(p6);
	LinkedList<int>*obg2 = obg->findall(4);
	cout << "test 7 class LinkedList  findall()" << endl;
	if ((obg2->gettail()->value == 4) && (obg2->gettail()->next == nullptr) && (obg2->getsize() == 2)&&(obg2->gethead()->value==4))
	{
		cout << "true \n" << endl;
	}
	else
	{
		cout << "false \n" << endl;
	}
	//  test 8 class LinkedList. del
	cout << "test 7 class LinkedList  del()" << endl;
	Node<int> *p7 = new Node<int>(4);
	obg->add_in_tail(p7);
	obg->del(4, true);

	if(obg->find(4)==nullptr)
	{
		cout << "true \n" << endl;
	}
	else
	{
		cout << "false \n" << endl;
	}
	//  test 9 class LinkedList.  dellist()
	cout << "test 7 class LinkedList  dellist()" << endl;
	obg->dellist();
	if((obg->gethead()==nullptr)&&(obg->gettail()==nullptr))
	{
		cout << "true \n" << endl;
	}
	else
	{
		cout << "false \n" << endl;
	}





	delete p7;
	delete p6;
	delete p5;
	delete p3;
	delete p2;
	delete p;
	return 0;
}
