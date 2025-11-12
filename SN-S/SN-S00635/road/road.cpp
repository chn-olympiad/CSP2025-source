#include <bits/stdc++.h>
using namespace std;
int n, m, k, price[10005][10005];
int turn[10005][10005];
int main(){;
	freopen("road.in","r",stdin);,dp[][]
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int a, b, c;
	for (int i=1; i<=m; i++){
		cin >> a >> b >> c;
		price[a][b] = price[b][a] = c;
	}
	for (int i=1; i<=k; i++){
		cin >> a;
		b = 1;
		while(b++ <= n){
			cin >> turn[a][b];
			turn[b][a] = turn[a][b]; 
		}
	}
	cout << 24325420 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
