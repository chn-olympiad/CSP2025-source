#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ll,rr,lr,rl;
	int l=max(max(a,b),max(c,d));
	int r=min(min(a,b),min(c,d));
	if(a!=l&&a!=r){
		lr=a;
	}else if(b!=l&&b!=r){
		if(lr==a){
			rl=b;
		}else{
	        lr=b;
	    }
	}else if(c!=l&&c!=r){
		if(lr==a||lr==b){
			rl=c;
		}else{
	        lr=c;
	    }
	}else if(c!=l&&c!=r){
		rl=d;
	}
	ll=max(lr,rl);
	rr=min(lr,rl);
	if(n==1&&m==1){
		cout<<1;
	}else if(n==1){
		cout<<m;
	}else if(m==1){
		cout<<n;
	}else if(n==2&m==2){
	    if(a==l){
	    	cout<<1;
		}else if(a==r){
			cout<<4;
		}else if(a==lr){
			cout<<2;
		}else{
			cout<<3;
		}
	}
}

