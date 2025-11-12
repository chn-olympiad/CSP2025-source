#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[400005],sum=0,mx=1;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i],mx=min(mx,a[i]);
	for(int i=1;i<s.size();i++) sum+=(1-(s[i]-'0'));
	if(m+sum>n) cout<<0;
	else
	{
		int y=1;
		for(int i=1;i<=n;i++) y*=i;
		cout<<y;
	}
	return 0;
}