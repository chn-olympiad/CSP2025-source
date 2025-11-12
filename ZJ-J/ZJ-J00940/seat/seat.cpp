#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s=1,a[110],l;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[1]<a[i]) s++;
	}
	if(s%n==0) l=s/n,cout<<s/n;
	else l=s/n+1,cout<<s/n+1;
	cout<<" ";
	if(l%2==1) cout<<s-(l-1)*n;
	else cout<<n-s+(l-1)*n+1;
	return 0;
}
