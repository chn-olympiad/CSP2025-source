#include<bits/stdc++.h>
using namespace std;
const int maxn1 = 1e5 + 10;
const int maxn2 = 5e5 + 50;
int a[5][maxn1], sum[maxn2];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, m1, m2, m3;
	cin >> t;
	while(t--){
		cin >> n;
		if(n == 2){
			for(int i = 1; i <= 3; i++){
				for(int j = 1; j <= n; j++){
					cin >> a[i][j];
				}
			}
			for(int k = 1; k <= 5 * n; k++){
				int i = 1, j = 1;
				if(i == j){
					j++;
					sum[k] = a[1][i] + a[2][j];
					k++;
			    }
			    j++;
			    sum[k] = a[1][i] + a[2][j];
			    k++;
				if(j == 3){
					i++;
					j = 1;
				}
				sum[k] = a[1][i] + a[2][j];
				k++;
			}
			sort(sum + 1, sum + 3 * n + 1, cmp);
			cout << sum[1] << endl;
	    }
	}
	return 0;
}