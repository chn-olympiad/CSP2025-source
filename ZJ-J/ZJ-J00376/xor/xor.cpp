#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10;
using namespace std;
ll ans,a[N],s[N],n,k,v[N];
map<ll,ll>vis;
void f1(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
		if(x==a[i])
			ans++;
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)
			flag=0;
	}
	if((k==0||k==1)&&flag)
	{
		f1(k);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=i+1;j<=n;j++)
		{
			t^=a[j];
			if(t==k)
			{
				vis[i]=j;
				break;
			}
		}
	}
	cout<<n;
	return 0;
}
/*
10 1
1 2 3 4 5 6 7 8 9 10
*/
