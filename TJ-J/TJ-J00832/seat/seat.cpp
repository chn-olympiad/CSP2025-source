#include <bits/stdc++.h>
using namespace std;
int a[20];
int s[20][20];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n*m; i++){
		scanf("%d", &a[i]);
	}
	int achi = a[1];
	sort(a+1, a+1+(n*m), cmp);
	int index= 1;
	for (int i = 1; i <=m; i+=0){
		for (int y = 1; y <= n; y++){
			s[y][i] = a[index];
			index++;
		} 
		i++;
		for (int y = n; y >= 1; y--){
			s[y][i] = a[index];
			index++;
		}
		i++;
	}
	
	
	int retx = 0, rety = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == achi){
				retx = j, rety = i;
				break;
			}
		}
	}
	
	printf("%d %d", retx, rety);
	return 0;
} 


