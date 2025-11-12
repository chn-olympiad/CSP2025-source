#include<bits/stdc++.h>
#define inf LLONG_MAX
using namespace std;
typedef long long ll;
typedef __int128 llong;
const ll N=5e2+5;
ll n,m,c[N],ans,a[N],tot;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
		tot+=(s[i-1]=='1');
	}
	if(m==1)
	{
		
	}
//	if(tot==n)
//	{
//		ans=1;
//		for(int i=1;i<=n;i++)
//		{
//			ans*=i;
//			ans%=998244353;
//		}
//		cout<<ans;
//		return 0;
//	}
	do
	{
		ll k=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||k>=c[a[i]])
			{
				k++;
			}
		}
		if(n-k>=m)
		{
//			for(int i=1;i<=n;i++)
//			{
//				cout<<a[i]<<' ';
//			}
//			cout<<"\n";
			ans++;
			ans%=998244353;
		}
	}
	while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}

