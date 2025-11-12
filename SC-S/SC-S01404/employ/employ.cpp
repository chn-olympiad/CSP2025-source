#include<bits/stdc++.h>
#define int long long 
using namespace std;
int s[505],c[505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')	num++;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int ans=1;
	for(int i=1;i<=num;i++)	
		ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
} 