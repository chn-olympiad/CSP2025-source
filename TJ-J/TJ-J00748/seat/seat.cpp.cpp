#include<bits/stdc++.h>
using namespace std;

int m,n,a[225],myself,key_turn,x,y;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m;i++){
		cin >> a[i];
	}
	myself = a[1];
	for(int i = 1;i <= n*m; i++){
		for(int j = 1;j <= n*m; j++){
			if(a[j] < a[j + 1]){
				key_turn = a[j];
				a[j] = a[j + 1];
				a[j + 1] = key_turn;
			}
		}	
	}
	for(int i = 1;i <= n*m; i++){
		if(a[i] == myself){
			key_turn = i;
		}
	}
	if(key_turn <= n){
		x = 1;
		y = key_turn;
	}else{
		x = 1 + (key_turn / n);	
		if(x % 2 == 0){
			y = n + 1 - (key_turn % n);
		}else{
			y = key_turn % n;	
		}
	}	
	cout << x << " " << y;
	return 0;
} 
