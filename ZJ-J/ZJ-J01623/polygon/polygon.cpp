#include <bits/stdc++.h>
using namespace std;
long long n,mod=998244353,ans,a[5001];
void dfs(long long dep, long long len, long long mx, long long num, bool flag)
{
	if (!flag and num>2 and len>(mx<<1))
		ans++,ans%=mod,flag=1;
	if (dep>n) return;
	dfs(dep+1,len,mx,num,flag);
	dfs(dep+1,len+a[dep],a[dep],num+1,0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}
