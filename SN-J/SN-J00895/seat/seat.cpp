#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,m,a[N],k,x,y;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	k=a[1],sort(a+1,a+n*m+1,greater<int>()),k=lower_bound(a+1,a+n*m+1,k,greater<int>())-a;
	x=(k-1)/n+1,y=(k-1)%(2*n)+1;
	if(y>n)	y=2*n-y+1;
	cout<<x<<' '<<y<<'\n';
	return 0;
}
