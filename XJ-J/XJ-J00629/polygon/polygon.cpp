#include<bits/stdc++.h>
using namespace std;

long long int n,a[5005],x,maxn;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	cin >> n;
	for (i=1; i<=n; i++)
	{
		cin >> x;
		a[x]++;
		maxn=max(x,maxn);
	}
//	fun();
	if (maxn==1)
		cout << n-3;
	return 0;
}
