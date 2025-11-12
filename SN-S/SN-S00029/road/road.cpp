#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n , m , k , a[N] , b[N] , w[N] , times[N] , mid , ans;

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	cin >> n >> m >> k;
	for(int i=1 ; i<=m ; i++){
		cin >> a[i] >> b[i] >> w[i];
	}
	for(int i=1 ; i<=m ; i++){
		times[a[i]]++;
		times[b[i]]++;
	}
	for(int i=1 ; i<=m ; i++){
		if(times[i] > times[i-1]) mid = i; 
	}
	for(int i=1 ; i<=m ; i++){
		if(a[i] == mid || b[i] == mid) ans += w[i];
	}
	cout <<ans;
} 
