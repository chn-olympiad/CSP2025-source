#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int N=200005;

int t,n,a[N][5],c[N],mx[N];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		int tmp[5],t;
		ll res=0;
		tmp[1]=0,tmp[2]=0,tmp[3]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) c[i]=1,mx[i]=max(a[i][2],a[i][3]);
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) c[i]=2,mx[i]=max(a[i][1],a[i][3]);
			else c[i]=3,mx[i]=max(a[i][1],a[i][2]);
			tmp[c[i]]++;
			res+=a[i][c[i]];
		}
		if(tmp[1]<=n/2&&tmp[2]<=n/2&&tmp[3]<=n/2)
		{
			printf("%lld\n",res);
			continue;
		}
		if(tmp[1]>tmp[2]&&tmp[1]>tmp[3]) t=1;
		else if(tmp[2]>tmp[1]&&tmp[2]>tmp[3]) t=2;
		else t=3;
		priority_queue<int> q;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==t)
			{
				ll cnt=a[i][c[i]]-mx[i];
				q.push(-cnt);
			}
		}
		for(int i=tmp[t];i>(n/2);i--)
		{
			ll tp=q.top();
			res+=tp;
			q.pop();
		}
		printf("%lld\n",res);
	}
	return 0;
}
