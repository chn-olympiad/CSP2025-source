#include<bits/stdc++.h>
using namespace std;
int n,m,ans,s,t,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>s;
		if(!t)
		t=s;
		if(s>=t)
			ans++;
	}
	x=(ans-1)/m;
	if(x%2==0)
	cout<<x+1<<" "<<ans-x*m;
	else
	cout<<x+1<<" "<<m-(ans-x*m)+1;
	return 0;
}
