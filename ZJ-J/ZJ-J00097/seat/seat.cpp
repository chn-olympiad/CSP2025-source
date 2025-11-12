#include<bits/stdc++.h>
using namespace std;
int n,m,k,v,t,x,y,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1],v=n*m;
	stable_sort(a+1,a+v+1,greater<int>());
	for(int i=1;i<=v;i++)if(a[i]==k)t=i;
	x=(t+m-1)/m,y=t%m;
	if(x%2&&!y)y=m;
	if(x%2==0)y=m-y+1;
	cout<<x<<" "<<y;
	return 0;
}
