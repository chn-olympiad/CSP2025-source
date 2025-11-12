#include<bits/stdc++.h>
using namespace std;
int n,m,z,RR,c=1,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>RR;
	z=n*m;
	for(int i=2;i<=z;i++){
		cin>>a[i];
	}a[1]=RR;
	for(int i=1;i<=z;i++){
		for(int j=1;j<=z;j++){
			if(a[i]<a[i+1]) swap(a[i],a[i+1]);
		}
	}
	for(int i=1;i<=z;i++){
		if(a[i]==RR) r=i;
	}

	while(r>n){

		r-=n;
		c++;
	}if(c%2==0){
		r=n+1-r;
	}
	cout<<c<<" "<<r;
}