#include<bits/stdc++.h>
using namespace std;
int m,n,a[10005],t,k,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	t=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==t)k=i;
	}
	x=k%(2*n);
	y=k/n;
	if(k%n!=0)y++;
	if(x>n)x=(2*n+1)-x;
	cout<<y<<" "<<x;
	return 0;
}
