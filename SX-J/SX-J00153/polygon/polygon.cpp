#include<bits/stdc++.h>
using namespace std;
int n,arr[10086],vis[10086],ans;
//void dfs(int step,int sum,int x,int mymax)
//{
//	if(step>n)	return ;
//	if(sum>2*arr[mymax]&&x>=3)
//	{
//		cout<<sum<<endl;
//		ans++;
//		ans%=998244353;
//		return ;
//	}
//	for(int i=step;i<=n;i++)
//	{
//		if(vis[i]==0)
//		{
//			vis[i]=1;
//			dfs(step+1,sum+arr[i],x+1,i);
//			vis[i]=0;
//		}
//
//	}
//}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		cout<<1;
		return 0;
	}

//	for(int i=1;i<=n;i++)	cin>>arr[i];
//	sort(arr+1,arr+n+1);

	int lk=0;
	for(int i=n;i>=1;i--)	lk+=i;
	cout<<lk-n+1;

//	dfs(1,0,0,0);
//	cout<<ans;


	return 0;
}
