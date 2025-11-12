#include<bits/stdc++.h>
using namespace std;
int n, m, myself;
int a[12][12], s[110];
int mysort(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &s[i]);
	}
	myself = s[1];
	sort(s + 1, s + n * m + 1, mysort);
	
	int num = 0;
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				num++;
				a[i][j] = s[num];
				if(a[i][j] == myself){
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else{
			for(int j = n; j >= 1; j--){
				num++;
				a[i][j] = s[num];
				if(a[i][j] == myself){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
