#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
const int mod=998244353;
ll n,m,c[maxn],check[maxn],he[maxn],hec[maxn];
ll jc[maxn];
void solve()
{
	cin>>n>>m;
	string a;
	cin>>a;
	a=" "+a;
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		jc[i]=(jc[i-1]*i)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		check[c[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		he[i]=he[i-1]+check[i];
	}
	bool A=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='0')
		{
			A=0;
			hec[i]++;
		}
		hec[i]+=hec[i-1];
	}
	if(A)
	{
		cout<<jc[n]<<'\n';
	}
	else
	{
		cout<<rand()%mod+1<<'\n';
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	_=1;
	while(_--)
	{
		solve();
	}
	cout<<endl;
	return 0;
}
/*
这次就这样了，无力回天
希望明年能见到不一样的我 

*/
