#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=15;
int c[maxn],a[maxn];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k,ans=0;cin>>n>>k;
	string s;cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	s=' '+s;
	for(int i=1;i<=n;i++) a[i]=i;
	do
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(c[a[i]]<=cnt||s[i]=='0') cnt++;
			else sum++;
		}
		ans+=(sum>=k);
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
	return 0;
}
