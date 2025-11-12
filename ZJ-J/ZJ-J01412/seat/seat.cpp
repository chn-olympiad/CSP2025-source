#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1]) cnt++;
	int l=cnt/n+1;
	int x=cnt%n+1;
	if(l%2==0) cout<<l<<" "<<n-x+1;
	else cout<<l<<" "<<x;
	return 0;
}