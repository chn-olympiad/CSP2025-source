#include<bits/stdc++.h>
using namespace std;
int n,m,t,i,a[6666],r,x,y;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	cin>>a[1];r=a[1];
	for(i=2;i<=t;i++) cin>>a[i];
	sort(a+1,a+1+t,cmp);
	x=0;y=1;
	for(i=1;i<=t;i++){
		x=x+((y%2==1) ? 1 : -1);
		if(x==n+1||x==0) y++,x=((x==n+1) ? n : 1);
		if(a[i]==r) break;
	}
	cout<<y<<" "<<x;
	return 0;
}

