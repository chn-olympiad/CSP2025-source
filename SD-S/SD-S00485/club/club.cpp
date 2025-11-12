#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int a,b,c,id,dta,zf;
}s[100010];
bool cmp1(node a,node b)
{
	return a.a>b.a;
}
int fa,fb;
int dta[100010];
void dfs(int now,int na,int nb,int nc,int num,int cnt)
{
	if(now==1) cnt+=s[num].a;
	else if(now==2) cnt+=s[num].b;
	else cnt+=s[num].c;
	if(num>=n)
	{
		ans=max(ans,cnt);
		return;
	}
	if(na<(n/2)) dfs(1,na+1,nb,nc,num+1,cnt);
	if(nb<(n/2)) dfs(2,na,nb+1,nc,num+1,cnt);
	if(nc<(n/2)) dfs(3,na,nb,nc+1,num+1,cnt);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=-999;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0) fa=1;
			if(s[i].c!=0) fb=1;
			s[i].id=i;
		}
		if(n<=30)
		{
			dfs(1,1,0,0,1,0);
			dfs(2,0,1,0,1,0);
			dfs(3,0,0,1,1,0);
			cout<<ans<<endl;
		}
		else if(fa==0&&fb==0)
		{
			sort(s+1,s+n+1,cmp1);
			for(int i=1;i<=n/2;i++) ans+=s[i].a;
			cout<<ans<<endl;
		}
	}
	return 0;
} 
