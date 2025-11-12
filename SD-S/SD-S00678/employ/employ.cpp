#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],fl[505];
string aa;
int c=998244353,ans;
long long qpl()
{
	long long h=1;
	for(int i=1;i<=n;i++)
	{
		h=(h*i)%c;
	}
	return h;
}
void dfs(int x,int s)
{
	if(x-s-1+n-x+1<m)
		return ;
	if(x==n+1)
	{
		
		ans=(ans+1)%c;
	}
	for(int i=1;i<=n;i++)
	{
		int k=0,h=0;
		if(!fl[i])
		{
			fl[i]=1;
			if(!a[x]||b[i]<=s)
				k++;
			
			dfs(x+1,s+k);
			fl[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>aa;
	int h=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=aa[i-1]-'0';
		h=min(h,a[i]);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	if(h==1)
	{
		printf("%lld",qpl());
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
