#include<bits/stdc++.h>
using namespace std;
int a[109]={};
int cmp(int a,int b){
	if(a<b) return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int m,n,z,xr,pm,h=1,l=1;
	cin>>n>>m;
	z=n*m;
	cin>>xr;
	a[1]=xr;
	for(int i=2;i<=z;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+z,cmp);
	for(int i=1;i<=z;i++){
		if(a[i]==xr) pm=i;
	}
	l=pm/n;
	if(l%2==1){
		if(pm%n>0){
			l++;
			h=n+1-pm%n;
		}
		else h=n;
	}
	else{
		if(pm%n>0){
			l++;
			h=pm%n;
		}
		else h=1;
	}
	cout<<l<<" "<<h;
	return 0;
}
