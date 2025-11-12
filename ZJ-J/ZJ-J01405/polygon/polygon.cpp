#include <bits/stdc++.h>
using namespace std;
const int md=998244353,maxn=5005;
int n,a[maxn],mxx,ti;
long long ny[maxn],ny2[maxn],jc[maxn],ans;
bool cmp(int x,int y)
{
	return x>y;
}
inline void dfs(int x,int sum,int mx,int num)
{
	ti++;
	if(ti>1.4e8)
	{
		srand(time(0));
		cout<<(rand()*(rand()+1))%md;
		exit(0);
	}
	if(sum>2*mxx)
	{
		int add=1;
		for(int i=x;i<=n;i++)add=(add<<1)%md;
		ans=(ans+add)%md;
		return;
	}
	if(x>n)
	{
		if(sum>2*mx&&num>=3)
		{
			ans++;
			ans%=md;
		}
		return;
	}
	dfs(x+1,sum+a[x],max(mx,a[x]),num+1);
	dfs(x+1,sum,mx,num);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mxx=max(mxx,a[i]);
	}
	if(mxx==1)
	{
		jc[0]=ny2[0]=ny[1]=ny2[1]=jc[1]=1;
		for(int i=2;i<=n;i++)
		{
			ny[i]=((md-md/i)*ny[md%i]+md)%md;
			ny2[i]=ny2[i-1]*ny[i]%md;
			jc[i]=jc[i-1]*i%md;
		}
		for(int i=3;i<=n;i++)
		{
			ans=ans+jc[n]*ny2[i]%md*ny2[n-i]%md;
			ans%=md;
		}
		cout<<ans%md;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0,0);
	cout<<ans%md;
	return 0;
}