#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10000];
long long R=0;
void dp(long long c,long long mc,int bh,int zongshu);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	dp(0,0,0,0);
	cout << R%998244353;
	return 0;
}
void dp(long long c,long long mc,int bh,int zongshu)
{
	if(c>2*mc&&zongshu>=3)
	{
		R++;
	}
	for(int i = bh+1;i<=n;i++)
	{
		dp(c+a[i],max(mc,a[i]),i,zongshu+1);
	}
}
