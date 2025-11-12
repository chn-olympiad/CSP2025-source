#include<bits/stdc++.h>
using namespace std;
const int N=1e2+12;
int n,m,a[N],c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1],y;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==x)y=i;
	if(y%n==0)c=y/n;
	else c=y/n+1;
	if(c%2==1){
		if(y%n==0)r=n;
		else r=y%n;
	}
	else{
		if(y%n==0)r=1;
		else r=n-y%n+1;
	}
	cout<<c<<' '<<r;
	return 0;
} 
