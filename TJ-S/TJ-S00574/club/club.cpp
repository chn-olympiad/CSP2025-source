#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#define ll long long
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	int f=1;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(!(b[i]==c[i]&&b[i]==0))
			{
				f=0;
			}
		}
		if(f==1)
		{
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--)
			{
				ans+=a[i];
			}
			cout<<ans<<"\n";
			
		}else if(n==2)
		{
			int ans=0;
			ans=max(a[1]+b[2] , max(a[1]+c[2] , max(b[1]+a[2] , max(b[1]+c[2] , max(c[1]+a[2] , c[1]+b[2])))));
			cout<<ans<<"\n";
			
		}
	}
	return 0;
}

