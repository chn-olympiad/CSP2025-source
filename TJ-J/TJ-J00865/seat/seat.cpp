#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,c;
	cin >> n >> m;
	int x = n*m;
	int a[x+1];
	for(int i = 1;i <= x;i++){
		cin >> a[i];
	}
	int k = a[1],d;
	for(int i = 1;i <= x;i++){
		for(int j = i;j <= x;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				
			}
		}
	}
	for(int i = 1;i <= x;i++){
		if(a[i]==k){
			d = i;
			break;
		}
	}
	
	if(d <= n){
	    c = 1;
	}
	else{
		c = d/n+1;
   	}
	if(d%n==0){
		r = n;
	}
	else{
		r = d%n;
	}
	if(c%2==0){
		r = n-r+1;
	
	}
	cout << c << " " << r;
	
	return 0;
}
