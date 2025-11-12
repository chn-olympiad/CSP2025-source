#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+5;
string n;
ll ans,m;
int k[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	ll a;
	a = n.size();
	if (a == 1)
	{
		cout << n;
		return 0;
	}
	m = 0;
	for (int i = 1;i <= a;++i)
	{
		if (n[i] == '0')
		{
			k[m] = 0;
			m++;
		}
		if (n[i] == '1')
		{
			k[m] = 1;
			m++;
		}
		if (n[i] == '2')
		{
			k[m] = 2;
			m++;
		}
		if (n[i] == '3')
		{
			k[m] = 3;
			m++;
		}
		if (n[i] == '4')
		{
			k[m] = 4;
			m++;
		}
		if (n[i] == '5')
		{
			k[m] = 5;
			m++;
		}
		if (n[i] == '6')
		{
			k[m] = 6;
			m++;
		}
		if (n[i] == '7')
		{
			k[m] = 7;
			m++;
		}
		if (n[i] == '8')
		{
			k[m] = 8;
			m++;
		}
		if (n[i] == '9')
		{
			k[m] = 9;
			m++;
		}
	}
	sort(k + 1,k + m + 1);
	for (int i = 0;i <= m;++i)
	{
		cout << k[i];
	}
	cout << a;
}
