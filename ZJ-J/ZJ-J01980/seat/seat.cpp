#include<bits/stdc++.h>
using namespace std;
long long n,m,r,a,x=1,l,h,hyk;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<=n*m-1;i++){
		cin>>a;
		if(a>r){
			x++;
		}
	}
	l=(x-1)/n+1;
	if(l%2==1){
		h=(x-1)%n+1;
	}
	else{
		h=n-((x-1)%n+1)+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

