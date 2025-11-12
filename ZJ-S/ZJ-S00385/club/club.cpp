#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	long long x[3],p0[3],op;
}a[100005];
ll t,vis[105],ans,nx[105],n;
bool cmp(node& x,node& y)
{
	return x.op>y.op||(x.op==y.op&&(x.x[1]-x.x[0])>(y.x[1]-y.x[0]));
}
bool cmp2(ll x,ll y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof vis);
		ans=0;
		cin>>n;
		for(int ii=1;ii<=n;ii++)
		{
			for(int i=0;i<=2;i++)
			{
				cin>>a[ii].x[i];
				nx[i]=a[ii].x[i];
			}
			sort(a[ii].x,a[ii].x+3,cmp2);
			for(int i=0;i<=2;i++)
				for(int j=0;j<=2;j++)
					if(nx[j]==a[ii].x[i])
					{
						a[ii].p0[i]=j;
					}
			a[ii].op=a[ii].x[0]-a[ii].x[1];
		 } 
		 //cout<<1;
		 sort(a+1,a+n+1,cmp);
		 /*for(int i=1;i<=n;i++)
		 {
		 	for(int j=0;j<3;j++)
		 	{
		 		cout<<a[i].p0[0]<<" "<<a[i].p0[1]<<" "<<a[i].p0[2]<<endl;
		 		//cout<<a[i].x[0]<<" "<<a[i].x[1]<<" "<<a[i].x[2]<<endl;
			 }
		 }*/
		 for(int i=1;i<=n;i++)
		 {
		 	if(vis[a[i].p0[0]]<n/2)
		 	{
		 		vis[a[i].p0[0]]++;
		 		ans+=a[i].x[0];
			 }
			 else if(vis[a[i].p0[1]]<n/2)
			 {
			 	vis[a[i].p0[1]]++;
		 		ans+=a[i].x[1];
			  } 
			else
			{
				vis[a[i].p0[2]]++;
		 		ans+=a[i].x[2];
			}
		 }
		 cout<<ans<<endl;
	}
	return 0;
}
