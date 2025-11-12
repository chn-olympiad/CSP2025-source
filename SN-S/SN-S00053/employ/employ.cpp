#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
bool b[505],ts1=1,ts2=1;
int c[505],da=1;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) b[i+1]=(s[i]=='1'?1:0);
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0) ts2=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) ts1=0;
	}
	if(n==m)
	{
		if(ts2&&ts1)
		{
			da=1;
			for(int i=1;i<=n;i++) da=(da*i)%mod;
			cout<<da;
		}
		else cout<<0;
		return 0;
	}
	if(ts2)
	{
		da=1;
		for(int i=1;i<=n;i++) da=(da*i)%mod;
		cout<<da; 
	} 
	return 0;
}
