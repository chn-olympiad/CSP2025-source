#include<bits/stdc++.h>
using namespace std;
const int N=2e5; 
long long t,a[N],b[N],c[N],d[N],e[N],f[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long n,cntd=0,cnte=0,cntf=0,maxx,minn=20010,minxb,ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(long long i=1;i<=n;i++)
		{
			maxx=max(max(b[i],c[i]),a[i]);
			if(maxx==a[i])
			{
				cntd++;
				d[cntd]=i;
			}
			else if(maxx==b[i])
			{
				cnte++;
				e[cnte]=i;
			}
			else if(maxx==c[i])
			{
				cntf++;
				f[cntf]=i;
			}
		}
		while(cntd>n/2 || cnte>n/2 || cntf>n/2)
		{
			while(cntd>n/2)
			{
				for(long long i=1;i<=cntd;i++)
				{
					if(a[d[i]]-max(b[d[i]],c[d[i]])<minn)
					{
						minxb=i;
						minn=a[d[i]]-max(b[d[i]],c[d[i]]);
					}
				}
				maxx=max(b[d[cntd]],c[d[cntd]]);
				if(maxx==b[d[cntd]])
				{
					cnte++;
					e[cnte]=b[d[cntd]];
				}
				else
				{
					cntf++;
					f[cntf]=c[d[cntd]];
				}
				cntd--;
			}
			minn=20010;
			while(cnte>n/2)
			{
				for(long long i=1;i<=cnte;i++)
				{
					if(b[e[i]]-max(a[e[i]],c[e[i]])<minn)
					{
						minxb=i;
						minn=b[e[i]]-max(a[e[i]],c[e[i]]);
					}
				}
				swap(e[minxb],e[cnte]);
				maxx=max(a[e[cnte]],c[e[cnte]]);
				if(maxx==a[e[cnte]])
				{
					cntd++;
					d[cntd]=a[cnte];
				}
				else
				{
					cntf++;
					f[cntf]=c[cnte];
				}
				cnte--;
			}
			minn=20010;
			while(cntf>n/2)
			{
				for(long long i=1;i<=cntf;i++)
				{
					if(c[f[i]]-max(b[f[i]],a[f[i]])<minn)
					{
						minxb=i;
						minn=c[f[i]]-max(b[f[i]],a[f[i]]);
					}
				}
				swap(f[minxb],f[cntf]);
				maxx=max(a[f[cntf]],b[f[cntf]]);
				if(maxx==a[d[cntf]])
				{
					cntd++;
					d[cntd]=a[cntf];
				}
				else
				{
					cnte++;
					e[cnte]=b[cntf];
				}
				cntf--;
			}
			minn=20010;
		}
		for(long long i=1;i<=cntd;i++)
		{
			ans+=a[d[i]];
		}
		for(long long i=1;i<=cnte;i++)
		{
			ans+=b[e[i]];
		}
		for(long long i=1;i<=cntf;i++)
		{
			ans+=c[f[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
