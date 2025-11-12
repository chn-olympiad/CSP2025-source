#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],t,b[101][101],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	ans = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i = 1,j = 1;
	while(i <= n && j <= m){
		while(i < n){
			b[i][j] = a[++t];
			i++;
		}
		b[i][j] = a[++t];
		j++;
		while(i > 1){
			b[i][j] = a[++t];
			i--;
		}
		b[i][j] = a[++t];
		j++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == ans){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
} 
