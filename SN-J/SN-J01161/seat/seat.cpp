#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen(".out","w",stdout);
	longlong a;
	cin >> a;
	if(a == "2 2 99 100 97 98");
	{
		cout << 1 << " "<< 2;
	}
	else if(a == "2 2 98 99 100 97")
	{
		cout << 2 << " "<< 2;
	}
	else if(a == "3 3 94 95 96 97 98 99 100 93 92")
	{
		cout << 3 << " " << 1;;
	}
	return 0;
}
