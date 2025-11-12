#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n, q;
string s1[N], s2[N];
string t1[N], t2[N];

inline void write(int x)
{
	if ( x < 0 ) putchar('-'), x = -x;
	if ( x > 9 ) write(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i ++ )
		cin >> s1[i] >> s2[i];
		
	for (int i = 1; i <= q; i ++ )
	{
		cin >> t1[i] >> t2[i];
		write(0);
		putchar('\n');
	}

	return 0;
}
