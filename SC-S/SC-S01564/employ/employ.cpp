#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
constexpr int N = 505;
constexpr LL MOD = 998244353;
int n,m;
int s[N],c[N];

namespace BF{
	int cnt0,cnt1;
	inline void main(){
		LL ans=0;
		vector<int> perm(n);
		iota(perm.begin(),perm.end(),1);
		do{
			cnt0=0,cnt1=0;
			for(int i=1; i<=n; i++){
				int t = perm[i-1];
				if(cnt0 >= c[t]) {cnt0++;continue;}
				if(s[i]==1){
					cnt1++;
				}
				else{
					cnt0++;
				}
			}
			ans += (cnt1>=m);
		}while(next_permutation(perm.begin(), perm.end()));
		printf("%lld\n", ans);
		return ;
	}
}

namespace BF2{
	LL dp[1<<18][20]; 
	inline void red(LL &x){
		x = (x>=MOD) ? x-MOD : x;
		return ;
	}
	inline void main(){
		// dp[S][i]表示前面面试的集合是S，有i个人被拒绝的方案数量 
		dp[0][0]=1;
		for(int S=0; S<(1<<n); S++){
			int pre = __builtin_popcount(S);
			for(int i=1; i<=n; i++){  // 枚举这回谁去 
				if((S>>i-1)&1)continue;
				for(int j=0; j<=pre; j++){  // 枚举前面有多少个人被拒绝 
					int T = S | (1<<i-1);
					int refuse = j >= c[i] || s[pre+1]==0;
					red(dp[T][j+refuse] += dp[S][j]);
				}
			}
		}
		LL ans=0;
		for(int refu=0; refu<=n-m; refu++){
			ans += dp[(1<<n)-1][refu];
		}
		printf("%lld\n", ans);
		return ;
	}
}

namespace ALL1{
	inline void main(){
		// 0会导致 
		LL ans=1;
		for(int i=1; i<=n; i++) ans=(ans*i)%MOD;
		printf("%lld\n", ans); 
		return ;
	}
}

namespace NM{
	inline void main(){
		// 不能有任何人被拒绝
		// 不能有0，不能有人的c=0
		// 如果有，方案数=0，否则=全排列 
		LL ans=1;
		for(int i=1; i<=n; i++) ans=(ans*i)%MOD;
		for(int i=1; i<=n; i++){
			if(s[i]==0) ans=0;
			if(c[i]==0) ans=0; 
		}
		printf("%lld\n", ans); 
		return;
	}
}

signed main(){
	fastio;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool all1=1,nm=(n==m);
	for(int i=1; i<=n; i++){
		char ch; cin >> ch;
		s[i] = ch-'0';
		if(s[i]==0) all1=0;
	}
	for(int i=1; i<=n; i++) cin >> c[i];
	if(n<=10) BF::main();
	else if(n<=18) BF2::main();
	else if(nm) NM::main();
	else if(all1) ALL1::main();
//	BF2::main();
	return 0;
}