#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define float double
const int MOD=998244353;
using namespace std;
int n,m,ans=1;
string S;
int c[500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>S;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	
	for(int i=n;i>=2;i--)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}
//161088479
