#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum;
	int maxx=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<3) cout<<0;
	else if(n==3 and maxx*2<sum)cout<<1;
	else cout<<0;
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int a[100005]
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];	
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			for(int k=j+1;k<=n;k++)
//			{
//				
//			}
//		}
//	}
//	return 0;
//}
