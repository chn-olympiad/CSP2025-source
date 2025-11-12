#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int b[200];
int r = 0,cnt = 0,m=0,n=0;
int main(){
	cin >> m >> n;
	for(int i = 0;i < m*n;i++){
		cin >> b[i];
		r = b[0];
	}
	for(int i = 0;i < m*n;i++){
		for(int i = 0;i < m*n;i++){
			if(b[i]>b[i-1]){
				swap(b[i],b[i-1]);
			}	
		}
	}
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			a[i][j] = b[cnt];
			cnt ++;
			cout << a[i][j];
		}	
	}
	return 0;
} 
