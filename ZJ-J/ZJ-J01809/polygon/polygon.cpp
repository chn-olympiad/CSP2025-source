#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353 ;
int n,ans;
int a[5005],res[5005],vis[5005];
map<string,int>mp;
void dfs(int mx,int t,int sum,string s,int last)
{
	if(t<2)	return ;
	if(sum<=mx)	return ;
	vis[last]=1,mp[s]=1;
//	cout<<mx<<' '<<t<<' '<<s<<'\n';
	ans=((ans+1)%mod+mod)%mod;
	for(int i=1;i<=t;i++)
	{
		if(vis[a[i]])	continue ;
		string c=s+','+char(48+a[i]);
		if(mp[c]==0)
			dfs(mx,t-1,sum-a[i],c,a[i]),vis[a[i]]=0;
	}	
	mp[s]=0;	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],res[i]=res[i-1]+a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--)	dfs(a[i],i-1,res[i-1],"",0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
