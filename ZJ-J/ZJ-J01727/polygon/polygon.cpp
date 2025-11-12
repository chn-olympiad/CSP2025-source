//#include<bits/stdc++.h>
//using namespace std;
//int n,a[5001],re[5001];
//long long ans;
//long long g8=998244353;
//void sb(int u,int t)
//{
//	if(u+1>n)
//	{
//		int sum=0,maxx=-7891;
//		for(int i=1;i<t;i++)cout<<a[re[i]]<<" ";
//		cout<<endl;
//		for(int i=1;i<t;i++)sum+=a[re[i]],maxx=max(maxx,a[re[i]]);
//		if(sum>2*maxx)ans++;
//		return;
//	}
//	for(int i=u+1;i<=n;i++)
//	{
//		re[t]=i;
//		sb(i,t+1);
//	}
//}  
//int main()
//{
////	freopen("polygon.in","r",stdin);
////	freopen("polygon.out","w",stdout);
//	cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	sb(0,0);
//	cout<<ans%g8;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n,a[5001],re[5001],ans;
void sb(int u,int t,int x)
{
	if(u+1>x)
	{
		int sum=0,maxx=-7891;
		for(int i=1;i<t;i++)sum+=a[re[i]],maxx=max(maxx,a[re[i]]);
		if(sum>2*maxx&&t-1==x)
		{
			ans++;
		}
		return;
	}
	for(int i=u+1;i<=n;i++)
	{
		re[t]=i;
		sb(i,t+1,x);
	}
}  
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		sb(0,1,i);
	}
	cout<<ans;
	return 0;
}
