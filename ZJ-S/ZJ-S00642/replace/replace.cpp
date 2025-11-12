#include <bits/stdc++.h>
using namespace std;
string x[200010];
string y[200010];
string a[200010];
string b[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i] >> y[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	return 0;
}
