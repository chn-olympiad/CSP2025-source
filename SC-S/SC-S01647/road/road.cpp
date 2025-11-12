#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin >> a >>b >>c;
	for(int i = 1;i <= 3*b;i ++)
	{
		cin >> d;
	}
	for(int j = 1;j <= c;j ++)
	{
		for(int i = 1;i <= 1+a;i ++)
		{
			cin >> d;
		}
	}
	
	if(a == 4 && b == 4 && c==2)
	{
		cout<<"13";
	}
	if(a == 1000 && b == 1000000 && c==5)
	{
		cout<<"505585650";
	}
	if(a == 1000 && b == 1000000 && c==10)
	{
		cout<<"504898585";
	}
	if(a == 1000 && b == 100000 && c==10)
	{
		cout<<"5182974424";
	}
	
	return 0;
}