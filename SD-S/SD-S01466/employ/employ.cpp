#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505,mod=998244353;
int n,m;
int a[N],c[N],sum[N];
char s[N];
int ck[N],flag[N],ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int wt=0,cp=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<ck[i]<<" ";
			if(ck[i]<=wt)
			{
				wt++;
				cp++;
				continue;
			}
			if(a[i]==0)cp++;
			wt+=(a[i]==0);
		}
		cout<<endl;
		if(n-cp>=m)ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		flag[i]=1;
		ck[x]=c[i];
		dfs(x+1);
		flag[i]=0;
		ck[x]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		a[i]=s[i]-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<endl;
	}
	else cout<<0;
	return 0;
 } 
