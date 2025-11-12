#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans=0,m=998244353;
void dfs(int k,int s,int m,int l)
{
	if(k>n)
	{
		return;
	}
	if(s>2*m && l>=3 && k==n)
	{
		ans++;
	}
	dfs(k+1,s+a[k+1],a[k+1],l+1);
	dfs(k+1,s,m,l);
}
long long ksm(long long x,long long y)
{
	long long b=1;
	while(y)
	{
		if(y&1)
		{
			b=b*x%m;
		}
		x=x*x%m;
		y>>=1;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20)
	{
		dfs(0,0,0,0);
		cout << ans;
	}
	else
	{
		cout << (ksm(2,n)-n*(n-1)/2-n-1+m)%m;
	}
	return 0;
}
