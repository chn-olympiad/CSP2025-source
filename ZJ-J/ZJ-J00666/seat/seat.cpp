#include<iostream>
#include<cstdio>
using namespace std;
int n,m,num,a,z,cnt,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n>>z;
	num=n*m;
	for(int i=1;i<num;i++){
		cin>>a;
		if(a>z)cnt++;
	}
	for(z=1;cnt--;){
		y+=z;
		if(y>m)y=m,x++,z*=-1;
		else if(y<1)y=1,x++,z*=-1;
	}
	cout<<x<<" "<<y;
	return 0;
}
