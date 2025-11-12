#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[111111][10];
struct Node{
	int x,y;
}mi[111111];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		int cnt[10]={};
		for(int i=1;i<=n;i++)
		{
			mi[i].x=a[i][1]-a[i][2];
			mi[i].y=a[i][1]-a[i][3];
			if(mi[i].x<mi[i].y&&mi[i].x<0) cnt[2]++;
			else if(mi[i].x>0&&mi[i].y>0) cnt[1]++;
			else cnt[3]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=max(a[i][3],max(a[i][1],a[i][2]));
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		if(cnt[1]>n/2)
		{
			int tot=0;
			int ret[111111]={};
			for(int i=1;i<=n;i++) if(mi[i].x>0&&mi[i].y>0)ret[++tot]=min(mi[i].x,mi[i].y);
			sort(ret+1,ret+1+tot);
			for(int i=1;i<=cnt[1]-n/2;i++)ans-=ret[i];
			cout<<ans<<endl;
		}
		else if(cnt[2]>n/2)
		{
			int tot=0;
			int ret[111111]={};
			for(int i=1;i<=n;i++) if(mi[i].x<mi[i].y&&mi[i].x<0)ret[++tot]=min(abs(mi[i].x),abs(mi[i].x-mi[i].y));
			sort(ret+1,ret+1+tot);
			for(int i=1;i<=cnt[2]-n/2;i++)ans-=ret[i];
			cout<<ans<<endl;
		}
		else
		{
			int ret[111111]={};
			int tot=0;
			for(int i=1;i<=n;i++) if(mi[i].y<=0&&mi[i].y<=mi[i].x)ret[++tot]=min(abs(mi[i].y),abs(mi[i].y-mi[i].x));
			sort(ret+1,ret+1+tot);
			for(int i=1;i<=cnt[3]-n/2;i++) ans-=ret[i];
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			a[i][1]=0,a[i][2]=0,a[i][3]=0;
			mi[i].x=0,mi[i].y=0;
		}
	}
	return 0;
}

