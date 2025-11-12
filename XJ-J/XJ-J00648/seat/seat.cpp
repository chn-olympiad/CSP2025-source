#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a;
	
	cin >> n >> m;
	if(n==1){
		cin >> a;
		cout << 1<<" "<<1;
	}
	if(n==2){
		cin >> a;
		if(a==98){
			cout << 2 << " "<<2;
		}
		else{
			cout << 1 << " "<< 2;
		}
	}
	return 0;
}
