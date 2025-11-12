#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 205;
const ll inf = 1e12;
int n;
ll f[N][N / 2][N / 2];
ll tp[100005];
bool fl;
struct node{
	ll a[4];
}x[100005];
void solve(){
	cin >> n;
	fl = 1;
	for(int i = 1;i <= n;++ i){
		cin >> x[i].a[1] >> x[i].a[2] >> x[i].a[3];
		fl &= ((x[i].a[2] == 0) && (x[i].a[3] == 0));
	}
	ll ans = 0;
	if(fl){
		for(int i = 1;i <= n;++ i) tp[i] = x[i].a[1];
		sort(tp + 1,tp + 1 + n);
		for(int i = n;i >= n / 2 + 1;-- i) ans += tp[i];
		cout << ans << endl;
		return;
	}
	
	for(int i = 0;i <= n;++ i)
		for(int j = 0;j <= n / 2;++ j)
			for(int k = 0;k <= n / 2;++ k)
				f[i][j][k] = -inf;
	f[0][0][0] = 0;
	for(int i = 1;i <= n;++ i)
		for(int j = 0;j <= min(i,n / 2);++ j)
			for(int k = 0;(k <= min(i,n / 2)) && (k + j <= i);++ k){
				if(j) f[i][j][k] = max(f[i][j][k],f[i - 1][j - 1][k] + x[i].a[1]);
				if(k) f[i][j][k] = max(f[i][j][k],f[i - 1][j][k - 1] + x[i].a[2]);
				if(i - j - k <= n / 2 && i - j - k >= 1)
					f[i][j][k] = max(f[i][j][k],f[i - 1][j][k] + x[i].a[3]);
				if(i == n && i - j - k <= n / 2) ans = max(ans,f[i][j][k]);
			}
//	cout << f[3][0][2] << endl;
	cout << ans << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios :: sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;
	cin >> t;
	while(t --) solve();
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

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