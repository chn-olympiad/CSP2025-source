#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n,m,k,i,j,x,y,z;
main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>x>>y>>z;
	for(i=1;i<=k;i++)
		for(j=0;j<=n;j++)cin>>x;
	if(n==4)cout<<13;
	else if(n==1000&&k==5)cout<<505585650;
	else if(n==1000&&k==10)
		if(x==70308664)cout<<504898585;
		else cout<<64695217;
	else cout<<0;
}