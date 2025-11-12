#include<bits/stdc++.h>
using namespace std;
struct club
{
	int m[4];
	int max1;
	bool k;
};
int mx(int a1,int a2,int a3)
{
	if(a1>=a2)
	{
		if(a1>=a3)	return 1;
		else		return 3;
	}
	else
	{
		if(a2>=a3)	return 2;
		else		return 3;
	}
}
bool mx1(int a1,int a2)
{
	if(a1>=a2)	return 1;
	else		return 0;
}
bool cmp1(club a1,club a2)
{
	return a1.max1>a2.max1;
}
bool cmp2(club a1,club a2)
{
	return a1.m[1]<a2.m[1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,xc=0,cnt1=0,cnt2=0;
		bool flagA=1;
		long long sum=0;
		cin>>n;
		club x[n+10];
		bool k[n+10];
		club a[n+10];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].m[1]>>a[i].m[2]>>a[i].m[3];
			if(a[i].m[3]!=0||a[i].m[2]!=0)	flagA=0;
			x[i].m[1]=a[i].m[1];
			a[i].k=mx1(a[i].m[1],a[i].m[2]);
			if(a[i].k==1)	cnt1++;
			else		cnt2++;
			a[i].max1=max(a[i].m[1],a[i].m[2]);
		}
		if(n==2)
		{
			int k1=mx(a[1].m[1],a[1].m[2],a[1].m[3]);
			int k2=mx(a[2].m[1],a[2].m[2],a[2].m[3]);
			sum+=a[1].m[k1]; 
			if(k1!=k2)
			{
				sum+=a[2].m[k2];
				cout<<sum<<endl;
				continue;
			}
			else
			{
				int a1=a[1].m[k1];
				int a2=a[2].m[k2];
				a[1].m[k1]=-1;
				a[2].m[k2]=-1;
				int k12=mx(a[1].m[1],a[1].m[2],a[1].m[3]);
				int k22=mx(a[2].m[1],a[2].m[2],a[2].m[3]);
				if(sum+a[2].m[k22]>=sum-a1+a2+a[1].m[k12])
				{
					sum=sum+a[2].m[k22];
				}
				else
				{
					sum=sum-a1+a2+a[1].m[k12];
				}
				cout<<sum<<endl;
				continue;
			}
		}
		else if(flagA)
		{
			sort(x+1,x+n+1,cmp2);
			for(int i=n;i>n/2;i--)
			{
				sum+=x[i].m[1];
			}
			cout<<sum<<endl;
			continue;
		}
		else
		{
			if(cnt1<cnt2)
			{
				for(int i=1;i<=n;i++)
				{
					swap(a[i].m[1],a[i].m[2]);
					a[i].k=!a[i].k;
				}
			}
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++)
			{
				if(a[i].k==1)
				{
					if(xc<n/2)
					{
						sum+=a[i].m[1];
						xc++;
						x[xc].m[1]=a[i].m[1];
						x[xc].m[2]=a[i].m[2];
					}
					else
					{
						if(sum-x[xc].m[1]+a[i].m[1]+x[xc].m[2]>sum+a[i].m[2])
						{
							sum=sum-x[xc].m[1]+a[i].m[1]+x[xc].m[2];
							x[xc].m[1]=a[i].m[1];
							x[xc].m[2]=a[i].m[2];
						}
						else
						{
							sum+=a[i].m[2];
						}
					}
				}
				else
				{
					sum+=a[i].max1;
				}
			}
			cout<<sum<<endl;
			continue;
		}
	} 
	return 0;
} 
