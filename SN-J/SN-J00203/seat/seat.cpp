#include<bits/stdc++.h>
using namespace std;
int a [100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n*m ; i++){
		cin>>a[i];
	}
	int g = a[0];
	for(int i = 0 ; i < n * m - 1 ; i++){
		for(int j = 0 ; j < n * m - i ; j++){
			if(a[i] < a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i = 0 ; i < n*m ; ++i){
		if(a[i] == g){
			int c = i % (2*n);
			if(c / n > 1){
				cout>>2 * c +(c / n + 1) >>" ">> n + 1 - (c % 5); 	
			}
			else{
				cout>>2 * c +(c / n + 1) >>" ">> c % 5;
			}
		}
	}
	return 0;
}
