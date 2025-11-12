#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[550],n,m,c[550];
long long tot,ans;
bool b[550];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x; cin>>x;
		if(x=='0') b[i]=0;
		else b[i]=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i],a[i]=i;
	do
	{
		tot=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0||tot>=c[a[i]])
			{
				tot++;
				if(n-tot<m) break;
			}
		}
		if(n-tot>=m) ans++;
		ans%=mod;
	}
	while(next_permutation(a+1,a+n+1));
	cout<<ans;
return 0;
}
