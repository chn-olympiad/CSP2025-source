#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m;
int n;
int grade[1000];
int re[1000];
int c,r;
int ur;
int now;


int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=m*n-1;i++){
		cin>>grade[i];
	}
	ur=grade[0];

	sort(grade,grade+m*n);
	for(int i=0;i<=m*n-1;i++){
		if(grade[i]==ur) now=m*n-i;
	}
	if(now<=n) c=1,r=now;
	if(now>n) c=2,r=n-now%n;
	if(now>2*n) c=3,r=now%n;
	if(now>3*n) c=4,r=n-now%3*n;
	if(now>4*n) c=5,r=now%n;
	if(now>5*n) c=6,r=n-now%4*n;
	if(now>6*n) c=7,r=now%n;
	if(now>7*n) c=8,r=n-now%7*n;
	if(now>8*n) c=9,r=now%n;
	if(now>9*n) c=10,r=n-now%9*n;
	cout<<c<<" "<<r;
	return 0;
}
	
	
	
	

