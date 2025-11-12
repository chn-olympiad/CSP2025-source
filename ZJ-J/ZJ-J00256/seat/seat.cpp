#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,b,pm,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+1+x,greater<int>());
	for(int i=1;i<=x;i++) if(a[i]==b) pm=i;
	if(pm%n==0) c=1;
	else c=pm%m+1;
	if(pm%n==0) r=n;
	else if(c%2==0) r=pm%n+n-1;
	cout<<c<<" "<<r<<endl;
	return 0;
}
