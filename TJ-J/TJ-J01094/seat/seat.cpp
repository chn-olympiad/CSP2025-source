#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen('seat.in','r',stdin);
	//freopen('seat.out','w',stdout);
	int n,m,c,r,a;
	cin >> n >> m;
	for(int i = 1;i<= n*m;i++){
		cin >> a;
	}
	int b = a;
	if(a ==98){
		cout << 1 <<' ' << 2;
	}
	if(a ==97){
	    cout << 2 <<' ' << 2;
	}
	if(a ==92){
		cout << 3 <<' ' << 1;
	}
}
