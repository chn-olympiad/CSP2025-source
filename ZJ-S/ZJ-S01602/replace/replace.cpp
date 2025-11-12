#include <bits/stdc++.h>
using namespace std;
string stra[200005],strb[200005],sttra,sttrb;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> stra[i]>>strb[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin >> sttra >> sttrb;
		cout << 0 << endl;
	}
	return 0;	
}
