#include<bits/stdc++.h>
using namespace std;
int n,m,c,y,a[10005],ans= 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i <= n*m-1;i++){
		cin >> a[i];
	}
	for(int j = 1;j <= n*m-1;j++){
		if(a[j]>a[0]){
			ans++;
		}
	}
	if(ans % n == 0){
		c = ans/n;
	}else{
		c = ans/n+1;
	}
	if(c%2 == 0){
		y = n-ans%n+1;
	}else{
		if(ans%n!= 0){
			y = ans%n;	
		}else{
			y = n;
		}
	}
	cout << c << " " << y;
	return 0;
}
