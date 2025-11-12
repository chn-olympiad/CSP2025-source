#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l);i<=(r);++i)
#define per(i, r, l) for(int i(r);i>=(l);--i)
using namespace std;

const int N = 1e5 + 10;
int n,a[N][3];

namespace sub1{
	const int inf = 0x3f3f3f3f;
	int f[210][210][210];
	inline void upd(int &x,int y){
		(x < y) && (x = y);
	}
	void solve(){
		memset(f, -0x3f, sizeof f);
		f[0][0][0] = 0;
		rep(i, 0, n-1){
			rep(j, 0, i)for(int k = 0;k+j<=i;++k)if(f[i][j][k] > -inf){
				upd(f[i+1][j+1][k], f[i][j][k]+a[i+1][0]);
				upd(f[i+1][j][k+1], f[i][j][k]+a[i+1][1]);
				upd(f[i+1][j][k], f[i][j][k]+a[i+1][2]);
			}
		}
		int ans = -inf;
		rep(j, 0, n/2)for(int k = 0;k+j<=n && k<=n/2;++k){
			int rst = n-j-k;
			if(rst <= n/2)
				upd(ans, f[n][j][k]);
		}
		printf("%d\n",ans);
	}
}

namespace sub2{
	inline bool check(){
		rep(i, 1, n)if(a[i][1] || a[i][2])return false;
		return true;
	}
	int p[N];
	void solve(){
		rep(i, 1, n)p[i] = a[i][0];
		sort(p+1,p+n+1,greater<int>() );
		int ans = 0;
		rep(i, 1, n/2)
			ans += p[i];
		printf("%d\n",ans);
	}
}

////namespace sub3{
////	inline bool check(){
////		rep(i, 1, n)if(a[i][2])return false;
////		return true;
////	}
////	void solve(){
////		priority_queue<int> q;
////		while(!q.empty()){
////			int x = q.top(); q.pop();
////			
////		}
////	}
////}

namespace sub4{
	bool vis[N];
	struct node{
		int x, y, z;
		bool friend operator <(const node &a,const node &b){
			return a.x < b.x;
		}
	};
	void solve(){
		rep(i, 1, n)vis[i] = 0;
		priority_queue<node> q;
		rep(i, 1, n)q.push({a[i][0], 0, i}), q.push({a[i][1], 1, i}), q.push({a[i][2], 2, i});
		int ans = 0;
		int ct[3] = {0, 0, 0};
		while(!q.empty()){
			int x = q.top().x, y = q.top().y, z = q.top().z; q.pop();
//			cerr << y << ' ' << z << endl;
			if(vis[z])continue;
			if(ct[y] == n/2)continue;
			++ct[y], ans += x, vis[z] = 1;
		}
		printf("%d\n",ans);
	}
}

void solve(){
	scanf("%d",&n);
	rep(i, 1, n)
		rep(o, 0, 2)scanf("%d",&a[i][o]);
	if(n <= 200)
		sub1::solve();
	else if(sub2::check())
		sub2::solve();
	else
		sub4::solve();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)	
		solve();
	return 0;
}