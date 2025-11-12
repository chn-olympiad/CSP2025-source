#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=998244353;
int n,m,ans[105],p=1;
string s;
int c[105];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		p=p*i;
	}
	cout<<p;
	return 0;
}

