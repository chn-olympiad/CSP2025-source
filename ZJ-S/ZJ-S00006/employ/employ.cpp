#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],sum[510],b[510],ans,g[510];
string st;
void dfs(int k,int S)
{
	if(S>=m) ans=(ans+1)%998244353;
	for(int i=k+1;i<=n;i++)
	{
	  	swap(a[k],a[i]);
	  	dfs(k+1,S-(a[i]+sum[i]-i>0&&b[i])-(a[k]+sum[k]-k>0&&b[k])+(a[k]+sum[i]-i>0&&b[i])+(a[i]+sum[k]-k>0&&b[k]));
	  	swap(a[i],a[k]);
	}
}
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	int len=st.size();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//g[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=0;i<len;i++) b[i+1]=st[i]-'0';
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if(a[i]-i+sum[i]+1>=0&&b[i]) sum[i]++;
	}
	if(sum[n]<m)
	{
		cout<<0<<endl;
		return 0;
	}
	dfs(1,sum[n]);
	cout<<ans<<endl;
	return 0;
}