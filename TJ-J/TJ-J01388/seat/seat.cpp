#include <bits/stdc++.h>
using namespace std;
int b[101],s[1001][1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt = n * m; 
	for (int i = 1;i <= cnt;i++){
		cin >> b[i];
	}
	int f = b[1];
	sort(b,b + cnt + 1);
	int x = 1,y = 1,sum = 0;
	for (int i = 1;;i++){
		if (b[cnt] == f){
			cout << y << ' ' << x;
			break;
		}
		cnt--;
		if (y % 2 == 1){
			if (x == n){
				y++;
			}
			else{
				x++;
			} 
		}
		else{
			if (x == 1){
				y++;
			}
			else{
				x--; 
			} 
		}
	}
	return 0; 
} 
