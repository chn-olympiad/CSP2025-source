#include<bits/stdc++.h>
using namespace std;
int a[100010][10],b[100010],c[100010],d[100010],mx[100010],cnt[10],temp,kkk,k,ans,maxx,tot;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		ans=kkk=temp=k=ans=maxx=tot=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			maxx=mx[i]=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(mx[i]<a[i][j])
					maxx=mx[i];
				else
					maxx=max(maxx,a[i][j]);
				mx[i]=max(mx[i],a[i][j]);
			}
			for(int j=1;j<=3;j++)
			{
				if(mx[i]==a[i][j])
					b[i]=j;
			}
			cnt[b[i]]++;
			c[i]=mx[i]-maxx;
		}
		for(int i=1;i<=3;i++)
		{
			if(kkk<cnt[i])
			{
				kkk=cnt[i];
				k=i;
			}
		}
		if(kkk<=n/2)
		{
			for(int i=1;i<=n;i++)
				ans+=mx[i];
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++)
			{
				if(k==b[i])
				{
					d[++tot]=c[i];
					ans+=mx[i]-c[i];
				}else
					ans+=mx[i]; 
				//cout<<mx[i]<<" "<<c[i]<<endl;
			}
			sort(d+1,d+tot+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=d[i];
			cout<<ans<<endl;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(mx,0,sizeof(mx));
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}

