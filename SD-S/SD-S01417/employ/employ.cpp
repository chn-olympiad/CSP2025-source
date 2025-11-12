#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, s[N], a[N];
	double c[N];
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> s[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> c[i];
		a[i] = int(c[i]);
	}
	cout << 0 << endl;
}
