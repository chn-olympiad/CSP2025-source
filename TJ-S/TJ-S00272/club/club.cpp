#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],maxid[100005],cnt[20004],ans,zong,maxa[100005];
bool cmp(int q,int w)
{
	if (q>=w)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][1]>=a[i][2])
			{
				if (a[i][1]>=a[i][3])
				{
					maxid[i]=1;
				}
				else
				{
					maxid[i]=3;
				}
			}
			else if (a[i][2]>=a[i][3])
			{
				maxid[i]=2;
			}
			else
			{
				maxid[i]=3;
			}
			zong+=a[i][maxid[i]];
			maxa[i]=a[i][maxid[i]];
		}
		
		if (n==2)
		{
			if (maxid[1]!=maxid[2])
			{
				cout<<a[1][maxid[1]]+a[2][maxid[2]]<<endl;
			}
			else
			{
				int a1=-1,a2=-1;
				for (int i=1;i<=3;i++)
				{
					if (a[1][i]==a[1][maxid[1]])
					{
						continue;
					}
					else
					{
						a1=max(a1,a[1][i]);
					}
				}
				for (int i=1;i<=3;i++)
				{
					if (a[2][i]==a[2][maxid[2]])
					{
						continue;
					}
					else
					{
						a2=max(a2,a[2][i]);
					}
				}
				if (a[1][maxid[1]]+a2>=a1+a[2][maxid[2]])
				{
					cout<<a[1][maxid[1]]+a2<<endl;
				}
				else
				{
					cout<<a1+a[2][maxid[2]]<<endl;
				}
			}
		}
		
		else if (a[1][2]==0 && a[1][3]==0 && a[2][2]==0 && a[2][3]==0 && a[3][2]==0 && a[3][3]==0 && a[4][2]==0 && a[4][3]==0)
		{
			sort(maxa+1,maxa+1+n,cmp);
			for (int i=1;i<=n/2;i++)
			{
				ans+=maxa[i];
			}
			cout<<ans<<endl;
		}
		
		else
		{
			cout<<zong<<endl;
		}
	}
	return 0;
}
