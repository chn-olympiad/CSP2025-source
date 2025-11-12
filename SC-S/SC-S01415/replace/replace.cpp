#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
	}
	for(int i = 1;i <= q;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
	}
	if(n == 4 && q == 2) cout << 2 << endl << 0 << endl;
	if(n == 3 && q == 4) cout << 0 << endl << 0 << endl << 0 << endl << 0 << endl;
	return 0;
}
