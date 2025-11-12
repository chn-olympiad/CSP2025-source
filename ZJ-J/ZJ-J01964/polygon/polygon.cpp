#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],pre[N],dig[1001],ans,dp[N];
bool vis[1001];
//64pts 
void cz(int x)
{
	int cnt=0;
	while(x)
	{
		vis[++cnt]=x%2;
		x/=2;
	}
}
void baoli()
{
	bool ly=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			ly=1;
			break;
		}
	}
	if(ly==0)
	{
		cout<<"0\n";
		return;
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)vis[j]=0;
		cz(i);
		int cnt=0;
		for(int j=1;j<=n;j++)if(vis[j])dig[++cnt]=a[j];
		if(cnt<3)continue;
		int maxn=dig[cnt],sum=0;
		for(int j=1;j<=cnt;j++)sum+=dig[j];
		if(sum>2*maxn)ans++;
	}
	cout<<ans<<"\n";
	return;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	baoli();
	
	return 0;
}
