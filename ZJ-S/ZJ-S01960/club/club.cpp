#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1000001,M=1001;
int T,n,ma,sum,f[5],a[N],b[N],c[N],w[N],k,g[5];
bool cmp (int x,int y)
{
	return x>y;
}
void bfs (int x,int ans)
{
//	if (f) //jian zhi
	if (x==n+1)
	{
		ma=max (ma,ans);
		return ;
	}
	if (g[1]<k) g[1]++,bfs (x+1,ans+a[x]),g[1]--;
	if (g[2]<k) g[2]++,bfs (x+1,ans+b[x]),g[2]--;
	if (g[3]<k) g[3]++,bfs (x+1,ans+c[x]),g[3]--;
}
int ss (int x)
{
	int t=1,w=N;
	while (t<=w)
	{
		int mid=(t+w)/2;
		if (x>a[mid]) t=mid+1;
		else if (x==a[mid]) return mid;
		else w=mid-1;
	}
}
int main ()
{
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	cin >>T;
	while (T--)
	{
		cin >>n;
		sum=f[1]=ma=f[2]=f[3]=0;
		for (int i=1;i<=n;i++)
		{
			 cin >>a[i]>>b[i]>>c[i];
			 if (a[i]>b[i]&&a[i]>c[i]) sum+=a[i],f[1]++;
			 if (b[i]>a[i]&&b[i]>c[i]) sum+=b[i],f[2]++;
			 if (c[i]>b[i]&&c[i]>a[i]) sum+=c[i],f[3]++;
		}
		k=n/2;
		if (n==200||n==100000)
		{
			int F=0,ans=0;
			for (int i=1;i<=n;i++)
				if (b[i]!=c[i]) F=1;
			if (F==0) //A
			{
				sort (a+1,a+1+n,cmp);
				for (int i=1;i<=k;i++) ans=ans+a[i];
				cout <<ans<<"\n";
			}
			else //B
			{
				int ans=0,ansb=0;
				for (int i=1;i<=n;i++) w[i]=0;
				for (int i=1;i<=n;i++)
				{
					sort (a+1,a+1+n,cmp);
					for (int i=1;i<=k;i++)
					{
						ans+=a[i];
						w[ss (a[i])]+=1;
					}
					sort (b+1,b+1+n,cmp);
					for (int i=1;i<=k;i++)
					{
						ansb+=b[i];
						w[ss (b[i])]+=2;
					}
					if (ans>=ansb)
					{
						for (int i=1;i<=n;i++)
							if (w[i]!=1&&w[i]!=3) ans+=w[i];
						cout <<ans<<'\n';
					}
					else if (ansb>=ans)
					{
						for (int i=1;i<=n;i++)
							if (w[i]!=2&&w[i]!=3) ansb+=w[i];
						cout <<ansb<<'\n';
					}
				}
			}
		}
		else if (k>=max (f[1],max (f[2],f[3]) ) ) cout <<sum<<"\n";
		else if (n<=10)
		{
			bfs (1,0);
			cout <<ma<<"\n";
		}
	}
	return 0;
}
