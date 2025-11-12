#include <bits/stdc++.h>
using namespace std;
int n,m,a1,a,wei=1,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>a1) wei++;
	}
	if(wei%n==0) l=wei/n;
	else l=wei/n+1;
	int k=wei%n;
	int pan=wei%(2*n);
	if(pan>=1&&pan<=n){
		if(k!=0) cout<<l<<' '<<k;
		else cout<<l<<' '<<n;
	}
	else{
		if(k!=0) cout<<l<<' '<<n-k+1;
		else cout<<l<<' '<<1;
	}
	return 0;
}

