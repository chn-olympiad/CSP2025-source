#include<bits/stdc++.h>
using namespace std;
int m,n,in,im,a[1001],x,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	im=1,t=1;
	for(int i=1;i<=n*m;i++){
		if(t) in++;
		else in--;
		if(in>n&&t) im++,in=n,t=0;
		else if(in<1&&!t) im++,in=1,t=1;
		if(a[i]==x){
			cout<<im<<" "<<in;	
			break;
		}
	}
}
