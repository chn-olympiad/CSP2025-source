#include<bits/stdc++.h>
using namespace std;

int t,n,b,sum23=0,sum3,sum31,sum32,cur1,cur3,cur2,a[100005][5],a23[100005],sum,d,d1,d2,id1[100005],id2[100005],id3[100005],sum1,sum2,sum33;
struct stu
{
	int id,c[5],maxn;
}a3[100005];
bool cmp(int x,int y)
{
	return x>y;
}
bool cmp1(stu x,stu y)
{
	if(x.maxn!=y.maxn)
	{
		return x.maxn<y.maxn;
	}
	return x.c[x.maxn]>y.c[y.maxn];
}
bool flag23=0,flag3=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	cin>>t;
	while(t--)
	{
		sum23=0,cur1=0,cur2=0,sum31=0,sum32=0,sum3=0,sum1=0,sum2=0,sum33=0,sum=0,cur3=0;
		flag23=0,flag3=0;
		cin>>n;
		b=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]!=0&&(j==2||j==3))
				{
					flag23=1;
				}
				if(a[i][j]!=0&&j==3)
				{
					flag3=1;
				}
			}
		}
		if(flag23==0)
		{
			for(int i=1;i<=n;i++)
			{
				a23[i]=a[i][1];
			}
			sort(a23+1,a23+n+1,cmp);
			for(int i=1;i<=b;i++)
			{
				sum23+=a23[i];
			}
			cout<<sum23<<endl;
		}
		else if(flag3==0)
		{
			for(int i=1;i<=n;i++)
			{
				a3[i].id=i;
				a3[i].c[1]=a[i][1];
				a3[i].c[2]=a[i][2];
				if(a[i][1]>a[i][2])
				{
					a3[i].maxn=1;
				}
				else if(a[i][1]<a[i][2])
				{
					a3[i].maxn=2;
				}
			}
			sort(a3+1,a3+n+1,cmp1);
			for(int i=1;i<=n;i++)
			{
				if(a3[i].maxn==2)
				{
					d=i;
					break;
				}
			}
			int y=min(b,d-1);
			for(int i=1;i<=y;i++)
			{
				sum31+=a3[i].c[1];
			}
			y=min(b+d,b+d-1);
			for(int i=d;i<=y;i++)
			{
				sum32+=a3[i].c[2];
			}
			if(sum31>sum32)
			{
				for(int i=1;i<=b;i++)
				{
					sum3+=a3[i].c[1];
				}
				for(int i=b+1;i<=n;i++)
				{
					sum3+=a3[i].c[2];
				}
				cout<<sum3<<endl;
			}
			else if(sum31<sum32)
			{			
				int x=max(d+b-1,n);
				for(int i=d;i<=x;i++)
				{
					sum3+=a3[i].c[2];
				}
				for(int i=1;i<=d;i++)
				{
					sum3+=a3[i].c[1];
				}
				cout<<sum3<<endl;
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					sum3+=a3[i].c[a3[i].maxn];
				}
				cout<<sum3<<endl;
			}
		} 
		else
		{
			cout<<rand();
		}
	}
	return 0;
}
