#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,a[10005],pos,r,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x)pos=i;
	c=(pos-1)/n+1;
	pos-=(c-1)*n;
	if(c&1)r=pos;
	else r=n-pos+1;
	cout<<c<<' '<<r<<'\n';
	return 0;
}