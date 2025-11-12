//SN-J00721  Õı •ø≠ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1005],now;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int ret=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(ret==a[i])now=i;
	int x=(now-1)/n+1;
	int y=(now-1)%n+1;
	if(x%2==0)y=(n+1)-y;
	cout<<x<<' '<<y;
	return 0;
}

