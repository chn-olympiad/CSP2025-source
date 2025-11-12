#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define mkp make_pair
#define fst first
#define scd second
using namespace std;
const int N = 300+10;
const int NN = 1e5+10;
const int INF = 0x3f3f3f3f3f3f3f3f;
int t, n, m, a[NN][5], b[5], f[N][N], f3[NN], ans;
bool vis[NN];

void init(){
	memset(b, 0, sizeof b);
	for(int i=1;i<=n;i++) vis[i] = 0;
	ans = 0, m = n>>1;
	return ;
}

void subtask1(){
	memset(f, 0xcf, sizeof f);
	f[0][0] = ans;
	for(int i=1;i<=n;i++){
		for(int j=min(n+1, m);j>=0;j--){
			for(int k=min(n+1, m);k>=0;k--){
				if(k) f[j][k] = max(f[j][k], f[j][k-1] + (a[i][3] - a[i][1]));
				if(j) f[j][k] = max(f[j][k], f[j-1][k] + (a[i][2] - a[i][1]));
			}
		}
	}
	ans = -INF;
	for(int j=0;j<=m;j++){
		for(int k=0;k<=m;k++){
			if(n-j-k > m) continue;
			ans = max(ans, f[j][k]);
		}
	}
	cout<<ans<<'\n';
	return ;
}

void subtask2(){
	vector<PII> v;
	for(int i=1;i<=n;i++){
		v.push_back({a[i][1], i});
	}
	sort(v.begin(), v.end());
	for(int i=1;i<=m;i++){
		int p = v[i-1].scd;
		ans -= a[p][1];
	}
	cout<<ans<<'\n';
	return ;
}

void subtask3(){
	memset(f3, 0xcf, sizeof f3);
	f3[0] = ans;
	for(int i=1;i<=n;i++){
		for(int j=min(n+1, m);j>=0;j--){
			f3[j] = max(f3[j], f3[j-1] + (a[i][2] - a[i][1]));
		}
	}
	cout<<f[m]<<'\n';
	return ;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag2 = 1, flag3 = 1;
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ans += a[i][1];
		}
		if(n <= 300){
			subtask1();
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i][2]){
					flag2 = 0;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i][3]){
					flag3 = 0;
					break;
				}
			}
			if(flag2 && flag3){
				subtask2();
			}
			else if(flag3){
				subtask3();
			}
			else cout<<"No\n";
			continue;
		}
	}
	return 0;
}
