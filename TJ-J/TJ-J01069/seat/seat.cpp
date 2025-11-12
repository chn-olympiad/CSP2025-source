#include<bits/stdc++.h>
using namespace std;

int a[102],n,m,num,b[102],seat[101][101];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m ;
	for(int i = 1 ; i <= n * m ; i ++){
		cin >> b[i];
	}
	num = b[1];
	sort(b + 1 , b + 1 + n * m);
	for(int i = 1 ; i <= n * m ; i ++){
		a[i] = b[n * m - i + 1];
		//cout << a[i] << " ";
	}
	//cout << endl;
	int cnt = 0;
	for(int i = 1 ; i <= m ; i ++){
		if(i % 2 == 0){
			for(int j = 1 ; j <= n ; j++){
				seat[j][i] = a[n - j + 1 + cnt];
			}
			cnt += n;
		}
		if(i % 2 == 1){
			for(int j = 1 ; j <= n ; j++){
				seat[j][i] = a[j  + cnt];
			}
			cnt += n;
		}
	}
	for(int i = 1; i <= n ; i ++){
		for(int j = 1; j <= m ; j ++){
			//cout << seat[i][j]  <<" ";
			if(seat[i][j] == num){
				cout << j << " " << i;
			}
		}
	}
	return 0;
}
