#include<bits/stdc++.h>
using namespace std;
int a[10007];
int ans(int n , int m){
	if(m - n == 3){
		int k = 0;
		for(int i = n ; i < m ; i++){
			k += a[i];
		}
		if(k > a[m]) return 1;
	}
	return ans(0, (m - n) / 2) + ans((m - n) / 2, (m - n) / 2 + 1);
}
int main(){
	
	
	int n;
	scanf("%d", n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < n - i - 1 ; j++){
			if(a[j] > a[j+1]) swap(a[j], a[j+1]);
		}
	}	
	printf("%d", ans(0, n) % 998244353);
	
	
	return 0;
}
