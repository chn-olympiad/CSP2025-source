#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
string s;
int c[505];
int a[505];
signed main(void)
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)a[i]=i;
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')continue;
			if(i-cnt-1>=c[a[i]])continue;
			cnt++;
		}
		if(cnt>=m)ans=(ans+1)%998244353;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
