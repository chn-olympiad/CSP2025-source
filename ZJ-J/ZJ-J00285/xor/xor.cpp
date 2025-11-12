#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k, a[N], sum[N], cnt, ans;
map < int, int > mp;
struct node{
	int l, r;
} p[N];
bool cmp(node x, node y){
	if(x.r != y.r) return x.r < y.r;
	return x.l > y.l;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	for(int i = n; i >= 1; i--){
		mp[sum[i]] = i;
		if(mp.count(sum[i-1] ^ k)){
			++cnt;
			p[cnt].l = i;
			p[cnt].r = mp[sum[i-1] ^ k];
		}
	}
	sort(p + 1, p + cnt + 1, cmp);
	int t = 1;
	for(int i = 1; i <= cnt; i++){
		if(p[i].l >= t){
			ans++;
			t = p[i].r+1;
		}
	}
	cout << ans << "\n";
	return 0;
}