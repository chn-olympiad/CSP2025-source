#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ax,sl=1,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>ax;
		if(ax>a){
			sl++;
		}
	}
	l=sl/n;
	if(sl%n!=0){
		l++;
		if(l%2==0){
			h=n+1-sl%n;
		}
		else{
			h=sl%n;
		}
	}
	else{
		if(l%2==0){
			h=1;
		}
		else{
			h=n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
