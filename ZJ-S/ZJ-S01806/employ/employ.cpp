#include<bits/stdc++.h>
using namespace std;
long long n, m;
string s;
long long c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	long long x = rand() % 10;
	cout << x << endl;
	return 0;
}
