#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],d;
string b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> b;
	for (int i = 0;i < b.length();i++)
	{
		if (b[i] == '0' || b[i] == '1' || b[i] == '2')
		{
			int c = b[i];
			a[++d] = c;
		}
		if (b[i] == '3' || b[i] == '4' || b[i] == '5')
		{
			int c = b[i];
			a[++d] = c;
		}
		if (b[i] == '6' || b[i] == '7' || b[i] == '8')
		{
			int c = b[i];
			a[++d] = c;
		}
		if (b[i] == '9')
		{
			int c = b[i];
			a[++d] = c;
		}
	}
	sort(a+1,a+d+1);
	for (int i = d;i >= 1;i--)
	{
		cout << a[i]-48;
	}	
	
	return 0;
}
