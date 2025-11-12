#include<bits/stdc++.h>
#define fileio(nam) \
	freopen(nam".in","r",stdin); \
	freopen(nam".out","w",stdout)
#define ct(x) \
	ios::sync_with_stdio(x); \
	cin.tie(x),cout.tie(x)

using namespace std;

//#define int long long

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define fi first
#define se second

const int mod = 998244353;
const int N = 567;
int n,m;
char s[N];
int c[N];
int dp[(1<<18)+5][2][20];
vector<int> R[N];
inline int ppcnt(int x) {
	int cnt=0;
	while(x){if(x&1)cnt++;x>>=1;}
	return cnt;
}
inline int ftmod(int x) {
	if(x>=mod)return x-mod;
	return x;
}
void gt_ry() {
	if(n==m) {
		for(int i=1;i<=n;i++) {
			if(c[i]==0) {
				cout<<0<<'\n';
				return;
			}
			if(s[i]=='0') {
				cout<<0<<'\n';
			}
		}
		ll ans=1;
		for(int i=1;i<=n;i++) 
			ans=(ans*i)%((ll)mod);
		cout<<ans<<'\n';
		return;
	}
	cout<<0<<'\n';
}
signed main() {
	fileio("employ");
	ct(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n>18) {
		gt_ry();
		return 0;
	}
	for(int st=0;st<(1<<n);st++) 
		R[ppcnt(st)].push_back(st);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++) {
		bool now=i&1; bool pre=now^1;
		for(int st:R[i-1]) {
			for(int j=0;j<i;j++) {
				for(int p=1;p<=n;p++) {
					if((1<<p-1)&st) {
						continue;
					}
					if(s[i]=='0'||c[p]<=j) {
						dp[(1<<p-1)|st][now][j+1]+=dp[st][pre][j];
						dp[(1<<p-1)|st][now][j+1]=ftmod(dp[(1<<p-1)|st][now][j+1]);
					} else {
						dp[(1<<p-1)|st][now][j]+=dp[st][pre][j];
						dp[(1<<p-1)|st][now][j]=ftmod(dp[(1<<p-1)|st][now][j]);
					}
				}
				dp[st][pre][j]=0;
			}
		}
	}
	ll answer=0;
	for(int i=0;i<=n-m;i++) {
		answer+=dp[(1<<n)-1][n&1][i];
	}
	cout<<answer%mod;
	return 0;
}
