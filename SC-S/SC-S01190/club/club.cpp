#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+10;

int n,m;
int cnt[5];
struct node {
	int b[4],maxx;
}a[N];
inline void Clear() {
	rep(i,1,3) cnt[i]=0;
	rep(i,1,n) a[i].maxx=0;
	return ;
}
inline void solve() {
	cin>>n;
	rep(i,1,n) rep(j,1,3) cin>>a[i].b[j],a[i].maxx=max(a[i].maxx,a[i].b[j]);
	sort(a+1,a+n+1,[](node p,node q){return p.maxx>q.maxx;});
	int res=0;
	rep(i,1,n) {
		vector<int> pos;
		rep(j,1,3) if (a[i].b[j]==a[i].maxx) pos.eb(j);
		int minn=2e9,x=0;
		for (auto v : pos) {
			if (cnt[v]<minn) {
				minn=cnt[v];
				x=v;
			}
		}
		if (minn==n/2) {
			int secmax=0;
			pos.clear();
			rep(j,1,3) {
				if (a[i].b[j]==a[i].maxx) continue;
				if (secmax==a[i].b[j]) pos.eb(j);
				if (secmax<a[i].b[j]) {
					secmax=a[i].b[j];
					x=j;
					pos.clear();
					pos.eb(j);
				}
			}
			res+=secmax;
			minn=2e9;
			for (auto v : pos) {
				if (cnt[v]<minn) {
					minn=cnt[v];
					x=v;
				}
			}
			cnt[x]++;
		} else cnt[x]++,res+=a[i].maxx;
	}
	cout<<res<<endl;
	return Clear();
}
namespace Baoli {
	const int M=200+10;
	int f[2][M/2][M/2][M/2];
	inline void subA() {
		int res=0;
		rep(i,1,n) res+=a[i].b[1];
		cout<<res<<endl;
		return ;
	}
	inline void subB() {
		int res=0,cnt1=0,cnt2=0;
		sort(a+1,a+n+1,[](node x,node y){return abs(x.b[1]-x.b[2])>abs(y.b[1]-y.b[2]);});
		rep(i,1,n) {
			if (cnt1==n/2) {
				res+=a[i].b[2];
				continue;
			} 
			if (cnt2==n/2) {
				res+=a[i].b[1];
				continue;
			}
			if (a[i].b[1]<a[i].b[2]) {
				res+=a[i].b[2];
				cnt2++;
			} else {
				res+=a[i].b[1];
				cnt1++;
			}
		}
		cout<<res<<endl;
		return ;
	}
	inline void solve() {
		cin>>n;
		bool A=1,B=1;
		rep(i,1,n) rep(j,1,3) {
			cin>>a[i].b[j];
			if (j==2 or j==3) A&=(a[i].b[j]==0);
			if (j==3) B&=(a[i].b[j]==0);
		}
		if (A) return subA();
		if (B) return subB();
		const int up=n/2;
		rep(i,1,n) rep(cnt1,0,up) rep(cnt2,0,up) {
			int cnt3=i-cnt1-cnt2;
			if (cnt3<0) continue;
			f[i&1][cnt1][cnt2][cnt3]=0;
		}
		rep(i,1,n) {
			int now=i&1;
			int lst=now^1;
			rep(j,1,3) {
				rep(cnt1,0,min(i,up)) rep(cnt2,0,min(i,up)) {
					int cnt3=i-cnt1-cnt2;
					if (cnt3<0) continue;
					if (j==1) {
						if (cnt1) f[now][cnt1][cnt2][cnt3]=max(f[now][cnt1][cnt2][cnt3],f[lst][cnt1-1][cnt2][cnt3]+a[i].b[j]);
					}
					if (j==2) {
						if (cnt2) f[now][cnt1][cnt2][cnt3]=max(f[now][cnt1][cnt2][cnt3],f[lst][cnt1][cnt2-1][cnt3]+a[i].b[j]);
					}
					if (j==3) {
						if (cnt3) f[now][cnt1][cnt2][cnt3]=max(f[now][cnt1][cnt2][cnt3],f[lst][cnt1][cnt2][cnt3-1]+a[i].b[j]);
					}
				}
			} 
		}
		int res=0;
		rep(cnt1,0,up) rep(cnt2,0,up) rep(cnt3,0,up) if (cnt1+cnt2+cnt3==n) res=max(res,f[n&1][cnt1][cnt2][cnt3]);
		cout<<res<<"\n";
		return ;
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;cin>>_;
	while (_--) Baoli::solve();
	return 0;
}
/*
可以考虑先贪心选然后调整
还是想一下 DP 吧
设 f[i][j] 表示：
前 i 个数，第 i 个数属于 j 的方案数
可以从哪里转移过来？
按最大贡献排
是不是应该先写一个正确性比较对的东西啊
f[i][cnt1][cnt2][cnt3] : 前 i 个数，第 i 种颜色染了 cnti 个的方案数
f[i]

70 pts
*/