#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 20;
const int U = 18;

int n,m,c[N],s[N];
int f[N][1<<U+1];
string s1;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++)
		s[i]=s1[i-1]-'0';
	for(int i=0;i<n;i++)
		cin>>c[i];
	f[0][0]=1;
	for(int S=0;S<(1<<n);S++)
		for(int j=0;j<=__builtin_popcount(S);j++)
		{
//			cout<<j<<" "<<S<<" "<<f[j][S]<<"\n";
			int day=__builtin_popcount(S)+1;
			for(int k=0;k<n;k++)
				if(!((S>>k)&1))
				{
					if(j>=c[k]||!s[day])
						f[j+1][S|(1<<k)]+=f[j][S];
					else f[j][S|(1<<k)]+=f[j][S];
				}
		}
	int ans=0;
	for(int j=0;j<=n;j++)
		if(n-j>=m) ans+=f[j][(1<<n)-1];
	cout<<ans;
	return 0;
}
