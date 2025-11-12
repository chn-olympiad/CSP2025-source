#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[15][15], s[105];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) cin >> s[i];
	ans = s[1];
	sort(s+1, s+(n*m)+1, cmp);
	for(int i=1; i<=m; i++){
		if(i%2==1){
		    for(int j=1; j<=n; j++){
		    	a[i][j] = s[(i-1)*n+j];
		    }
	    }
	    else{
	    	for(int j=n; j>=1; j--){
	    		a[i][j] = s[(i-1)*n+(n-j+1)];
			}
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j]==ans){
				cout << i << " " << j;
				return 0;
			} 
		}
	}
	return 0;
} 
