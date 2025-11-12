#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fre {freopen("club.in","r",stdin);freopen("club.out","w",stdout);}
#define pii pair<LL,LL>
LL T,n,cnt[10],ans,a[7][100050];
struct node
{
	LL id,x,fr,se;
	bool operator <(const node &p) const
	{
		return p.x<x;
	}
}p[100500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("club1.in","r",stdin);
	fre;
	cin>>T;
	while(T--)
	{
		cnt[1]=0,cnt[2]=0,cnt[3]=0,ans=0;
		cin>>n;
		for(LL i=1;i<=n;++i)
		{
			LL fg=0;
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if((a[1][i]>=a[2][i])&&(a[1][i]>=a[3][i]))
			{
				if(a[2][i]>a[3][i]) fg=2;
				else fg=3;
				p[i].id=i,p[i].x=(a[1][i]-a[fg][i]),p[i].fr=1,p[i].se=fg;
			}
			else if((a[2][i]>a[1][i])&&(a[2][i]>=a[3][i]))
			{
				if(a[1][i]>a[3][i]) fg=1;
				else fg=3;
				p[i].id=i,p[i].x=(a[2][i]-a[fg][i]),p[i].fr=2,p[i].se=fg;
			}
			else if((a[3][i]>a[2][i])&&(a[3][i]>a[1][i]))
			{
				if(a[2][i]>a[1][i]) fg=2;
				else fg=1;
				p[i].id=i,p[i].x=(a[3][i]-a[fg][i]),p[i].fr=3,p[i].se=fg;
			}
		}
		sort(p+1,p+1+n);
		//cout<<p[1].x<<" "<<p[2].x<<endl;
		for(LL i=1;i<=n;++i)
		{
			LL ff=p[i].fr,ss=p[i].se,idx=p[i].id;
			//cout<<p[i].x<<" "<<idx<<" "<<ff<<" "<<ss<<" "<<ans<<" "<<a[ff][idx]<<endl;
			if(cnt[ff]<n/2) cnt[ff]++,ans+=a[ff][idx];
			else if(cnt[ff]>=n/2) ++cnt[ss],ans+=a[ss][idx];
		}
		cout<<ans<<endl;
		for(LL i=1;i<=n;++i) p[i].fr=p[i].id=p[i].se=p[i].x=0;
	}
	return 0;
}
/*
1 4
1 1 0
2 2 0
3 3 0
4 5 0
*/
