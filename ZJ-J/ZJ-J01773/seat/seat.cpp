#include<bits/stdc++.h>
using namespace std;
int n,m,f,f1;
int a[105];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==f){
			f1=i;break;
		}
	int x,y;
	if(f1<n)x=1;
	else if(f1%n==0)x=f1/n;
	else x=f1/n+1;
	if(f1<n)y=f1;
	else if(x%2==1){
		if(f1%n==0)y=n;
		else y=f1%n;
	}
	else {
		if(f1%n==0)y=1;
		else y=n-f1%n+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
