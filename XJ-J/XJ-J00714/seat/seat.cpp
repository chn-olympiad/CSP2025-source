#include <bits/stdc++.h>
using namespace std;

int n,m,c,r,seat;
int id,a[510],p;

bool ans(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	
	cin >> n >> m;
	seat = n*m;
	for(int i=0; i<=seat; i++){
		cin >> a[i];
		break;
	} 
	
	id = a[1];
	sort(a+1,a+seat+1,ans);

	for(int i=1; i<=seat; i++){
		if(a[i] == id){
			p = i;
		}
	}
	c = p/n+1;
	r = p%n;
	if(r==0){
		r = n;
		c -= 1; 
	}
	
	cout << c << " " << r;
	
return 0;
}
