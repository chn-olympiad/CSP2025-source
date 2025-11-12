#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,b,c;
int a1,b1;
bool ok;
int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	ok = 0;
	n = 1;
	m = 1;
	
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	b = a[1];
	sort(a+1,a+n*m+1);
	for(int i = 1;i<=n*m;i++){
		if(a[i] == b){
			c = n*m-i+1;
		}
	}
	
	
	
	
	if(c%n==0){
		a1 = c/n;
		ok = 1;
	}
	else{
		a1 = c/n+1;
	}
	if(a1%2==1){
		if(ok){
			b1 = n;
		}
		else{
			b1 = c%n;
		}
	}
	else{
		if(ok){
			b1 = 1;
		}
		else{
			b1 = n-(c%n)+1;
		}
	}
	cout<<a1<<" "<<b1;
	return 0;
}


