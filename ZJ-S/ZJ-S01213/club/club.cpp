#include<bits/stdc++.h>
using namespace std;
int t,n,zd,f,g,a[100005][5],b[5],c[100005],d[100005];
long long s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		b[1]=b[2]=b[3]=0;
		s=0;
		f=0;
		g=0;
		for(int i=1;i<=n;i++)
		{
			c[i]=0;
			d[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			zd=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				zd=max(zd,a[i][j]);
			}
			for(int j=1;j<=3;j++)
			{
				if(zd==a[i][j])
				{
					c[i]=j;
					b[j]++;
					s=s+a[i][j];
					break;
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			if(b[i]>n/2)
			{
				f=i;
			}
		}
		if(f>0)
		{
			for(int i=1;i<=n;i++)
			{
				if(c[i]==f)
				{
					d[++g]=min(a[i][f]-a[i][f%3+1],a[i][f]-a[i][(f+1)%3+1]);
				}
			}
			sort(d+1,d+g+1);
			for(int i=1;i<=b[f]-n/2;i++)
			{
				s=s-d[i];
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
