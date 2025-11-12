#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],b[100005],c[100005];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		ans=0;
		int num1=0,num2=0,num3=0,pos=0;
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin >> a[i][j]; 
			}
			if(a[i][3]!=0)
			{
				pos=1;
			} 
			long long w=max(a[i][1],max(a[i][2],a[i][3]));
			if(w==a[i][1])
			{
				num1++;
				b[i]=1;
			}
			else if(w==a[i][2])
			{
				num2++;b[i]=2;
			}
			else if(w==a[i][3])
			{
				num3++;b[i]=3;
			}
			ans+=w;
		}
		if(!(num1>n/2||num2>n/2||num3>n/2))
		{
			cout << ans << endl;
			continue;
		}
		if(!pos)
		{
			ans=0;
			for (int i=1;i<=n;i++)
			{
				ans+=a[i][1];
			}
			for (int i=1;i<=n;i++)
			{
				c[i]=a[i][1]-a[i][2];
			}
			sort(c+1,c+n+1);
			for (int i=1;i<=n/2;i++)
			{
				ans-=c[i];
			}
			cout << ans << endl;
			continue;
		}
		if(n==2)
		{
			cout << max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2]))))) << endl;
			continue;
		}
		int k=0,p=0;
		if(num1>n/2)
		{
			k=num1-n/2;p=1;
		}
		else if(num2>n/2)
		{
			k=num2-n/2;p=2;
		}
		else
		{
			k=num3-n/2;p=3;
		}
		for (int i=1;i<=n;i++)
		{
			if(p==1&&b[i]==1)
			{
				c[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(p==2&&b[i]==2)
			{
				c[i]=a[i][2]-max(a[i][1],a[i][3]); 
			}
			else if(p==3&&b[i]==3)
			{
				c[i]=a[i][3]-max(a[i][1],a[i][2]);
			}
			else 
			{
				c[i]=0x3f;
			}
		}
		sort(c+1,c+n+1);
		for (int i=1;i<=k;i++)
		{
			ans+=c[i];
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
*/
