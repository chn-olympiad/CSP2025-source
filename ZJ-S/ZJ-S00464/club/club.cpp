#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100005][4],d,e,f,t,b[100005],n_1[200005],n_2[200005],n_3[200005],ans,k[100005];
void T()
{
	for(int i=1;i<=100003;i++)
	{
		n_1[i]=0;
		n_2[i]=0;
		n_3[i]=0;
	}
	ans=0;
	d=0;
	e=0;
	f=0;
	cin>>n;
	if(n!=100000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
	}
    else
    {
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
		{
			d++;
			ans+=a[i][1];
			n_1[a[i][1]-max(a[i][2],a[i][3])]++;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
		{
			ans+=a[i][2];
		    e++;
			n_2[a[i][2]-max(a[i][1],a[i][3])]++;
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
		{
		    f++;
		    ans+=a[i][3];
			n_3[a[i][3]-max(a[i][1],a[i][2])]++;
		}
	}
	if(d>n/2)
	{
		for(int i=0;i<=10003&&d>=n/2;i++)
		{
			while(n_1[i]>0)
			{
				n_1[i]--;
				ans-=i;
				d--;
			}
		}
	}
	else if(e>n/2)
	{
		for(int i=0;i<=10003&&e>=n/2;i++)
		{
			while(n_2[i]>0)
			{
				n_2[i]--;
				ans-=i;
				e--;
			}
		}
	}
	else if(e>n/2)
	{
		for(int i=0;i<=10003&&f>=n/2;i++)
		{
			while(n_3[i]>0)
			{
				n_3[i]--;
				ans-=i;
				f--;
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
    for(int i=1;i<=t;i++)
    {
    	T();
	}
}

