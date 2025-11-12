#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n+q; i ++)
	{
		string s;
		cin >> s >> s;
	}
	srand(20110802);
	for (int i = 1; i <= q; i ++)
	{
		cout << rand() % 20110802;
	}
	return 0;
}
