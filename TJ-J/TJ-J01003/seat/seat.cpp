#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],pos,c,r,sc;
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
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc){
			pos=i;
			break;
		}
	}
	c=(pos-1)/n+1;
	if(c%2==1){
		r=pos%n;
		if(r==0){
			r=n;
		}
	}
	else{
		r=n-(pos-1)%n;
	}
	cout<<c<<' '<<r;
	return 0;
}
