#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=5e2+10;
const ll mod=998244353;
#define test
int n,m;
char cs[MAX];
bool s[MAX];
int cnt;
int bcnt;
ll ans=1;
int c[MAX];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	#ifdef test
	freopen("employ3.in","r",stdin);
	#else
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	cin>>n>>m;
	cin>>cs;
	for(int i=0;i<n;i++)
		s[i]=cs[i]=='1'?++cnt:0;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i])bcnt++;
	}
	if(cnt<n)
	{
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	ans=ans*i%mod;
	cout<<ans;
}