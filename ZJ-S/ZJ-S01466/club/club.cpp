#include<bits/stdc++.h>
using namespace std;
int n, t, A, B, ans;
int a[100005][4];
int b[100005];
int c[100005];
int d[100005];
int dfs(int qb, int qc, int qd, int w){
	int k = qb + qc + qd;
	if (k == n){
		if (qb>n/2 || qc>n/2 ||qd>n/2){
			return -1000000000;
		}	
		return w;
	}
	int w1 = dfs(qb+1, qc, qd, w + a[k+1][1]);
	int w2 = dfs(qb, qc+1, qd, w + a[k+1][2]);
	int w3 = dfs(qb, qc, qd+1, w + a[k+1][3]);
	return max(w1, max(w2, w3));
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		A = B = 1;
		ans = 0;
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] != 0 || a[i][3] != 0){
				A = 0;
			}
			if(a[i][3] != 0){
				B = 0;
			}
		}
		
		if (A == 1){
			for(int i = 1; i <= n; i++) b[i] = a[i][1];
			for(int i = 1; i < n; i++){
				for (int j = n-1; j >= i; j-- ){
					if (b[j] < b[j+1]) swap(b[j], b[j+1]);
				}
			}
			for(int i = 1; i <= n/2; i++){
				ans += b[i];
			}
			cout << ans << endl;
		}
		else if(B == 1){
			int qb, qc;
			qb = qc = 0;
			for(int i = 1; i <= n; i++){
				if(a[i][1] > a[i][2]){
					ans += a[i][2];
					b[++qb] = a[i][1] - a[i][2];
				}
				else {
					ans += a[i][1];
					c[++qc] = a[i][2] - a[i][1];
				}
			}
			
			for(int i = 1; i < qb; i++){
				for (int j = qb-1; j >= i; j-- ){
					if (b[j] < b[j+1]) swap(b[j], b[j+1]);
				}
			}
			for(int i = 1; i < qc; i++){
				for (int j = qc-1; j >= i; j-- ){
					if (c[j] < c[j+1]) swap(c[j], c[j+1]);
				}
			}
			
			for (int i = 1; i <= min(qb, n/2); i++){
				ans += b[i];
			}
			for (int i = 1; i <= min(qc, n/2); i++){
				ans += c[i];
			}
			cout << ans << endl;
		}
		else if(n <= 10){
			ans = dfs(0, 0, 0, 0);
			cout << ans << endl;
		}
		else {
			int qb, qc, qd;
			qb = qc = qd = 0;
			for(int i=1; i<= n; i++){
				if(a[i][1]== min(min(a[i][1], a[i][2]), a[i][3])){
					ans += a[i][1];
					b[++qb] = 0;
					c[++qc] = a[i][2] - a[i][1];
					d[++qd] = a[i][3] - a[i][1];
				}
				else if(a[i][2]== min(min(a[i][1], a[i][2]), a[i][3])){
					ans += a[i][2];
					c[++qc] = 0;
					b[++qb] = a[i][1] - a[i][2];
					d[++qd] = a[i][3] - a[i][2];
				}
				else{
					ans += a[i][3];
					d[++qd] = 0;
					c[++qc] = a[i][2] - a[i][3];
					b[++qb] = a[i][1] - a[i][3];
				}
			}
			
			cout << ans << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
