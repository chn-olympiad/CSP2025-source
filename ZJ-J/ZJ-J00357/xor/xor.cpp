#include <bits/stdc++.h>
using namespace std;

// 1-12

int n, k;
int a[500010];
int pre[500010];
int cnt = 0;
bool A = true;
bool B = true;
bool C = true;

struct q{
	int l, r;
};

inline bool check(int l, int r){
	return pre[r] ^ pre[l - 1] == k;
}

bool cmp(q x, q y){
	return x.l < y.l;
}

vector<q> v;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != 1) A = false;
		if (a[i] != 1 && a[i] != 0) B = false;
		if (a[i] >= 256) C = false;
	}
	if (A){
		if (k == 0){
			cout << n / 2;
		} else {
			cout << n;
		}
		return 0;
	}
	pre[0] = 0;
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] ^ a[i];
	}
	
	int ma = 0;
	
	for (int l = ma; l <= n; l++){ // O(n^2)
		for (int r = l; r <= n; r++){
			if (check(l, r)){
				q tmp;
				tmp.l = l;
				tmp.r = r;
				v.push_back(tmp);
			}
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	int ans = v.size();
	int b = v[0].r;
	for (int i = 1; i < v.size(); i++){
		if (v[i].l <= b){
			ans--;
		} else {
			b = v[i].r;
		}
	}
	cout << ans;
	return 0;
}
