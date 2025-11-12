#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=5e2+5;
int n,m,c[N],sum,ans=1,f=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(s[i]=='0') f=0;
	}
	if(!f)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}

