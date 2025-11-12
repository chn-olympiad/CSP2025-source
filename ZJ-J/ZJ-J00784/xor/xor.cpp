# include <bits/stdc++.h>
using namespace std;
int n, k, cnt, t, st, a[500003];
bool e[500003];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i<=n; ++i){
		scanf("%d", a+i);
		if (a[i] == k){
			e[i] = true;
			cnt++;
		}
	}
	for (int p = 1; p<n; ++p){
		t = 0, st = p;
		for (int i = p; i<=n; ++i){
			if (e[i]){
				st = i+1;
				t = 0;
				continue;
			} 
			t = t^a[i];
			if (t == k){
				cnt++;
				for (int j = st; j<=i; ++j){
					e[j] = true;
				}
				st = i+1;
				t = 0;
				break;
			}
		}	
	}
	cout << cnt << endl;
	return 0;
}
