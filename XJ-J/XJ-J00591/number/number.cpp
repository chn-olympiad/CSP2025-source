#include <bits/stdc++.h>
using namespace std;
int n[1000010],cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for (int i=0;i<a.length();i++)
	{
		if (a[i] - '0' < 10)
		{
			n[cnt++] = a[i] - '0';
		}
	}
	sort(n+0,n+cnt);
	for (int i=cnt-1;i>=0;i--)
	{
		cout << n[i];
	}
	return 0;
} 
