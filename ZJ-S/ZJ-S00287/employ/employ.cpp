#include <bits/stdc++.h>
#define N 510
#define mod 998244353
using namespace std;
int n,m;
string s;
int c[N];
int cnt;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i],cnt+=(c[i]!=0);
	if(cnt<m) puts("0");
	else
	{
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}
