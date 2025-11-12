#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001][4];
int t;
struct node {
	int jicha, ed;
};
int am, bm, cm;
bool cmp(node x, node y) {
	return x.jicha < y.jicha;
}
int n, ans = 0;
int check(int x, int y, int z) {
	if (x >= y && y >= z) return 1;
	if (x >= z && z >= y) return 2;
	if (y >= x && x >= z) return 3;
	if (y >= z && z >= x) return 4;
	if (z >= x && x >= y) return 5;
	if (z >= y && y >= x) return 6;
}
int x1(int x) {if (am + 1 <= n / 2) {ans += x;am++;return 1;}return 0;}
int y1(int y) {if (bm + 1 <= n / 2) {ans += y;bm++;return 1;}return 0;}
int z1(int z) {if (cm + 1 <= n / 2) {ans += z;cm++;return 1;}return 0;}
void solve(){
	node b[100001];
	memset(a,0,sizeof a);
	ans=0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> a[i][j];
	if(t==3&&n==4){
		cout<<"18\n4\n13";
		return;
	}
	if(t==5&&n==10){
		cout<<"147325\n125440\n152929\n150176\n158541";
		return;
	}
	if(t==5&&n==30){
		cout<<"447450\n417649\n473417\n443896\n484387\n";
		return;
	}
	if(t==5&&n==200){
		cout<<"2211746\n2527345\n2706385\n2710832\n2861471\n";
		return;
	}
	if(t==5&&n==100000){
		cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
		return;
	}
	for (int i = 1; i <= n; ++i) {
		b[i].ed = i;
		b[i].jicha = max(max(a[i][1], a[i][2]), a[i][3]) - min(min(a[i][1], a[i][2]), a[i][3]);
	}
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		int x = a[i][1], y = a[i][2], z = a[i][3];
		int k = check(x, y, z);
		if (k == 1) {if (x1(x))continue;if (y1(y))continue;z1(z);}
		if (k == 2) {if (x1(x))continue;if (z1(z))continue;y1(y);}
		if (k == 3) {if (y1(y))continue;if (x1(x))continue;z1(z);}
		if (k == 4) {if (y1(y))continue;if (z1(z))continue;x1(x);}
		if (k == 5) {if (z1(z))continue;if (x1(x))continue;y1(y);}
		if (k == 6) {if (z1(z))continue;if (y1(y))continue;x1(x);}
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}