#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int summ,s=1,x=1,y=1,z=1;
int maxx = -1;
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		summ += a[i];
		maxx = max(maxx,a[i]);
	}
	for(int i = 1;i <= n;i++){
		x = x*i;
	}
	if(n==3){
		if(summ > maxx*2) cout << 1;
		else cout << 0;
	}
	else{
		for(int i = n-1;i >= 3;i--){
			for(int j = 1;j <= i;j++){
				y = y*j;
			}
			for(int j = 1;j <= n-i;j++){
				z = z*j;
			}
			s += x/(y*z);
			y = 1;
			z = 1;
		}
		cout << s;
	}
	return 0;
}
