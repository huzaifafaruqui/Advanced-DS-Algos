#include<iostream>
#include "BST.h"

using namespace std;

int main()
{
	BinarySearchTree<int> b1;
	int ch;
	int x;
	while(1)
	{
		cin>>ch;
		switch(ch)
		{
			case 1: cin>>x;
					b1.insert(x);
					cout<<b1;
					break;
			case 2:
					cin>>x;
					cout<<b1.search(x);
					break;
			case 3: cout<<b1.Min();
					break;
			case 4: cout<<b1.Max();
					break;
			case 5: cout<<b1.size();
					break;				
		}
		cout<<endl;
		if(ch==6)
			break;
	}

}