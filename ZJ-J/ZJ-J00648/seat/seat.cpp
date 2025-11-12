#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b=1,q,w,h,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int e=n*m-1;
	cin>>a;
	while(e--){
		cin>>q;
		if(q>a){
			b++;
		}
	}
	h=(b+n-1)/n;
	r=b-n*(h-1);
	if(h%2==1){
		cout<<h<<" "<<r;
		return 0;
	}
	else{
		cout<<h<<" "<<n-r+1;
		return 0;
	}

	return 0;
}

