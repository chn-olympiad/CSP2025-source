#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],n;
void tp23()
{
	long long s=0;
	sort(a+1,a+1+n);
	for(int i=n;i>n/2;i--)
	{
		s+=a[i];
	}
	cout<<s<<'\n';
	return;
}
void tpn2()
{
	int t[10];//shi
	t[1]=a[1]+b[2];
	t[2]=a[1]+c[2];
	t[3]=b[1]+a[2];
	t[4]=b[1]+c[2];
	t[5]=c[1]+a[2];
	t[6]=c[1]+b[2];
	int ans=0;
	for(int i=1;i<=6;i++)
	{
		ans=max(ans,t[i]);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)//n==30
	{
		long long f[50][50][50],md;//num 1 2
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		long long tp2=-1,tp3=-1;
		memset(f,0,sizeof(0));
		cin>>n;
		md=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			tp2=max(tp2,b[i]);
			tp3=max(tp3,c[i]);
		}
		if(n==2)
		{
			tpn2();
			continue;
		}
		f[0][0][0]=0;
		long long ans=0;
		if(tp2==0 && tp3==0)//
		{
			tp23();
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=md;j>=0;j--)
			{
				for(int k=md;k>=0;k--)
				{
					for(int r=md;r>=0;r--)
					{
						if(j+k+r>i)continue;
						if(j!=0 && k!=0)
							f[j][k][r]=max(f[j-1][k][r]+a[i],f[j][k-1][r]+b[i]);
						else if(j!=0 && r!=0)
							f[j][k][r]=max(f[j-1][k][r]+a[i],f[j][k][r-1]+c[i]);
						else if(k!=0 && r!=0)
							f[j][k][r]=max(f[j][k-1][r]+b[i],f[j][k][r-1]+c[i]);
						else if(j==0 && k==0 && r==0) f[j][k][r]=0;
						else if(k==0 && r==0) f[j][k][r]=f[j-1][k][r]+a[i];
						else if(j==0 && r==0) f[j][k][r]=f[j][k-1][r]+b[i];
						else if(j==0 && k==0) f[j][k][r]=f[j][k][r-1]+c[i];
						if(i==n && j+k+r==n) ans=max(ans,f[j][k][r]);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
