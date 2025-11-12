#include <bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
const int N=510,mod=998244353;
int a[N],f[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int ans=1;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=1LL*f[i-1]*i%mod;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			cnt++;
		}
	}
	//cout<<endl;
	cout<<(cnt>m?0:(f[n]-1LL*f[cnt]*f[n-cnt-1]%mod+mod)%mod);
	return 0;
}


