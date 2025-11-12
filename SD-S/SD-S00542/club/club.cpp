#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n;

int l1,l2,l3;

long long sum;

struct sss
{
	int ma;
	int mb;
	int mab;
	int man;
//	int mbn;
}num[N];

int ans[N];

bool cmp(sss a,sss b)
{
	return a.mab<b.mab;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		int ma=n/2;
		sum=0;
		l1=0;
		l2=0;
		l3=0;
		int a,b,c;
		for (int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			if (a>=b&&b>=c)//a>=b>=c
			{
				num[i].ma=a;
				num[i].mb=b;
				num[i].mab=a-b;
				num[i].man=1;
//				num[i].mbn=2;
				l1++;
			}
			else if (a>=c&&c>=b)//a>=c>=b
			{
				num[i].ma=a;
				num[i].mb=c;
				num[i].mab=a-c;
				num[i].man=1;
//				num[i].mbn=3;
				l1++;
			}
			else if (b>=a&&a>=c)//b>=a>=c
			{
				num[i].ma=b;
				num[i].mb=a;
				num[i].mab=b-a;
				num[i].man=2;
//				num[i].mbn=1;
				l2++;
			}
			else if (b>=c&&c>=a)//b>=c>=a
			{
				num[i].ma=b;
				num[i].mb=c;
				num[i].mab=b-c;
				num[i].man=2;
//				num[i].mbn=3;
				l2++;
			}
			else if (c>=a&&a>=b)//c>=a>=b
			{
				num[i].ma=c;
				num[i].mb=a;
				num[i].mab=c-a;
				num[i].man=3;
//				num[i].mbn=1;
				l3++;
			}
			else if (c>=b&&b>=a)//c>=b>=a
			{
				num[i].ma=c;
				num[i].mb=b;
				num[i].mab=c-b;
				num[i].man=3;
//				num[i].mbn=2;
				l3++;
			}
			sum+=num[i].ma;
		}
		sort (num+1,num+1+n,cmp);
		if (l1>ma)
		{
			int i=1;
			while (l1>ma)
			{
				if (num[i].man==1)
				{
					l1--;
					sum-=num[i].mab;
				}
				i++;
			}
		}
		else if (l2>ma)
		{
			int i=1;
			while (l2>ma)
			{
				if (num[i].man==2)
				{
					l2--;
					sum-=num[i].mab;
				}
				i++;
			}
		}
		else if (l3>ma)
		{
			int i=1;
			while (l3>ma)
			{
				if (num[i].man==3)
				{
					l3--;
					sum-=num[i].mab;
				}
				i++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

