#include<bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
int a[500010];
bool cnt[500010];
int cal(int x, int y){
	return x ^ y;
}
bool check(int x, int y){
	int sum = a[x];
	for(int i = x + 1; i <= y; i++){
		sum = cal(sum, a[i]);
	}
	if(sum == k) return 1;
	return 0;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	if(n <= 2 && k == 0){
		if(a[1] == k && a[2] == k)
			cout << 2;
		else if(a[1] == k || a[2] == k)
			cout << 1;
		else if(cal(a[1], a[2]) == k)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(cnt[i] == 1) break;
			if(cnt[j] == 1) break;
			int l = i, r = j, mid, ans1 = -1, ans2 = -1;
			while(l <= r){
				mid = (l + r) / 2;
				if(check(mid, mid)){
					ans1 = mid, ans2 = mid;
					r = mid - 1;
				}
				else if(check(l, mid)){
					ans1 = l, ans2 = mid;
					r = mid - 1;
				}
				else{
					l = mid + 1;
				}
			}
			if(ans1 != -1){
				for(int p = ans1; p <= ans2; p++) cnt[p] = 1;
				ans++;
				cout << ans1 << " " << ans2 << " ";
			}
		}
	}
	cout << ans;
	return 0;
}
