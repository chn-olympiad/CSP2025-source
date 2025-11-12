#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,a[1000010],x,y;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	/*if(m>100){
		c=m;
		m
	}else */
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;break;
		}
	}
	y=n*m+1-y;
	if(y%n!=0){
		x=1+y/n;
	}
	else x=y/n;
	//cout<<y<<" ";
	cout<<x<<" ";
	if(x%2==1){
		if(y%n==0)cout<<n;
		else cout<<y%n;
	}
	else {
		if(y%n==0)cout<<1;
		else cout<<n+1-y%n;
	}
	return 0;
}
//2 2 98 99 100 97
//3 3 94 95 96 97 98 99 100 93 92
