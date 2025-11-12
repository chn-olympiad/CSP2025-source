#include<bits/stdc++.h>
using namespace std;
const int maxn = 11;
int s[110];
//int sor[110];
int a[maxn][maxn];
void find(int n, int m, int a1){
	int x = 1;
	int y = 1;
	int d = 0;
	for(int i = 1; i <= n*m; i++){
		a[y][x] = s[i];
		if(a[y][x] == a1){
			cout << x << " " << y;
			return;
		}
		if(d == 0 ){
			if(y+1 <= n){
				y++;
			}else{
				d = d+1 % 4;
				x++;
			}
		}else if(d == 1){
			if(x+1 <= m){
				x++;
				d = d+1 % 4;
			}
		}else if(d == 2){
			if(y-1 >= 1){
				y--;
			}else{
				d = d+1 % 4;
				x++;
			}
		}else{
			if(x+1 <= m){
				x++;
				d == d+1 %4;
			}
		}
	}
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> s[i];
	}
	a1 = s[1];
	int maxx;
	int c;
	for(int i = 1; i <= n*m; i++){
		//maxx = s[i];
		for(int j = i+1; j <= n*m; j++){
			if(s[i] < s[j]){
				c = s[j];
				s[j] = s[i];
				s[i] = c;
			//	maxx = s[i];
			}
		}
	}
	find(n, m, a1);
	return 0;
}
