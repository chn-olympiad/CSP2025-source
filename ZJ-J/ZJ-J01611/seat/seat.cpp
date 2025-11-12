#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int read(){
	int x; scanf("%d", &x); return x;
}
int n, m, poss;
int a[N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= n * m; i++){
		a[i] = read();
		if(i == 1) poss = a[i];
	} 
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[(i - 1) * m + j] == poss){
				if(i % 2 == 1){
					printf("%d %d", i, j);
				}
				else{
					printf("%d %d", i, n - j + 1);
				}
				break;
			}
			
		}
	}
	return 0;
}
