#include<bits/stdc++.h>
using namespace std;
string a;
int a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i = 0;i < a.size();i++)
	{
		if(a[i] == '0')
		{
			a0++;
			cnt++;
		}
		if(a[i] == '1')
		{
			a1++;
			cnt++;
		}
		if(a[i] == '2')
		{
			a2++;
			cnt++;
		}
		if(a[i] == '3')
		{
			a3++;
			cnt++;
		}
		if(a[i] == '4')
		{
			a4++;
			cnt++;
		}
		if(a[i] == '5')
		{
			a5++;
			cnt++;
		}
		if(a[i] == '6')
		{
			a6++;
			cnt++;
		}
		if(a[i] == '7')
		{
			a7++;
			cnt++;
		}
		if(a[i] == '8')
		{
			a8++;
			cnt++;
		}
		if(a[i] == '9')
		{
			a9++;
			cnt++;
		}
	}
	for(int i = 0;i < a9;i++)
	{
		if(a9 != 0)
		{
			cout << 9;
		}
	}
	for(int i = 0;i < a8;i++)
	{
		if(a8 != 0)
		{
			cout << 8;
		}
	}
	for(int i = 0;i < a7;i++)
	{
		if(a7 != 0)
		{
			cout << 7;
		}
	}
	for(int i = 0;i < a6;i++)
	{
		if(a6 != 0)
		{
			cout << 6;
		}
	}
	for(int i = 0;i < a5;i++)
	{
		if(a5 != 0)
		{
			cout << 5;
		}
	}
	for(int i = 0;i < a4;i++)
	{
		if(a4 != 0)
		{
			cout << 4;
		}
	}
	for(int i = 0;i < a3;i++)
	{
		if(a3 != 0)
		{
			cout << 3;
		}
	}
	for(int i = 0;i < a2;i++)
	{
		if(a2 != 0)
		{
			cout << 2;
		}
	}
	for(int i = 0;i < a1;i++)
	{
		if(a1 != 0)
		{
			cout << 1;
		}
	}
	for(int i = 0;i < a0;i++)
	{
		if(a0 != 0)
		{
			cout << 0;
		}
	}
	return 0;
}
