#include <bits/stdc++.h>
using namespace std;

int t;

struct node 
{
	int a,b,c;
};

bool cmp1(node x,node y)
{
	return x.a > y.a;
}

bool cmp2(node x,node y)
{
	return x.b > y.b;
}

bool cmp3(node x,node y)
{
	return x.c > y.c;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--)
	{
		int n;
		long long cnta,cntb,cntc,ans;
		node a[100005];
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			cnta += a[i].a;
			cntb += a[i].b;
			cntc += a[i].c; 
		}
		if(cnta > cntb && cnta > cntc)
		{
			sort(a+1,a+n+1,cmp1);
			for(int i = 1;i <= n/2;i++)
			{
			 	 ans += a[i].a;
			 	 cntb -= a[i].b;
			 	 cntc -= a[i].c;
			}
			if(cntb > cntc)
			{
				sort(a+(n/2)+1,a+n+1,cmp2);
				for(int i = n/2+1;i <= n;i++) ans += a[i].b;
			}
			else
			{
				sort(a+(n/2)+1,a+n+1,cmp3);
				for(int i = n/2+1;i <= n;i++) ans += a[i].c;
			}
		}
		else if(cntb > cnta && cntb > cnta)
		{
			sort(a+1,a+n+1,cmp2);
			for(int i = 1;i <= n/2;i++)
			{
			 	 ans += a[i].b;
			 	 cntb -= a[i].a;
			 	 cntc -= a[i].c;
			}
			if(cnta > cntc)
			{
				sort(a+(n/2)+1,a+n+1,cmp1);
				for(int i = n/2+1;i <= n;i++) ans += a[i].a;
			}
			else
			{
				sort(a+(n/2)+1,a+n+1,cmp3);
				for(int i = n/2+1;i <= n;i++) ans += a[i].c;
			}
		}
		else if(cntc > cnta && cntc > cntb)
		{
			sort(a+1,a+n+1,cmp3);
			for(int i = 1;i <= n/2;i++)
			{
			 	 ans += a[i].c;
			 	 cntb -= a[i].b;
			 	 cntc -= a[i].a;
			}
			if(cntb > cnta)
			{
				sort(a+(n/2)+1,a+n+1,cmp2);
				for(int i = n/2+1;i <= n;i++) ans += a[i].b;
			}
			else
			{
				sort(a+(n/2)+1,a+n+1,cmp1);
				for(int i = n/2+1;i <= n;i++) ans += a[i].a;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}