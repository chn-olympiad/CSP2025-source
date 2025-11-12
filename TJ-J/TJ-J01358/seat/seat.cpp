#include <bits/stdc++.h>
using namespace std;
bool c(int a1,int a2){
	if(a1 > a2){
		return true;
	}
} 
int main(){
	int n , m ;
	freopen("seat.in","r",stdin);
	cin >> n >> m;
	int a[n*m+1];
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int x,y,r = a[1];
	sort(a+1,a+n*m+2,c) ;
	for(int i = 1;i <= n*m;i++){
		if(r == a[i]){
			x = i/n+1;
			y = i% n;
			break;
		}
	}
	y = m-y+1;
	freopen("seat.out","w",stdout);
	cout << x <<" "<< y;
	return 0;
} 
