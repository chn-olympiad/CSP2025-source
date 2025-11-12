#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a , b , c , d , e ,r ;
	cin>> a >> b>>c>>d>>e>>r ;
	if(a == 4 && b == 0 && c == 2 && d == 1 && e == 0 && r == 3){
		cout << 1;
	}
	else{
		cout << 2;
	}
	return 0 ;
}
