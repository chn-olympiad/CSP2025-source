#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int a[n * m];
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	int r = a[0];
	for(int i = 0;i < n * m;i++){
		for(int j = i + 1;j < n * m;j++){
			if(a[i] < a[j]) swap(a[i],a[j]);
		}
	} 
	int f[n][m];
	for(int i = 0;i < n * m;i++){
		for(int j = 0;j < n;j++){
			for(int k = 0;k < m;k++){
				f[j][k] = a[i];
			}
		}
	}
	int s1 = 1,s2 = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(f[i][j] == r && m % 2 == 0){
				s1 = a[i] + 1;
				s2 = a[j] + 1;
				break;
			}
			else if(f[i][j] == r && m % 2 == 1){
				s1 = n - a[i] + 1;
				s2 = a[j] + 1;
				break;
			}
		}
	}
	cout << s2 << " "<< s1;
	return 0;
} 
/*
 
*/
