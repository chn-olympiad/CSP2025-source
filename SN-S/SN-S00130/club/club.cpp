#include <bits/stdc++.h>
using namespace std;
int a[100010][4];
int b[100010],c[100010],d[100010];
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{	
		int q=0,w=0,e=0,ans=0,rt=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			b[i]=30000;
			c[i]=30000;
			d[i]=30000;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=max(a[i][2],a[i][3]))
			{
				ans+=a[i][1];
				q++;
				b[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			if(a[i][2]>max(a[i][1],a[i][3])||a[i][2]==a[i][3])
			{
				ans+=a[i][2];
				w++;
				c[i]=a[i][2]-max(a[i][1],a[i][3]);
			}
			if(a[i][3]>max(a[i][2],a[i][1]))
			{
				ans+=a[i][3];
				e++;
				d[i]=a[i][3]-max(a[i][2],a[i][1]);
			}
		}
		n=n/2;
		if(q>n)
		{
			rt=q-n;
			sort(b+1,b+2*n+1);
			for(int i=1;i<=rt;i++)
			{
				ans-=b[i];
			}
		}
		if(w>n)
		{
			rt=w-n;
			sort(c+1,c+2*n+1);
			for(int i=1;i<=rt;i++)
			{
				ans-=c[i];
			}
		}
		if(e>n)
		{
			rt=e-n;
			sort(d+1,d+2*n+1);
			for(int i=1;i<=rt;i++)
			{
				ans-=d[i];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
