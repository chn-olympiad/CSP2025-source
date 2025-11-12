//林靖轩 SN-S00418 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mo=998244353;
int n,m,ans=1;
int c[510];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		ans*=i,ans%=mo;
	cout<<ans%mo;
	return 0;
}

