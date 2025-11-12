#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
const int maxn=510;
typedef long long ll;
int n,m,c[maxn],vis[maxn],cnt;
char s[510];
ll ans;

void dfs(int step,int give_up)
{
	//cout<<give_up<<endl;
	if(step==n)
	{
		if((n-give_up)>=m) ans++;
		ans%=modd;
		return;
		//cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(give_up<c[i]&&s[step+1]=='1')
		{
			vis[i]=1;
			dfs(step+1,give_up);
			vis[i]=0;
		}
		else
		{
			vis[i]=1;
			//cout<<i<<" ";
			dfs(step+1,give_up+1);
			vis[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
