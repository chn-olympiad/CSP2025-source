#include <bits/stdc++.h>
using namespace std;
bool  f1 = 1;
struct T
{
	int a, b, c;
};
bool cmp(T x, T y)
{
	return x.a > y.a;
}
void solve()
{
	int n, tla = 0;
	cin >> n;
	T a[n + 1];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].c;
		tla += a[i].a; 
		if(a[i].b != 0)
		{
			f1 = 0;
		}
	}
	int  maxx = 0;
	if(n == 2)
	{
		maxx = max(max(max(a[1].a+a[2].b, a[1].a+a[2].c), max(a[1].b+a[2].a, a[1].b+a[2].c)), max(a[1].c + a[2].a, a[1].c + a[2].b));
		cout << maxx << endl;
	}
	else if(f1)
	{
		for(int i = 1; i <= n / 2; i++)
		{
			maxx += a[i].a;
		}
		cout << maxx << endl;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}