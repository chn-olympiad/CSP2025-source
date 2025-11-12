#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a , b , c , d , e ,r , j , k ,l;
	cin>> a >> b ;
	c = a * b;
	e = 0;
	r = 0;
	for(int i=1;i <= c;i++){
		cin >> d;
		if(e == 0){
			e = e + d;
		}
		if (e < d){
		    r = r + 1;	
		}
	}
	j = r / b;
	k = r % b;
	if(j % 2 == 0){
		l = k + 1;
	}
	else{
		l = b - k;
	}
	cout << j + 1<<" ";
	cout << l;
	return 0 ;
}
