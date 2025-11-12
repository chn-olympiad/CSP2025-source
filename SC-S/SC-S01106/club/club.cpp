#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l1;
	long long l2;
	long long l3;
}a[100005];
long long b[100005],c[5];
long long d[205],e[205],f[205];
bool cmp(int a,int b)
{
	return a>b;
}
int check(int k,int n)
{
	if(k==1)
	{
		sort(d,d+n,cmp);
		return d[n-1];
	}
	else if(k==2)
	{
		sort(e,e+n,cmp);
		return e[n-1];
	}
	else if(k==3)
	{
		sort(f,f+n,cmp);
		return f[n-1];
	}
}
int main()
{
	int time;
	cin>>time;
	while(time--)
	{
		long long n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			d[i]=a[i].l1;
			e[i]=a[i].l2;
			f[i]=a[i].l3;
		} 
		for(int i=0;i<n;i++)
		{
			int f=0;
			long long kk=max(a[i].l2,a[i].l3);
			if(kk==a[i].l2) 
				f=2;
			else 
				f=3;
			b[i]=max(kk,a[i].l1); 
			if(b[i]==a[i].l1)	
				f=1;
			c[f]++; 
			if(c[f]>n/2)
			{
				ans+=b[i]-check(f,n);
				c[f]--;
			}
			else
				ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}