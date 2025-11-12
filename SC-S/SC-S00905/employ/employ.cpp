#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int MOD=998244353;
int c[N];
int n,m;
void sove1()
{
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	 } 
	int flag=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)ans++;
		if(int(s[i])-48!=1)flag=0;
	}
//	cout<<flag;
	if(m==n&&flag==1)
	{
		sove1();
		return 0;
	}
	if(n-ans<m)cout<<0;
	return 0;
}