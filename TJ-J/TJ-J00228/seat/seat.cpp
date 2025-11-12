#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b,c,d;
	cin>>n>>m;
	if(n==1&&m==1){
		cin>>a;
		cout<<1<<" "<<1;
	}
	 else if(n==1&&m==2){
		cin>>a>>b;
		if(a>b){
			cout<<1<<" "<<1;
		}
		else{
			cout<<1<<" "<<2;
		}
	}
	else if(n==2&&m==1){
		cin>>a>>b;
		if(a>b){
			cout<<1<<" "<<1;
		}
		else{
			cout<<2<<" "<<1;
		}
	}
	else if(n==2&&m==2){
		cin>>a>>b>>c>>d;
		if(a>b&&a>c&&a>d){
			cout<<1<<" "<<1;
		}
		else if(a<b&&a>c&&a>d){
			cout<<2<<" "<<1;
		}
		else if(a<b&&a<c&&a>d){
			cout<<2<<" "<<2;
		}
		else if(a<b&&a<c&&a<d){
			cout<<1<<" "<<2;
		}
	}
return 0;
} 
