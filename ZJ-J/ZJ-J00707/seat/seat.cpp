#include<bits/stdc++.h>
using namespace std;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,R;
	cin>>n>>m>>a[1];
	R=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,greater<int>());
	int i=1;
	for(;i<=n*m;i++)if(a[i]==R)break;
	int c=(i-1)/n+1,r=(i-1)%n+1;
	if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r; 
	return 0;
}
