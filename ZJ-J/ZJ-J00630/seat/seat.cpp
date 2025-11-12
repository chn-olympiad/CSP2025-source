#include<bits/stdc++.h>
using namespace std;
int n=1,m,rp,o=1,x,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>rp;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>rp) o++;
	}
	l=o/n,r=o%n;
	if(r==0){
		if(l%2==1)
			cout<<l<<" "<<n;
		else
			cout<<l<<" "<<1;
	}
	else{
		if(l%2==1)
			cout<<l+1<<" "<<n-r+1;
		else	
			cout<<l+1<<" "<<r;
	}	
}