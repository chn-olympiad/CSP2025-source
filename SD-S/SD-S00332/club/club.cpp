#include <bits/stdc++.h>
using namespace std;
int a[100010][5],b[100010],a1[5],a2[100010];
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=3;j++)
			    cin>>a[i][j];
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			int maxn=-100000;
			for(int j=1;j<=3;j++)
			{
				b[j]=a[i][j];
				maxn=max(maxn,b[j]);
			}
			ans=ans+maxn;			
		}
		cout<<ans;
	}
	return 0;
}

