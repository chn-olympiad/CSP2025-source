#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a[100010],index;
	cin >> n >> m;
	for(int i = 0; i < n*m; i++){
		cin >> a[i];
	}
	r = a[0];
	index = 0;
	c = 0;
	for(int i = 0; i < n*m; i++){
		for(int j = 0; j < n*m-i; j++){
			if(a[j] < a[j+1]){
				int b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	}

	for(int i = 0; i < n*m; i++){
		if(a[i] == r){
			index = i+1;
			break;
		}
	}
	if(index%n == 0){
		c = index/n;
		r = n;
	}
	else{
		c = (index/n)+1;
		if(c%2==0){
			r = n-index%n+1;
		}
		else{
			r = index%n;
		}
	}
	cout << c << " " << r;
	
	
	
	
	
	
	
	
	
	return 0;
}
