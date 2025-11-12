#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a[5];
	int f,m,m1;
}e[100005];
int cmp(node x,node y)
{
	if(x.f==y.f)
		return x.m>y.m;
	return x.f<y.f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			e[i].a[1]=a,e[i].a[2]=b,e[i].a[3]=c;
			int f,m=0;
			for(int j=1;j<=3;j++)
				if(e[i].a[j]>m)
				{
					m=e[i].a[j];
					f=j;
				}
			e[i].m=m,e[i].f=f;
			e[i].m1=a+b+c-m-min(min(a,b),c);
		}
		sort(e+1,e+1+n,cmp);
		int num=0;
		for(int i=1;i<=n/2;i++)
			if(e[i].f==e[n-i+1].f)
				num=num+e[i].m+e[n-i+1].m1;
			else
				num=num+e[i].m+e[n-i+1].m;
		printf("%d\n",num);
	}
	return 0;
}
