#include<bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005];
int b[100005];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		sort(a1 + 1, a1 + 1 + n, cmp);
		for(int i = 1; i <= n / 2; i++)
		{
			b[k] += a1[i];
		}
	}
	for(int i = 1; i <= t; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
