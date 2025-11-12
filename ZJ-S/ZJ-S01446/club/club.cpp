#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100][5],aa[100100],ab[100100],ac[100100];
struct node
{
	int id,ch,mk;
}x[100100];
bool cmp(node q,node w)
{
	return q.ch<w.ch;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) aa[++cnt1]=i;
			else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]) ab[++cnt2]=i;
			else ac[++cnt3]=i;
		}
		int t=n/2;
		if(cnt1<=t&&cnt2<=t&&cnt3<=t)
		{
			long long ans=0;
			for(int i=1;i<=cnt1;i++) ans+=a[aa[i]][1];
			for(int i=1;i<=cnt2;i++) ans+=a[ab[i]][2];
			for(int i=1;i<=cnt3;i++) ans+=a[ac[i]][3];
			cout<<ans<<"\n";
			continue;
		}
		if(cnt1>t)
		{
			for(int i=1;i<=cnt1;i++)
			{
				x[i].id=aa[i];
				if(a[aa[i]][2]>a[aa[i]][3])
				{
					x[i].ch=a[aa[i]][1]-a[aa[i]][2];
					x[i].mk=2;
				}
				else
				{
					x[i].ch=a[aa[i]][1]-a[aa[i]][3];
					x[i].mk=3;			
				}
			}
			sort(x+1,x+cnt1+1,cmp);
			int ed=cnt1-t;
			long long ans=0;
			for(int i=1;i<=ed;i++) ans+=a[x[i].id][x[i].mk];
			for(int i=ed+1;i<=cnt1;i++) ans+=a[x[i].id][1];
			for(int i=1;i<=cnt2;i++) ans+=a[ab[i]][2];
			for(int i=1;i<=cnt3;i++) ans+=a[ac[i]][3];
			cout<<ans<<"\n";
			continue;
		}
		if(cnt2>t)
		{
			for(int i=1;i<=cnt2;i++)
			{
				x[i].id=ab[i];
				if(a[ab[i]][1]>a[ab[i]][3])
				{
					x[i].ch=a[ab[i]][2]-a[ab[i]][1];
					x[i].mk=1;
				}
				else
				{
					x[i].ch=a[ab[i]][2]-a[ab[i]][3];
					x[i].mk=3;			
				}
			}
			sort(x+1,x+cnt2+1,cmp);
			int ed=cnt2-t;
			long long ans=0;
			for(int i=1;i<=ed;i++) ans+=a[x[i].id][x[i].mk];
			for(int i=ed+1;i<=cnt2;i++) ans+=a[x[i].id][2];
			for(int i=1;i<=cnt1;i++) ans+=a[aa[i]][1];
			for(int i=1;i<=cnt3;i++) ans+=a[ac[i]][3];
			cout<<ans<<"\n";
			continue;
		}
		if(cnt3>t)
		{
			for(int i=1;i<=cnt3;i++)
			{
				x[i].id=ac[i];
				if(a[ac[i]][1]>a[ac[i]][2])
				{
					x[i].ch=a[ac[i]][3]-a[ac[i]][1];
					x[i].mk=1;
				}
				else
				{
					x[i].ch=a[ac[i]][3]-a[ac[i]][2];
					x[i].mk=2;			
				}
			}
			sort(x+1,x+cnt3+1,cmp);
			int ed=cnt3-t;
			long long ans=0;
			for(int i=1;i<=ed;i++) ans+=a[x[i].id][x[i].mk];
			for(int i=ed+1;i<=cnt3;i++) ans+=a[x[i].id][3];
			for(int i=1;i<=cnt2;i++) ans+=a[ab[i]][2];
			for(int i=1;i<=cnt1;i++) ans+=a[aa[i]][1];
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}