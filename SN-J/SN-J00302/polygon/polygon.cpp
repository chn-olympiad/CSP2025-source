#include <bits/stdc++.h>
using namespace std;
long long n , a[5005] , s , maxx = -1 , maxn = 0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++){
		if(a[i] > maxx){
			maxx = a[i];
		}
	}
	for(int i = 0; i < n; i ++){
		maxn += a[i];
	}
	if(maxn > maxx * 2){
		s ++;
	}
	cout << s;
	return 0; 
} 
