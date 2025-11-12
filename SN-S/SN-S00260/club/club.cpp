#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std;
struct node
{
	int num1,num2,num3;
}a[250];
int a2[6][250];
int T,n,f1,f2,ans,t1,t2;
int t[5];
bool cmp1(node a,node b)
{
	return a.num1>b.num1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ma=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].num1>>a[i].num2>>a[i].num3;
			if(a[i].num2!=0)
			{
				f1=1;
			}
			if(a[i].num3!=0)
			{
				f2=1;
			}
		}
		if(f1==0 && f2==0)
		{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=ma;i++)
			{
				ans+=a[i].num1;
			}
			cout<<ans<<"\n";
			ans=0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(a[i].num1,max(a[i].num2,a[i].num3));
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
