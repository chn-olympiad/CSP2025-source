#include<bits/stdc++.h>
using namespace std;

int n, k, id, ans;
int a[500005];
int vis[100005];
struct OK{
	int l, r;
}ok[500005];

bool cmp(OK x, OK y){
	if(x.r != y.r) return x.r < y.r;
	else return x.l < y.l;
}

void in(int l, int r){
	ok[++id].l = l;
	ok[id].r = r;
}

bool f(int l, int r){
	for(int i = l; i <= r; i++){
		if(vis[i] == 1) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int cnt = a[i];
		if(cnt == k) in(i, i);
		for(int j = i + 1; j <= n; j++){
			cnt ^= a[j];
			if(cnt == k) in(i, j);
		}
	}
	
	sort(ok + 1, ok + 1 + id, cmp);
	for(int i = 1; i <= id; i++){
		if(f(ok[i].l, ok[i].r)) continue;
		for(int j = ok[i].l; j <= ok[i].r; j++) vis[j] = 1;
		ans++;
	}
	
	cout << ans;
	
	return 0;
}