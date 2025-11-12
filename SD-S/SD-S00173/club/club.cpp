#include<bits/stdc++.h>
#define int long long
#define R(x) x=read()
using namespace std;
inline int read() {
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x*y;
}
const int N=100005;
int T,n,ans,a[3][N],cnt[3],bel[N];
priority_queue<int>q;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	R(T);
	while(T--) {
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		while(!q.empty())q.pop();
		R(n);
		for(int i=1; i<=n; ++i) {
			R(a[0][i]),R(a[1][i]),R(a[2][i]);
			int mx=max(a[0][i],max(a[1][i],a[2][i]));
			if(mx==a[0][i])++cnt[0],bel[i]=0;
			else if(mx==a[1][i])++cnt[1],bel[i]=1;
			else ++cnt[2],bel[i]=2;
			ans+=mx;
		}
		int mid=n/2,pos=-1;
		if(cnt[0]>mid) pos=0;
		if(cnt[1]>mid) pos=1;
		if(cnt[2]>mid) pos=2;
		if(pos==-1) {
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1; i<=n; ++i) {
			if(bel[i]==pos) {
				int mx=-0x3f3f3f3f3f3f3f3f;
				for(int j=0; j<3; ++j) {
					if(j!=pos) mx=max(mx,a[j][i]-a[pos][i]);
				}
				q.push(mx);
			}
		}
		for(int i=1; i<=cnt[pos]-mid; ++i) {
			ans+=q.top();
			q.pop();
		}
		cout<<ans<<"\n";
	}

	return 0;
}

