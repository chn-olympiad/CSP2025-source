#include<iostream>
#include<cstdio>
using namespace std;
int m,n,cj,mx;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m>>cj;
	int t,c,r;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>cj)mx++;
	}
	c=mx/n+1;
	if(c%2) r=mx%m+1;
	else r=m-(mx%m);
	cout<<c<<" "<<r;
}
