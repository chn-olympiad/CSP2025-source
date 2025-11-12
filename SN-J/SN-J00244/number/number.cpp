#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

string s;
int a[1000009];
int b[1000009];
//int sortres[1000009];
int cur;


void asort()
{
	for(int i = 0 ; i <= cur; i++)
	{
//		if(i == cur - 1)
//		{
//
//		}
		if(b[i] < b[i+1])
		{
			int x, y;
			x=b[i];
			y=b[i+1];
			b[i] = y;
			b[i+1] = x;
		}
		if(b[i] >= b[i+1])
		{
			int x, y;
			x=b[i];
			y=b[i+1];
			b[i] = x;
			b[i=1]=y;
		}
	}
}


int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	getline(cin, s);

	cur = -1;
	for(int i = 0 ; i < s.size(); i++)
	{

		if(s[i] >= '1' && s[i] <= '9')
		{
			cur++;
			a[cur] = s[i];
		}
	}

	for(int i = 0 ; i <= cur; i++)
	{
		if(a[i] == 49)
		{
			b[i] = 1;
		}
		if(a[i] == 50)
		{
			b[i] = 2;
		}
		if(a[i] == 51)
		{
			b[i] = 3;
		}
		if(a[i] == 52)
		{
			b[i] = 4;
		}
		if(a[i] == 53)
		{
			b[i] = 5;
		}
		if(a[i] == 54)
		{
			b[i] = 6;
		}
		if(a[i] == 55)
		{
			b[i] = 7;
		}
		if(a[i] == 56)
		{
			b[i] = 8;
		}
		if(a[i] == 57)
		{
			b[i] = 9;
		}
	}
	asort();
//	begin()
//	b = sort(b.begin(), b.last());
	for(int i = 0 ; i <= cur; i++)
	{
		cout << b[i];
	}

	return 0;
}

