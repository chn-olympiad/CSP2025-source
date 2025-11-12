#include<bits/stdc++.h>
using namespace std;
long long n,a[100000005],ans=0;
//int re(int h)
//{
//	int l=1,r=n,m;
//	while(l<=r)
//	{
//		m=(l+r)/2;
//		if(a[m]>h)
//		{
//			r=mid-1;
//		}else {
//			l=mid+1;
//		}
//	}
//	return m;
//}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[3])
	{
		cout<<1;
	}else cout<<0;
	return 0;
 } 
