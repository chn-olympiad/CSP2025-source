#include<bits/stdc++.h>
using namespace std;
int i,n,s,m,x,y,a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	for(i=1;i<=n*m;i++)
		s=s+(a[i]>=a[1]);
	x=(s+n-1)/n;
	y=s-(x-1)*n;
	if(x&1)
		cout<<x<<" "<<y;
	else
		cout<<x<<" "<<n-y+1;
}
