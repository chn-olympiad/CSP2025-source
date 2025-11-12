include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct node{
	int a, b, mon;
}a[1000005];
int c[15], d[15][1000005];
bool cmp(node x, node y){
	return x.mon < y.mon;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> a[i].a >> a[i].b >> a[i].mon ;
	bool flagc = true;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i]) flagc = false;
		for(int j= 1;j <= n;j++)
			cin >> d[i][j];
	}
	if(k == 0){
		int ans = 0;
		sort(a + 1, a + m + 1, cmp);
		for(int i = 1;i <= n-1;i++){
			ans += a[i].mon;
		}
		cout << ans << endl;
	}
	return 0;
}