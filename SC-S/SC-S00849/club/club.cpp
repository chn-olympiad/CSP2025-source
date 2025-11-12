#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+10,inf=1e18,mod=1e9+7;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
} 
int n,a[maxn][4],cnt[4],ans,t[4][maxn];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read(),ans=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=3;j++) a[i][j]=read();
			int mxid=0,mx=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>a[i][mxid]) mxid=j;
			}
			for(int j=1;j<=3;j++)
			{
				if(j!=mxid) mx=max(mx,a[i][j]);
			}
			t[mxid][++cnt[mxid]]=a[i][mxid]-mx,ans+=a[i][mxid];
		}
		if(cnt[1]<=n/2 and cnt[2]<=n/2 and cnt[3]<=n/2)
		{
			cout<<ans<<" "<<1<<'\n';
			continue;
		}
		int id=1*(cnt[1]>n/2)+2*(cnt[2]>n/2)+3*(cnt[3]>n/2);
		sort(t[id]+1,t[id]+cnt[id]+1);
		for(int i=1;i<=cnt[id]-n/2;i++) ans-=t[id][i];
		cout<<ans<<'\n';
	}
	return 0;
}