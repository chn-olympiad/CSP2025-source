#include<bits/stdc++.h>
using namespace std;
int n, k, a[200010], len, e, res;
int b[1010][1010];
struct point{
	int l, r;
};
point ans[1000010];
bool cmp(point x, point y){
	if(x.r != y.r) return x.r < y.r;
	return x.l < y.l;
}
int main(){
	freopen("xor.in", "w", stdin);
	freopen("xor.out", "r", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) b[i][i] = a[i];
	for(int l = 1; l <= n; l++){
		for(int r = l + 1; r <= n; r++) b[l][r] = b[l][r - 1] ^ a[r];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(b[i][j] == k) ans[++len].l = i, ans[len].r = j;
		}
	}
	sort(ans + 1, ans + len + 1, cmp);
	for(int i = 1; i <= len; i++){
		if(ans[i].l > e) e = ans[i].r, res++;
	}
	cout << res;
	return 0;
}
