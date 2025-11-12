#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int T,n,vis[100005],p[8],a[8][100005],c[8][100005],bm,id;
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(vis,0,sizeof vis);
		memset(p,0,sizeof p);
		ans=0;
		priority_queue<pair<int,pair<int,int> > > q;
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[1][i]=read(),a[2][i]=read(),a[3][i]=read();
			c[1][i]=a[1][i]-max(a[2][i],a[3][i]);
			c[2][i]=a[2][i]-max(a[1][i],a[3][i]);
			c[3][i]=a[3][i]-max(a[1][i],a[2][i]);
			q.push(make_pair(c[1][i],make_pair(i,1)));
			q.push(make_pair(c[2][i],make_pair(i,2)));
			q.push(make_pair(c[3][i],make_pair(i,3)));
		}
		for(int i=1;i<=n;i++)
		{
			while(vis[q.top().second.first]) q.pop();
			while(p[q.top().second.second]>=n/2) q.pop();
			bm=q.top().second.second;
			id=q.top().second.first;
			ans+=a[bm][id];
			vis[id]=1,p[bm]++;
		}
		write(ans),putchar('\n');
	}
	return 0;
}
