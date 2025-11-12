#include<bits/stdc++.h>
using namespace std;
int main(){
	//rfresh("seat.in","r",stdin);
	//rfresh("seat.out","w",stdout);
	int n,m,num=1,c,r,sum,point,a;
	cin>>n>>m;
	sum=n*m;
	cin>>a;
	for(int i=1;i<=n*m-1;i++){
		cin>>point;
		if(point>a)num++;
	}
	
	c=(num+n-1)/n;
	r=num%n;
	if(r==0)r=n;
	cout<<c<<' '<<r;
	
	//rclose(stdin);
	//rclose(stdout);
	return 0;
} 
