#include <bits/stdc++.h> 
using namespace std;

int num[500010], dp[500010], m[500010];

int yihuo(int a, int b){
	int x[25], y[25];
	for(int i = 1; i <= 24; i++){
		x[i] = 0;
		y[i] = 0;
	} 
	int i = 1, j = 1;
	while(a){
		x[i] = a % 2;
		a /= 2;
		i++;
	}
	while(b){
		y[j] = b % 2;
		b /= 2;
		j++;
	}
	int c = 0;
	for(int k = 1, p = 1; k <= max(i, j) - 1; k++, p *= 2){
		if(x[k] + y[k] == 1)
			c += p;
	}
	return c;
}

int main(){
	freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int ans = 0;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> num[i];
	int cnt = 0;
	for(int i = 1, j = 1; i <= n; i++, j = i){
		if(num[i] == k){
			dp[i] = m[i - 1] + 1;
			ans = max(ans, dp[i]);
		}else{
			int t = num[i];
			while(t != k && j != n){
				j++;
				t = yihuo(t, num[j]);
			}
			if(t == k){
			    dp[j] = max(dp[j], m[i - 1] + 1);
			    ans = max(dp[j], ans);
			}
	    }
	    m[j] = max(m[j], m[i - 1] + 1);
	    for(int p = j; p <= n; p++)
	    	m[p] = m[j];
	}
	cout << ans;
	return 0;
}
