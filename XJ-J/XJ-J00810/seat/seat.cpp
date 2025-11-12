#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[100010],x,s,l,h,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++) cin>>a[i],s=a[1];
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--) if(a[i]==s) x=l-i+1;
	k=ceil(x*1.0/n);
	if(k%2==1) h=x-(k-1)*n;
	else h=n-x+(k-1)*n+1;
	cout<<k<<" "<<h;	
	return 0;
} 



