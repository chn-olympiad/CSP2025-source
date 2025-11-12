#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int a[101] = {};
	int m,n,k;
	cin >> n >> m;
	for(int i = 1; i <= m*n;i++){
		cin >> a[i];
	}
	for(int i = 2;i <= m*n;i++){
		if(a[i] > a[1]){
			k++;
		}
	}
	k += 1;
	int c;
	if(k % n == 0){
		c = k / n;
	}
	if(k % n != 0){
		c = k / n + 1;
	}
	int r;
	if(c % 2 != 0){
		r = k - (c-1)*n;
	}
    if(c % 2 == 0){
    	r = n + 1 -(k - (c-1) * n);
	}
	cout << c <<" "<< r;
	return 0;
}
