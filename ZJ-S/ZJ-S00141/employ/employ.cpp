#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[501];
int c[501];
int ans=1;

void solve()
{
	if(m==n) 
	{
		cout<<0;
		return;	
	}
	if(m==1)
	{
		cout<<n; 
		return;
	} 
	for(int i=1;i<=n;i++) ans=ans*c[i]%998244353;
	cout<<ans;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	solve();
	return 0;
}

