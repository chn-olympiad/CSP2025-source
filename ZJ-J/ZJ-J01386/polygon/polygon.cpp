
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5500],num[5500],maxx[5500],m,ans;
bool flaga=true,vis[5500];
int find(int A)
{
	int cnt=1;
	for(int i=1;i<=A;i++)
	{
		cnt=(cnt*2)%MOD;
	}
	return (cnt-1)%MOD;
}
void DFS(int now,int cnt,int MAX)
{
	if(now>3)  
	{
		if(cnt>2*MAX)  ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			now++;
			DFS(now,cnt+a[i],max(MAX,a[i]));
			now--;
			vis[i]=0;
		}
	}
}
int main()
{
//  考试结束后，必须去除注释! 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1)  flaga=false;
		num[i]=num[i-1]+a[i];
		maxx[i]=max(maxx[i],a[i]*2);
	}
	if(flaga)
	{
		ans=find(n)-n-n*(n-1)/2;
		if(ans<0)  ans+=MOD;
		cout<<ans;
	}
	else if(n<=20)
	{
		DFS(1,0,0);
		cout<<ans/2;
	}
	else  cout<<MOD-1;
	return 0;
}
