#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,arr[5005],sum,maxx,ans,a[5005];
bool fmaxx,tp;
bool f(int step)
{
	if(sum>maxx*2&&step>=3)
	{
//  		for(int i=1;i<=step;i++)
//			cout<<a[step]<<' ';
//		cout<<endl;
		//cout<<"-> "<<step<<" "<<sum<<" "<<maxx<<endl;
		return true;
	}
	else
		return false;
}
void dfs(int step)
{
	if(f(step))
			ans=ans%P+1;
	if(step>n)
	{
		return ;
	}
	for(int i=a[step-1]+1;i<=n;i++)
	{
		int t=maxx;
		fmaxx=0;
		a[step]=i;
		if(arr[i]>maxx)
			maxx=arr[i],fmaxx=1;
		sum+=arr[i];

		dfs(step+1);
		sum-=arr[i];
		if(fmaxx)
			maxx=t;
	}
}
void tpdfs(int step)
{
	if(step>n)
	{
		return ;
	}
	for(int i=a[step-1]+1;i<=n;i++)
	{
		a[step]=i;
		if(step>=3)
		ans++;
		tpdfs(step+1);
	}
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	tp=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=1)
			tp=1;
	}
	if(tp==0)
	{
		tpdfs(1);
		cout<<ans<<" ";
		//ans=0;
		//dfs(1);
		//cout<<ans;
		return 0;
	}
	maxx=-1;
	sum=0;
	dfs(1);
	cout<<ans%P;
    return 0;
}