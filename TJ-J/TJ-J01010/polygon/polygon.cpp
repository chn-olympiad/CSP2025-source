#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long cmp(long long x,long long y)
{
	return x<y;
}
long long n,maxn,ans;
void dfs(long long p1,long long p,long long cnt)
{
	if(p1>=3&&cnt>maxn*2)
	{
		ans++;
		ans%=998244353;
		//cout << cnt <<endl;
	}
	else if(p==1)
	{
		return;
	 } 
	for(int i=p-1;i>=1;i--)
	{
		dfs(p1+1,i,cnt+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=n;i>=3;i--)
	{
		maxn=a[i];
		dfs(1,i,a[i]);
	}
	cout << ans;
	return 0;
}
