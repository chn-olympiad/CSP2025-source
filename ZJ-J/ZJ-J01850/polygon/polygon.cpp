#include<bits/stdc++.h>
using namespace std;
int n,ans,a[1010];
bool vis[1010]={0};
bool check()
{
	int cnt=0,sum=0,num=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			num++;
			sum+=a[i];
			cnt=max(cnt,a[i]);
		}
	}
	return (sum>cnt*2&&num>=3)?true:false;
}
void f(int i)
{
	vis[i]=1;
	if(check()) ans++;
	for(int j=i+1;j<=n;j++) f(j);
	vis[i]=0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f(1);
	cout<<ans;
	return 0;
}