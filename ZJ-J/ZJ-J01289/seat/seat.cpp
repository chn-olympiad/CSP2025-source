#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,sum=1,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>a){
			sum++;
		}
	}
	l=(sum+n-1)/n;
	if(l%2){
		h=(sum-1)%n+1;
	}
	else{
		h=n-(sum-1)%n;
	}
	cout<<l<<' '<<h;
	return 0;
}
