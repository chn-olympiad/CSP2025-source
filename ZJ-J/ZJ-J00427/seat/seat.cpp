#include<bits/stdc++.h>
using namespace std;

int n, m, a[1145], h, l, x;
int p[115][115], cnt = 0;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++)cin>>a[i];
	x = a[1];
	sort(a+1, a+n*m+1, greater<int>());
	
	for(int j = 1; j <= m; j++){
		if(j&1)for(int i = 1; i <= n; i++)p[i][j] = a[++cnt];
		else for(int i = n; i >= 1; i--)p[i][j] = a[++cnt];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
//			cout<<p[i][j]<<" \n"[j == m];
			if(p[i][j] == x)cout<<j<<" "<<i;
		}
	}
	return 0;
}
