#include "bits/stdc++.h"
using namespace std;
int n,m;
string s;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	//int sum = 0;
	int ji = 1;
	for (int i = 1;i <= n;i++)
	{
		ji *= i;
		ji %= 998244353;
	}
	cout << ji;
	return 0;
}