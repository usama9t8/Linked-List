#include<iostream>

using namespace std;

class Node
{
	int id;
	Node * next;

public:

	Node(int id,Node * next)
	{
		this->id=id;
		this->next=next;
	}

	friend class List;
};

class List
{
	Node * head;

public:

	List()
	{
		head=NULL;
	}

	bool isEmpty()
	{
		return (head==NULL);
	}

	void insertEnd(int id)
	{
		Node * temp =new Node(id,NULL);//next is passed as Null coz it is going to be inserted at end and last node has next Null

		if (isEmpty())
		{
			head=temp;
			cout<<id<<"added"<<endl;
		}

		else
		{
			Node * curr=head;//in order to save head so it cannot be lost 

			while(curr->next!=NULL)
			{
				curr=curr->next;
			}

			curr->next=temp;
			cout<<id<<"Added"<<endl;
		}
	}

	void insertStart(int id)
	{
		Node * temp= new Node(id,NULL);

		if(isEmpty())
		{
			temp=head;
			cout<<id<<"Added"<<endl;
		}

		else
		{
			temp->next=head;
			head=temp;
			cout<<id<<"Added"<<endl;
		}
	}

	void insertBefore (int beforeid,int newid)
	{

		if(isEmpty())
			cout<<"List Empty"<<endl;

		else
		{
		Node*pre=NULL; //to track the node prior to the node before which new node is to be added
		Node*curr=head; //to save the head in order to avoid the memory leaks


		while(curr->id != beforeid && curr->next !=NULL)
		{
			pre=curr;
			curr=curr->next;
		}

		Node * temp = new Node (newid,NULL);

		if(curr->id=beforeid)
		{
			temp->next=curr;
			pre->next=temp;
			cout<<newid<<"before after"<<beforeid<<endl;
		}
	}
	}
	void insertAfter(int afterid,int newid)
	{
		if(isEmpty())
			cout<<"List Empty"<<endl;

		else
		{

		Node * curr=head;
		Node * pro= curr->next; //to keep track of node after the node i am finding to insert after

		while(curr->id!=afterid&&curr->next!=NULL)
		{
			curr=pro;
			pro=pro->next;
		}

		Node * temp = new Node (newid,NULL);

		if(curr->id==afterid)
		{
			temp->next=pro;
			temp=curr->next;
			cout<<newid<<"added after"<<afterid<<endl;
		}
	}
	}

	void deleteStart()
	{
		if(isEmpty())
			cout<<"List Empty"<<endl;

		else
		{
			Node * temp = head;
			head=head->next;
			delete temp;
		}
	}

	void deleteEnd()
	{
			
		if(isEmpty())
			cout<<"List Empty"<<endl;

		else
		{
			Node * pre =NULL;
			Node * cur=head;

			while(cur->next!=NULL)
			{
				cur=cur->next;
			}

			pre->next=NULL;
			delete cur;
		}	
	}

	void deleteBefore(int beforeid)
	{
		
	}

	void deleteAfter(int afterid)
	{
		if(isEmpty())
			cout<<"List Empty"<<endl;

		else
		{

		Node * curr=head;
		Node * pro= curr->next; //to keep track of node after the node i am finding to delete after

		while(curr->id!=afterid&&curr->next!=NULL)
		{
			curr=pro;
			pro=pro->next;
		}

		if (curr->id==afterid)
		{
			curr->next=pro->next;
			delete pro;
		}
			
		else
		{
			cout<<"Not found"<<endl;
		}
		}
	}

	void deleteNode(int id)
	{
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}

		else
		{
			Node * curr=head;
		    Node * pre=NULL;

			while(curr->id != id && curr->next!=NULL)
			{
				pre=curr;
				curr=curr->next;
			}

			if(curr->id==id)
			{
				pre->next=curr->next;
				delete curr;
			}

			else
			{
				cout<<"Not Found"<<endl;
			}
		}
	}

	void updateNode(int oldid,int newid)
	{
		Node * cur = head;

		if(head->id==oldid)
		{
			head->id=newid;
		}

		else
		{
			while(cur->id != oldid && cur->next!=NULL)
			{		
				cur=cur->next;
			}

			if(cur->id==newid)
			{
				cur->id=newid;
			}

			else
			{
				cout<<"No Data Found"<<endl;
			}
		}
	}

	void Display()
	{
		if(isEmpty())
			cout<<"List Empty"<<endl;

		else
		{
			Node * curr=head;

			while(curr!=NULL)
			{
				cout<<curr->id<<endl;
				curr=curr->next;
			}
		}
	}


};

void main()
{
	List obj;

	obj.insertStart(7);
	//obj.insertEnd(4);
	//obj.insertEnd(6);
	//obj.insertEnd(5);
	//obj.insertEnd(51);
	

	obj.Display();

}