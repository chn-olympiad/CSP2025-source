#include<bits/stdc++.h>
using namespace std;
int n[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for (int i=0;i<=a.length();i++)
	{
		if (a[i]=='0')
		{
			n[0]++;
		}
		if (a[i]=='1')
		{
			n[1]++;
		}
		if (a[i]=='2')
		{
			n[2]++;
		}
		if (a[i]=='3')
		{
			n[3]++;
		}
		if (a[i]=='4')
		{
			n[4]++;
		}
		if (a[i]=='5')
		{
			n[5]++;
		}
		if (a[i]=='6')
		{
			n[6]++;
		}
		if (a[i]=='7')
		{
			n[7]++;
		}
		if (a[i]=='8')
		{
			n[8]++;
		}
		if (a[i]=='9')
		{
			n[9]++;
		}
	}
	for (int i=9;i>0;i--)
	{
		for (in j=1;j<=n[i];j++)
		{
			if (n[i]!=0)
				cout << n[i];
				n[i]--;
		}
	}
	return 0;
 } 
 
