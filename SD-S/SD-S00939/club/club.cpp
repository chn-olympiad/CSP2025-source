#include <bits/stdc++.h>
using namespace std;
struct nod
{
	int a,b,c;
}e[100006];
struct k
{
	int x,id,l;
}g[400005];
int cmp(k a,k b)
{
	return a.x<b.x;
}
int vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int t;
	cin>>t;
	while(t--)
	{
		int n,cnt=0,ans=0,cnt2=0,cnt3=0,cnt4=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i].a>>e[i].b>>e[i].c;
			g[++cnt].x=e[i].a-e[i].b,g[cnt].id=i,g[cnt].l=2;
			g[++cnt].x=e[i].a-e[i].c,g[cnt].id=i,g[cnt].l=3;
			ans+=e[i].a;
		}
//		cout<<ans<<"\n";
		sort(g+1,g+cnt+1,cmp);
//		for(int i=1;i<=cnt;i++)
//			cout<<g[i].x<<" ";
		for(int i=1;i<=cnt;i++)
			if((cnt2<n/2||g[i].x<=0)&&(!vis[g[i].id]))
			{
				if(g[i].l==2&&cnt3<n/2)
					ans-=g[i].x,cnt2++,cnt3++,vis[g[i].id]=1;
				else if(g[i].l==3&&cnt4<n/2)
					ans-=g[i].x,cnt2++,cnt4++,vis[g[i].id]=1;
			}
//		cout<<ans<<"\n";
		sum=max(ans,sum);
		cnt=0,ans=0,cnt2=0,cnt3=0,cnt4=0;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
//			cin>>e[i].a>>e[i].b>>e[i].c;
			g[++cnt].x=e[i].b-e[i].a,g[cnt].id=i,g[cnt].l=2;
			g[++cnt].x=e[i].b-e[i].c,g[cnt].id=i,g[cnt].l=3;
			ans+=e[i].b;
		}
//		cout<<ans<<"\n";
		sort(g+1,g+cnt+1,cmp);
//		for(int i=1;i<=cnt;i++)
//			cout<<g[i].x<<" ";
		for(int i=1;i<=cnt;i++)
			if((cnt2<n/2||g[i].x<=0)&&(!vis[g[i].id]))
			{
				if(g[i].l==2&&cnt3<n/2)
					ans-=g[i].x,cnt2++,cnt3++,vis[g[i].id]=1;
				else if(g[i].l==3&&cnt4<n/2)
					ans-=g[i].x,cnt2++,cnt4++,vis[g[i].id]=1;
			}
		sum=max(ans,sum);
		cnt=0,ans=0,cnt2=0,cnt3=0,cnt4=0;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
//			cin>>e[i].a>>e[i].b>>e[i].c;
			g[++cnt].x=e[i].c-e[i].a,g[cnt].id=i,g[cnt].l=2;
			g[++cnt].x=e[i].c-e[i].b,g[cnt].id=i,g[cnt].l=3;
			ans+=e[i].c;
		}
//		cout<<ans<<"\n";
		sort(g+1,g+cnt+1,cmp);
//		for(int i=1;i<=cnt;i++)
//			cout<<g[i].x<<" ";
		for(int i=1;i<=cnt;i++)
			if((cnt2<n/2||g[i].x<=0)&&(!vis[g[i].id]))
			{
				if(g[i].l==2&&cnt3<n/2)
					ans-=g[i].x,cnt2++,cnt3++,vis[g[i].id]=1;
				else if(g[i].l==3&&cnt4<n/2)
					ans-=g[i].x,cnt2++,cnt4++,vis[g[i].id]=1;
			}
		sum=max(ans,sum);
		cout<<sum<<"\n";
	}
	return 0;
}
