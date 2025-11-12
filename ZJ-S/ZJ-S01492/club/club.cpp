#include<bits/stdc++.h>
using namespace std;
int a[100007][3],f[100007],maxn[100007],num[100007],c[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int atp=0;atp<T;atp++)
	{
	    priority_queue<int> q;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		memset(maxn,0,sizeof(maxn));
		memset(num,0,sizeof(num));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int max1,max2;
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
			{
				max2=max(a[i][2],a[i][1]);
				max1=a[i][0];
				f[i]=max1-max2;
				num[i]=1;
				c[1]++;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>a[i][2])
			{
				max2=max(a[i][0],a[i][2]);
				max1=a[i][1];
				f[i]=max1-max2;
				num[i]=2;
				c[2]++;
			}
			else
			{
				max2=max(a[i][0],a[i][1]);
				max1=a[i][2];
				f[i]=max1-max2;
				num[i]=3;
				c[3]++;
			}
			maxn[i]=max1;
		}
		long long ans=0;
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)
		{
			for(int i=1;i<=n;i++) ans+=maxn[i];
			cout<<ans<<endl;
			continue;
		}
		else
		{
			int p,fh;
			if(c[1]>n/2) fh=1,p=c[1];
			else if(c[2]>n/2) fh=2,p=c[2];
			else fh=3,p=c[3];
			for(int i=1;i<=n;i++) ans+=maxn[i];
			p=p-(n/2);
			for(int i=1;i<=n;i++) if(fh==num[i]) q.push(f[i]);
			for(int i=1;i<=n/2;i++) q.pop();
			for(int i=1;i<=p;i++) ans-=q.top(),q.pop();
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
