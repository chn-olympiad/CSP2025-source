#include<bits/stdc++.h>
using namespace std;
long long n,m,f=1;
long long s[1009];
long long k[19][19];
struct node
{
	int x;
	int y;
	int cj;
	int code;
}a[1009];
bool cmp(node a,node b)
{
	return a.cj>b.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].cj;
		a[i].code=i;
	}
	sort(a+1,a+(n*m)+1,cmp);//∞¥’’≥…º®≈≈–Ú 
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				k[j][i]=a[f].cj;
				if(a[f].code==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				f++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				k[j][i]=a[f].cj;
				if(a[f].code==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				f++;
			}
		}
	}
	return 0;
}
