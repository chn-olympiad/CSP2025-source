#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(666);
const int V = 1e9;
int main()
{
	// freopen("road.in" , "r" , stdin);
	freopen("road.in" , "w" , stdout);
	int n = 1e4 , m = 1e6 , k = 10;
	cout << n << ' ' << m << ' ' << k << "\n";
	for(int i = 2 ; i <= n ; i++)
	{
		int u = rnd() % (i - 1) + 1;
		cout << u << ' ' << i << ' ' << rnd() % V << "\n";
	}
	m -= n - 1;
	for(int i = 1 ; i <= m ; i++)
	{
		int u = rnd() % n + 1;
		int v = rnd() % n + 1;
		cout << u << ' ' << v << ' ' << rnd() % V << "\n";
	}
	for(int i = 1 ; i <= k ; i++)
	{
		cout << 0 << " ";
		for(int j = 1 ; j <= n ; j++)
			cout << rnd() % V << " \n"[j == n];
	}
	return 0;
}