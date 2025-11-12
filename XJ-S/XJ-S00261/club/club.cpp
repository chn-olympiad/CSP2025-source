#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
}q[100005];
bool cmp(node a,node b)
{
	return a.a>b.a; 
}
long long int n,i,sum,t,a[100005],b[100005],c[100005],j;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			q[i].a=a[i];q[i].b=b[i];q[i].c=c[i];
		}
		if(n!=2)
		{
			sort(q+1,q+1+n,cmp);
			sum=q[1].a;
		}		
		else
		{
			i=1;
			if(sum<a[i]+b[i+1])
			{
				sum=a[i]+b[i+1];
			}
			if(sum<a[i]+c[i+1])
			{
				sum=a[i]+c[i+1];
			}
			if(sum<b[i]+a[i+1])
			{
				sum=b[i]+a[i+1];
			}
			if(sum<b[i]+c[i+1])
			{
				sum=b[i]+c[i+1];
			}
			if(sum<c[i]+a[i+1])
			{
				sum=c[i]+a[i+1];
			}
			if(sum<c[i]+b[i+1])
			{
				sum=c[i]+b[i+1];
			}
		}
		cout<<sum<<endl;
	}
	return 0; 
} 
