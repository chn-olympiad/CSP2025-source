#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=5e2+10;
const ll mod=998244353;

string s;
int vis[N],a[N],b[N],cnt[N],ans,n,m;
ll fac[N];

void dfs(int u)
{
	if(u>n)
	{
		int c=0;
		for(int i=1;i<=n;i++) if(s[i]=='1'&&i-1-c<a[b[i]]) c++;
		if(c>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			b[u]=i;
			dfs(u+1);
			vis[i]=0;
			b[u]=0;
		}
	}
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i=1;i<=n;i++) cin >> a[i];
    s=" "+s;
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0'||a[i]==0)
            {
                cout << 0 << '\n';
                return 0;
            }
        }
        cout << fac[n] << '\n';
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+cnt[i];
        ll sum=1,c=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                if(cnt[i-1]>c) sum=sum*(cnt[i-1]-c)%mod;
                else sum=0;
                c++;
            }
        }
        sum=sum*fac[n-c]%mod;
        cout << (fac[n]-sum+mod)%mod << '\n';
        return 0;
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}