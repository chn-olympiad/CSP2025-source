#include<bits/stdc++.h>
#define int long long
#define double long double
#define sqrt sqrtl
#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define popcount __builtin_popcountll
#define parity __builtin_parityll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
//#define CONSTRUCTOR
#ifdef CONSTRUCTOR
#define push_back emplace_back
#define pop_back emplace_back
#define insert emplace
#endif
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int qpow(int a,int n){int res=1;while(n){if(n&1){res=res*a;}a=a*a;n>>=1;}return res;}
int qpow(int a,int n,int p){int res=1;while(n){if(n&1){res=res*a%p;}a=a*a%p;n>>=1;}return res;}
int gcd(int a,int b){if(!b){return a;}return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int lowbit(int x){return x&(-x);}
const int N=1e5+99;
int n,a[N][5];
int get(int a,int b,int c){
	if(a>=b&&b>=c){
		return b;
	}else if(a>=c&&c>=b){
		return c;
	}else if(b>=a&&a>=c){
		return a;
	}else if(b>=c&&c>=a){
		return c;
	}else if(c>=a&&a>=b){
		return a;
	}else{
		return b;
	}
}
int ans;
int cnt[5];
void dfs(int stp,int sum){
	if(stp>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			dfs(stp+1,sum+a[stp][i]);
			cnt[i]--;
		}
	}
}
void solve(){
	cin>>n;
	ans=0;
	bool flg=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]||a[i][3]){
			flg=1;
		}
	}
	if(n<=10){
		dfs(1,0);
		cout<<ans<<endl;
		return;
	}
	if(flg){
		int res=0;
		vector<int>v;
		v.push_back(0);
		for(int i=1;i<=n;i++){
			v.push_back(a[i][1]);
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int i=1;i<=n/2;i++){
			res+=v[i];
		}
		cout<<res<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fst;
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

