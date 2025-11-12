#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int a[N];
int lewis(int u)
{
	if(u==0) return 1;
	if(u==1) return 1;
	int ans=1;
	for(int i=2;i<=u;i++)
	{
		ans*=i;
		ans%=mod;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool fa=true;
	for(int i=0;i<n;i++)
		if(s[i]=='0') fa=false;
	if(fa)
	{
		cout<<lewis(n)<<endl;
	}
	else cout<<"it's been a long way, without you my friend"<<endl;
	return 0;
}

