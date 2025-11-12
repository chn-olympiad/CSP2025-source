#include<bits/stdc++.h>
using namespace std;
#define il inline
#define getbit(x,y) (((x)>>(y))&1)
#define lowbit(x) ((x)&(-x))
#define mkp make_pair
#define fi first
#define se second
#define N 100005
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
typedef unsigned uint;
il ll read() {
	ll x=0;bool f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=0;c=getchar();}
	while(isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?x:-x;
}
int n,a[N][4],cnt[3];
priority_queue<pii,vector<pii>,less<pii> > pq;
il void mian() {
	n=read();
	ll ans=0;
	for(int i=1;i<=n;++i) {
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read(),a[i][3]=-1;
		int pos=0,sep=3;
		for(int j=1;j<=2;++j) {
			if(a[i][j]>a[i][pos]) sep=pos,pos=j;
			else if(a[i][j]>a[i][sep]) sep=j;
		}
		ans+=a[i][pos];
		pq.push(mkp(a[i][sep]-a[i][pos],pos));
		++cnt[pos];
	}
	int tot=max({cnt[0],cnt[1],cnt[2]});
	while(tot>n/2) {
		pii now=pq.top();pq.pop();
		if(cnt[now.se]<=n/2) continue;
		--tot,--cnt[now.se];
		ans+=now.fi;
	}
	printf("%lld\n",ans);
}
il void clean() {
	while(!pq.empty()) pq.pop();
	cnt[0]=cnt[1]=cnt[2]=0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--) {
		mian();
		clean();
	}
	return 0;
}

