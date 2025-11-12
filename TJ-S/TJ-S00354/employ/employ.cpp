#include<bits/stdc++.h>
using namespace std;


const int N = 1e4+5;
int n, m, c[N], p1=1;
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1; i<=n; i++)
	{
		cin >> c[i];
	}
	for(int i=n; i>=n-m+1; i--)
		p1 *= i;
	cout << p1;

	
	return 0;
}
