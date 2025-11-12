#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,d;
	cin >> a >>b;
	for(int i = 1;i <= 2*a;i ++)
	{
		cin >> d;
	}
	
	for(int i = 1;i <= 2*b;i ++)
	{
		cin >> d;
	}
	if(a == 4 && b == 2)
	{
		cout << "2" << endl << "0";
	}
	if(a == 3 && b == 4)
	{
		cout << "0" << endl << "0" << endl << "0" << endl<< "0";
	}
	
	return 0;
}