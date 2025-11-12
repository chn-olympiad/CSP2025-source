#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int R_ = a[1];
	sort(a+1, a+1+n*m, cmp);
	int x = 1, y = 1, w = 1;
	for(int i = 1; i <= n*m; i++){
		if(w == 1){
			if(a[i] == R_){
				cout << y << " " << x;
				break;
			}
			if(i % (2*n) == n && i != 1){
				y++;
				w = 0;
			}else{
				x++;
			}
			
		}else if(w == 0){
			if(a[i] == R_){
				cout << y << " " << x;
				break;
			}
			if(i % (2*n) == 0 && i != 1){
				y++;
				w = 1;
			}else{
				x--;
			}
			
		}
	}
	return 0;
}