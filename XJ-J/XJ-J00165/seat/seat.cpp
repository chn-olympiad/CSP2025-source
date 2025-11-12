#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b,seat = 0;
	cin >> n >> m;
	cin >> a;
	for(int i = 1;i<=n*m-1;i++){
		cin >> b;
		if(b>a){
			seat++;
		}
	}
	seat++;
	if(seat<=n){
		cout << 1 << ' ' << seat;
	}
	else if((seat/n+1)%2==0){
		cout << seat/n+1 << ' ' << n-(seat%m)+1;
	}
	else{
		cout << seat/n+1 << ' ' << seat%m;
	}
	return 0;
}
