#include<bits/stdc++.h>
using namespace std;
int sum[500010];
int ct[500010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[500010];
	int cnt = 0;
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ct[a[i]]++;
		cnt = cnt^a[i];
		sum[i] = cnt;
	}
	int ans = ct[k];
	int l = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] == k){
			int ent = i-l;
			if(ent >= 0){
//				cout << l << " " << i-1 << " " << ent/2 << endl;
				ans += ent/2;
			}
			l = i+1;
		}
	}
	cout << ans;
	return 0;
}