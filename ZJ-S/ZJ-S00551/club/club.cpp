#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=4;
int t[M];
int n;
struct c_node
{
	int num;
	int id;
}c[N];
struct node
{
	int n1;
	int n2;
	int n3;
	int s1;
	int s2;
	int s3;
	int s1n;
	int s2n;
	int s3n;
	int c12;
	int c13;
	int c23;
 }a[N];
 bool cmp(c_node A,c_node B)
 {
 	return A.num<B.num;
 }
int solve()
{
	for(int i=1;i<=n;i++)
	{
		t[a[i].s1]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i].s1n; 
	}
	if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2)
	{
		return sum;
	}
	int x;
	if(t[1]>t[2]&&t[1]>t[3])
	{
		x=1;
	}
	if(t[2]>t[1]&&t[2]>t[3])
	{
		x=2;
	}
	if(t[3]>t[1]&&t[3]>t[2])
	{
		x=3;
	}
	int more=t[x]-n/2;
	int cnum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].s1==x)
		{
			cnum++;
			c[cnum].num=a[i].c12;
			c[cnum].id=i;
		 } 
	}
	sort(c+1,c+cnum+1,cmp);
	for(int i=1;i<=more;i++)
	{
		sum-=c[i].num;
	 } 
	return sum;
}
void init()
{
	t[1]=t[2]=t[3]=0;
}
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].n1,&a[i].n2,&a[i].n3);
			if(a[i].n1>=a[i].n2&&a[i].n2>=a[i].n3)
			{
				a[i].s1=1;a[i].s1n=a[i].n1;
				a[i].s2=2;a[i].s2n=a[i].n2;
				a[i].s3=3;a[i].s3n=a[i].n3;
			}
			else if(a[i].n1>=a[i].n3&&a[i].n3>=a[i].n2)
			{
				a[i].s1=1;a[i].s1n=a[i].n1;
				a[i].s2=3;a[i].s2n=a[i].n3;
				a[i].s3=2;a[i].s3n=a[i].n2;
			}
			else if(a[i].n2>=a[i].n1&&a[i].n1>=a[i].n3)
			{
				a[i].s1=2;a[i].s1n=a[i].n2;
				a[i].s2=1;a[i].s2n=a[i].n1;
				a[i].s3=3;a[i].s3n=a[i].n3;
			}
			else if(a[i].n2>=a[i].n3&&a[i].n3>=a[i].n1)
			{
				a[i].s1=2;a[i].s1n=a[i].n2;
				a[i].s2=3;a[i].s2n=a[i].n3;
				a[i].s3=1;a[i].s3n=a[i].n1;
			}
			else if(a[i].n3>=a[i].n1&&a[i].n1>=a[i].n2)
			{
				a[i].s1=3;a[i].s1n=a[i].n3;
				a[i].s2=1;a[i].s2n=a[i].n1;
				a[i].s3=2;a[i].s3n=a[i].n2;
			}
			else if(a[i].n3>=a[i].n2&&a[i].n2>=a[i].n1)
			{
				a[i].s1=3;a[i].s1n=a[i].n3;
				a[i].s2=2;a[i].s2n=a[i].n2;
				a[i].s3=1;a[i].s3n=a[i].n1;
			}
			a[i].c12=a[i].s1n-a[i].s2n;
			a[i].c13=a[i].s1n-a[i].s3n;
			a[i].c23=a[i].s2n-a[i].s3n;
		}
		int res=solve();
		printf("%d\n",res);
	}
	
	return 0;
 } 
