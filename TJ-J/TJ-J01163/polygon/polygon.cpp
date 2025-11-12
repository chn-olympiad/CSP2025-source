#include<bits/stdc++.h>
using namespace std;
long long a[5005];
bool(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	long long x = a[1] + a[2] + a[3];
	if(a[1] * 2 < x)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
	return 0;
}
