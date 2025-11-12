#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],b[100005],x[100005];
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
	{
    	scanf("%d",&n);
    	int m=0;
    	int t[3]={0,0,0};
    	memset(x,0,sizeof 0);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    		int k=max(a[i][0],(max(a[i][1],a[i][2])));
    		m+=k;
    		if(k==a[i][0])t[0]++,x[i]=0;
    		else if(k==a[i][1])t[1]++,x[i]=1;
    		     else t[2]++,x[i]=2;
		}
		int k;
		if(t[1]>n/2)k=1;
		else if(t[2]>n/2)k=2;
		else if(t[0]>n/2)k=0;
		else
		{
			printf("%d\n",m);
			continue;
		}
		memset(b,127,sizeof b);
		int u=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]==k)
			  b[++u]=min(a[i][k]-a[i][(k+1)%3],a[i][k]-a[i][(k+2)%3]);
		}
		sort(b+1,b+u+1);
		for(int i=1;i<=t[k]-n/2;i++)m-=b[i];
		printf("%d\n",m);
	}
	return 0;
}
