#include<bits/stdc++.h>
using namespace std;
int n,m,wode,a,cnt=1,hang,lie;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>wode;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a;
		if(a>wode)cnt++;
	}
	lie=ceil(1.0*cnt/n);
	hang=cnt%n;
	if(lie%2==0)
	{
		if(hang==0)cout<<lie<<' '<<1;
		else cout<<lie<<' '<<n-hang+1;
	}
	else
	{
		if(hang==0)cout<<lie<<' '<<n;
		else cout<<lie<<' '<<hang;
	}
	return 0;
}
