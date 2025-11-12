/*by bsjsaikou10 memoria*/ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
int n;
int a[MAXN][4],b[MAXN][4];
typedef struct Node{
	int x,d,k1,k2;
}Node;
bool cmp(Node n1,Node n2){
	return n1.d > n2.d;
}
Node c[MAXN],d1[MAXN],d2[MAXN];
int cnt[MAXN];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		a[i][1] = a[i][2] = a[i][3] = 0;
		b[i][1] = b[i][2] = b[i][3] = 0;
		c[i].x = c[i].d = c[i].k1 = c[i].k2 = 0;
		d1[i].x = d1[i].d = d1[i].k1 = d1[i].k2 = 0;
		d2[i].x = d2[i].d = d2[i].k1 = d2[i].k2 = 0;
		cnt[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		b[i][1] = a[i][1],b[i][2] = a[i][2],b[i][3] = a[i][3];
		sort(a[i] + 1,a[i] + 4,greater<int>());
		//cout << "1: " << a[i][1] << endl;
		c[i].d = a[i][1] - a[i][2];
		c[i].k1 = a[i][1],c[i].k2 = a[i][2];
		if(b[i][1] == a[i][1]){
			c[i].x = 1;
			cnt[1]++;
			continue;
		}
		if(b[i][2] == a[i][1]){
			c[i].x = 2;
			cnt[2]++;
			continue;
		}
		cnt[3]++;
		c[i].x = 3;
	}
	int flag = 0,pos = 0;
	for(int i = 1; i <= 3; i++){
		if(cnt[i] > n / 2){
			flag = 1;
			pos = i;
		}
	}
	int ans = 0;
	if(!flag){
		for(int i = 1; i <= n; i++){
			ans += a[i][1];
		}
		cout << ans << endl;
		return;
	}
	int ct = 0,ct2 = 0; 
	for(int i = 1; i <= n; i++){
		if(c[i].x == pos){
			d1[++ct] = c[i];
		}
		else{
			d2[++ct2] = c[i];
		}
	}
	sort(d1 + 1,d1 + 1 + ct,cmp);
	for(int i = 1; i <= n / 2; i++){
		ans += d1[i].k1;
	}
	for(int i = n / 2 + 1; i <= ct; i++){
		ans += d1[i].k2;
	}
	for(int i = 1; i <= ct2; i++){
		ans += d2[i].k1;
	}
	cout << ans << endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
} 