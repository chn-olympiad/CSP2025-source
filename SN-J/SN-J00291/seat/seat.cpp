#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[102],x;
	cin>>n>>m;
	cin>>a[0];
	int r=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			x=i;
		}
	} 
	int c,d;
	if((x/n)%2!=0){
		c=x/n+1;
		d=n-(x%n);
	}else{
		c=x/n+1;
		d=x%n+1;
	}
	cout<<c<<' '<<d;
	return 0;
}
