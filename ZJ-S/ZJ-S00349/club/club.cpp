#include<bits/stdc++.h>
using namespace std;
int t,n,s,s1,s2,s3,p[20],sum,x,y,z,MAX,a[100010][5],b[100010][5];
struct node
{
	int a,b;
	int operator<(node x)const
	{
		return a<x.a;
	}
};
void solov()
{
	priority_queue<node> q[5];
	scanf("%d",&n);MAX=0;s1=0;s2=0;s3=0;
	for(int i=1;i<=n;i++)
	{	
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		b[i][1]=max(a[i][1],max(a[i][2],a[i][3]));
		b[i][3]=min(a[i][1],min(a[i][2],a[i][3]));
		b[i][2]=a[i][1]+a[i][2]+a[i][3]-b[i][1]-b[i][3];
		MAX+=b[i][1];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		{
			s1++;
			q[1].push({b[i][2]-b[i][1],i});
			q[1].pop();
			if(s1>n/2)
			{
				s1--;
				node x=q[1].top();
				if(a[x.b][2]==x.a)s2++,q[2].push({b[x.b][3]-b[x.b][2],x.b});
				else s3++,q[3].push({b[x.b][3]-b[x.b][2],x.b});
				MAX+=x.a;
			}
		}
		else if(a[i][1]<=a[i][2]&&a[i][2]>=a[i][3])
		{
			s2++;
			q[2].push({b[i][2]-b[i][1],i});
			if(s2>n/2)
			{
				s1--;
				node x=q[2].top();
				q[2].pop();
				if(a[x.b][1]==x.a)s1++,q[1].push({b[x.b][3]-b[x.b][2],x.b});
				else s3++,q[3].push({b[x.b][3]-b[x.b][2],x.b});
				MAX+=x.a;
			}
		}
		else if(a[i][3]>=a[i][2]&&a[i][1]<=a[i][3])
		{
			s3++;
			q[3].push({b[i][2]-b[i][1],i});
			if(s3>n/2)
			{
				s1--;
				node x=q[3].top();
				q[3].pop();
				if(a[x.b][2]==x.a)s2++,q[2].push({b[x.b][3]-b[x.b][2],x.b});
				else s1++,q[1].push({b[x.b][3]-b[x.b][2],x.b});
				MAX+=x.a;
			}
		}
	}
	cout<<MAX<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solov();
	return 0;
}
