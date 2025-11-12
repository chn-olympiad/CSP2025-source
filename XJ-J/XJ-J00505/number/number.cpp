#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	string b = "";
	cin >> a;
	long long q[1000005];
	for(int i = 0;i < a.length();i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			b += a[i];
		}
	}
	for(int i = 0;i < b.length();i++)
	{
		q[i] = b[i] - '0';
	}
	sort(q,q + b.length());
	for(int i = b.length() - 1;i >= 0;i--)
	{
		cout << q[i];
	}
	return 0;
}
