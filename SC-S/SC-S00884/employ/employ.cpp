#include<bits/stdc++.h>
using namespace std;
#define end '\n'
#define ll long long 
#define int long long 
const int N = 505, mod=998244353;

int a[N];
int arr[N];
int vis[N];
int n,m;
int ans;
string s;
int fact[N];
int c[N][N];

void init(){
	fact[0] = fact[1] = 1;
	for(int i=2;i<=500;i++){
		fact[i] = (1ll * fact[i-1] * i) % mod;
	}
	
	for(int i = 0;i <= 500;i++)
		for(int j = 0;j<=i;j++)
			if(!j)c[i][j]=1;
			else c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
}

void dfs(int now){
	if(now >=n + 1) {
		int cnt = 0;
		
	
		for(int i = 1, res = 0; i <= n;i++){
			if(res >= a[arr[i]] || s[i - 1] == '0') res++;
			else if(s[i - 1] == '1') {
				cnt ++ ;
			}
		}
		if(cnt >= m) ans = (ans + 1) % mod;
		
		return ;
		
	}
	
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			arr[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
	
}
void solve () {
	cin>>n>>m;
	cin >> s;
	
	int num0 = 0;
	for(auto c : s) 
		if(c == '0') num0++;
	for(int i=1;i<=n;i++) {
		cin>>a[i]; 
	}
	
	
	
	if(!num0) {
		sort(a+1,a+n+1);
		int cnt = 0;
		int sum = n;
		for(int i = 1; i <= n;i++) {
			if(cnt >= a[i]) {
				sum --;
			}
		}
		if(sum < m) {
			cout << 0 << endl;
			return ;
		}
		cout << (1ll * c[sum][m] % mod * fact[m] % mod * fact[n-m] % mod + mod) % mod;   // A(n-m, sum -m)   
		return ;
		
	}
	
//	 1-n 的排列 是吧
	dfs(1);
	cout <<ans<<endl;
	
}

signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	int t = 1;
	while(t --) solve();
	
	
	return 0;
}
