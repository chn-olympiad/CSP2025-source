#include<bits/stdc++.h>
#define rint register int
using namespace std;
const int N=100005;
int T,n,ans,cnt[5],a[N][5],id[N],d[5];
priority_queue<pair<int,int> >s[5];
void read(rint &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	for(;T;T--)
	{
		read(n);
		ans=0;
		memset(id,0,sizeof id);
		for(rint i=1;i<=3;i++) while(s[i].size()) s[i].pop();
		for(rint i=1;i<=n;i++)
		{
			for(rint j=1;j<=3;j++)
			{
				read(a[i][j]);
				if(!id[i]||a[i][j]>a[i][id[i]]) id[i]=j;
			}
			if(id[i]==1) s[1].push({max(a[i][2],a[i][3])-a[i][1],i});
			if(id[i]==2) s[2].push({max(a[i][1],a[i][3])-a[i][2],i});
			if(id[i]==3) s[3].push({max(a[i][1],a[i][2])-a[i][3],i});
		}
		while(s[1].size()>n/2)
		{
			int x=s[1].top().second;
			s[1].pop();
			ans+=max(a[x][3],a[x][2]);
		}
		while(s[2].size()>n/2)
		{
			int x=s[2].top().second;
			s[2].pop();
			ans+=max(a[x][3],a[x][1]);
		}
		while(s[3].size()>n/2)
		{
			int x=s[3].top().second;
			s[3].pop();
			ans+=max(a[x][2],a[x][1]);
		}
		while(s[1].size())
		{
			int x=s[1].top().second;
			s[1].pop();
			ans+=a[x][1];
		}
		while(s[2].size())
		{
			int x=s[2].top().second;
			s[2].pop();
			ans+=a[x][2];
		}
		while(s[3].size())
		{
			int x=s[3].top().second;
			s[3].pop();
			ans+=a[x][3];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
