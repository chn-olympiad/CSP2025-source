#include<bits/stdc++.h>
using namespace std;

int n, k, ans, a[500010], b[500010];

struct Info{
	int c, l, id;
	bool operator< (const Info &A) const {
		return l < A.l;
	}
} c[500010];

int main(){
//	freopen("xor6.in", "r", stdin);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int t = 0;
		c[i].id = i;
		for(int j = i; j <= n; j++){
			t ^= a[j];
			if(t == k){
				c[i].c = j;
				c[i].l = (j - i + 1);
				break;
			}
		}
	}
	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++){
		if(c[i].c == 0){
			continue;
		}
		int l = c[i].id, r = c[i].c;
		bool flag = true;
		for(int j = l; j <= r; j++){
			if(b[j]){
				flag = false;
			}
		}
		if(flag){
			for(int j = l; j <= r; j++){
				b[j] = 1;
			}
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
