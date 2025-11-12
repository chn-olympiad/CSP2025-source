#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010]={0},b[100010]={0},num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	/*num=(s);
	for(int i=0; i<=1000; i++)
	{
		if(s[i] == '0')
		{
			a[i] = 0;
			num++;
		}
		if(s[i] == '1')
		{
			a[i] = 1;
			num++;
		}
		else
		{
			if(s[i] == '2')
		{
			a[i] = 2;
			num++;
		}
			else
		{
			if(s[i] == '3')
		{
			a[i] = 3;
			num++;
		}
			else
		{
			if(s[i] == '4')
		{
			a[i] = 4;
			num++;
		}
			else
		{
				if(s[i] == '5')
		{
			a[i] = 5;
			num++;
		}
			else
		{
				if(s[i] == '6')
		{
			a[i] = 6;
			num++;
		}
			else
		{
			if(s[i] == '7')
		{
			a[i] = 7;
			num++;
		}
			else
		{
			if(s[i] == '8')
		{
			a[i] = 8;
			num++;
		}
			else
		{
			if(s[i] == '9')
		{
			a[i] = 9;
			num++;
		}
			else
		{
			continue;
		}
		}
		}
		}
		}
		}
		}
		}
		}
	}
	sort(a,a+num+1);
	for(int i=1; i<=num; i++)
	{
		b[i] = a[num+1-i];
	}
	for(int i=1; i<=num; i++)
	{
		cout<<b[i];
	}*/
	cout<<s;
	return 0;
}
