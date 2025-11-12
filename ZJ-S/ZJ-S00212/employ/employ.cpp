#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l);i<=(r);++i)
#define per(i, r, l) for(int i(r);i>=(l);--i)
using namespace std;

const int N = 510;
const int mod = 998244353;
int n,m;
char s[N];
int c[N];

inline int add(int x,int y){ return x + y >= mod ? x + y - mod : x + y; }
inline void toadd(int &x,int y){ x = add(x, y); }

namespace sub1{
	int p[15];
	void solve(){
		rep(i, 1, n)p[i] = i;
		int ans = 0;
		do{
			int pre = 0;
			rep(i, 1, n)
				if(pre >= c[p[i]] || s[i] == '0')++pre;
			if(n-pre >= m)++ans;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
}

namespace sub2{
	int f[19][1 << 18][19];
	vector<int> S[20];
	void solve(){
		f[0][0][0] = 1;
		rep(st, 0, (1 << n)-1)S[__builtin_popcount(st)].emplace_back(st);
		rep(i, 0, n-1){
			for(int st : S[i]){
				rep(j, 0, i)if(f[i][st][j]){
					int rst = ((1<<n)-1)^st;
					while(rst){
						int tmp = rst & (-rst);
						rst ^= tmp;
						int k = __lg(tmp)+1;
						if(j >= c[k] || s[i+1] == '0')toadd(f[i+1][st|tmp][j+1], f[i][st][j]);
						else toadd(f[i+1][st|tmp][j], f[i][st][j]);
					}
				}
			}
		}
		int ans = 0;
		rep(i, 0, n-m)toadd(ans, f[n][(1<<n)-1][i]);
		printf("%d\n",ans);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	rep(i, 1, n)scanf("%d",&c[i]);
	if(n <= 10)
		sub1::solve();
	else if(n <= 18)
		sub2::solve();
	return 0;
}