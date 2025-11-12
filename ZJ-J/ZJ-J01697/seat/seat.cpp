#include<bits/stdc++.h>
using namespace std;
int a[101][101];
struct st{
	int grade;
	int num;
}stu[101];
bool cmp(st x,st y)
{
	return x.grade<y.grade;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int cnt=0; 
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>stu[++cnt].grade;
			stu[cnt].num=cnt;
		}
	}
	sort(stu+1,stu+1+n*m,cmp);
	for (int j=1;j<=m;j++)
	{
		if (j%2==1)
		{
			for (int i=1;i<=n;i++)
			{
				a[i][j]=stu[cnt--].num;
				if (a[i][j]==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for (int i=n;i>=1;i--)
			{
				a[i][j]=stu[cnt--].num;
				if (a[i][j]==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
