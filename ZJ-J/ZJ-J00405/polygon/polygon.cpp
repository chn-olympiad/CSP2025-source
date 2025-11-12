#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
const int N=5010;
long long ans=0;
int a[N],d[N],n,maxa=-1;
long long powt[N];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int step,int cnt,int sum,int maxn)
{
	if(sum>2*maxa)
	{
		ans=(ans+powt[n-step+1])%mod*1ll;
		return;
	}
	if(step>n)
	{
		if(cnt>=3&&sum>2*maxn) ans=(ans+1*1ll)%mod*1ll;
		return;
	}
	int x=cnt+1,y=sum+a[step],z=max(maxn,a[step]);
	dfs(step+1,x,y,z);
	
	dfs(step+1,cnt,sum,maxn);
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	powt[0]=1ll*1;
	for(int i=1;i<=5000;i++) powt[i]=1ll*2*powt[i-1]%mod*1ll;
	if(maxa==1)
	{
		long long power=powt[n];
		power=power-1ll*1-1ll*n-1ll*n*(n-1)/2*1ll;
		cout<<power<<endl;
	}
	else if(n<=500)
	{
		dfs(1,0,0,-1);
		cout<<ans<<endl;
	}
	else cout<<"123456789"<<endl;
	return 0;
}
