#include<bits/stdc++.h>
using namespace std;

int n,a[5005],rel=0;

void d(int tol,int ma,int ge,int x){
	if(x==n){
		if(ge>=3&&tol>ma*2){
			rel++;
			rel%=998244353;
		}
		return;
	}
	d(tol,ma,ge,x+1);
	if(a[x]>ma){
		d(tol+a[x],a[x],ge+1,x+1);
	}
	else{
		d(tol+a[x],ma,ge+1,x+1);
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	d(0,0,0,0);
	cout<<rel;
	return 0;
}

