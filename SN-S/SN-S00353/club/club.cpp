//李梓煦 SN-S00353 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005],b[100005],c[100005],x,y,z,cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%lld",&n);cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]&&x<n/2)
			{
				cnt+=a[i];x++;
			}
			else if(b[i]>a[i]&&b[i]>c[i]&&y<n/2)
			{
				cnt+=b[i];y++;
			}
			else if(c[i]>b[i]&&c[i]>a[i]&&z<n/2)
			{
				cnt+=c[i];z++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
