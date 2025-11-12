#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[105][105],a[1050];
int mark;
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	mark=a[1];
	sort (a+1,a+1+n*m,cmp);
	if (mark==a[n*m])
	{
		cout<<m<<" "<<n;
		return 0;
	}
	int i=1;
	while (i<=n*m)
	{
		for (int j=1;j<=m;j++)
		{
			if (j%2==1)
			{
				for (int k=1;k<=n;k++)
				{
					v[j][k]=a[i];
					if (v[j][k]==mark)
					{
						cout<<j<<" "<<k;
						return 0;
					}
					i++;
					continue;
				}
			}
			else
			{
				for (int k=n;k>=1;k--)
				{
					v[j][k]=a[i];
					if (a[i]==mark)
					{
						cout<<j<<" "<<k;
						return 0;
					}
					i++;
					continue;
				}
			}
		}
	}
	return 0;
}