#include<bits/stdc++.h>
using namespace std;
int n, m, ans, ansx, ansy;
int a[1000];
int p[50][50];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m>>a[1];
	a[1] = -a[1];
	ans = a[1];
	for(int i = 2; i <= n*m; i++){
		cin>>a[i];
		a[i] = -a[i];
	}
	sort(a+1, a+1+n*m);
	int t = 0;
	for(int i = 1; i <= m; i++){
		int op = i%2;
		if(op != 0){
			for(int j = 1; j <= n; j++){
				p[j][i] = a[++t];
				if(a[t] == ans){
					ansx = j;
					ansy = i;
				}
			}
		}
		else{
			for(int j = n; j >= 1; j--){
				p[j][i] = a[++t];
				if(a[t] == ans){
					ansx = j;
					ansy = i;
				}
			}
		}
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}
