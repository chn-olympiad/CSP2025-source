#include<bits/stdc++.h>
using namespace std;
int a[100007], seat[10007][10007];
int main(){
	
	
	int n,m;
	scanf("%d%d", &n, &m);
	int k;
	for(int i = 1 ; i <= n * m ; i++){
		scanf("%d", &a[i]);
	}
	k = a[1];
	for(int i = 1 ; i < n * m ; i++){
		for(int j = 1 ; j < n * m - i ; j++){
			if(a[j] < a[j+1]) swap(a[j], a[j+1]);
		}
	}
	int l=0;
	for(int i = 1 ; i <= m ; i++){
		if(i % 2 == 1){
			for(int j=1 ; j <= n ; j++){
				seat[i][j] = a[l];
				l++;
				if(a[l] == k){
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
		else{
			for(int j = n ; j >= 1 ; j--){
				seat[i][j] = a[l];
				l++;
				if(a[l] == k){
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
	}
	
	
	return 0;
}
