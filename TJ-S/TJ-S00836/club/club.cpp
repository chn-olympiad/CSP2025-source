#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],b[100005];
long long ans;
bool cmp(long long x,long long y)
{
	return x>y;
}
void dfs(int c1,int c2,int c3,int id,long long sum)
{
	if(id==n) ans=max(ans,sum);
	if(c1) dfs(c1-1,c2,c3,id+1,a[id+1][1]+sum);
	if(c2) dfs(c1,c2-1,c3,id+1,a[id+1][2]+sum);
	if(c3) dfs(c1,c2,c3-1,id+1,a[id+1][3]+sum);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) flag=0;
			b[i]=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(flag)
		{
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=b[i];
			}
			cout<<ans<<endl;
		}
		else if(n<=20)
		{
			dfs(n/2,n/2,n/2,0,0);
			cout<<ans<<endl; 
		}
	}
	return 0;
}
