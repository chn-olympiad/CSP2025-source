#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5];
long long ans;
int l[5],ll[100005][5];
int b[100005];
int read()
{
	int tot=0;char c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	while('0'<=c&&c<='9')tot=tot*10+c-'0',c=getchar();
	return tot;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		l[1]=l[2]=l[3]=0;
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				l[1]++;
				ll[l[1]][1]=i;
				ans+=(long long)a[i][1];
			}
			else
			{
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				{
					l[2]++;
					ll[l[2]][2]=i;
					ans+=(long long)a[i][2];
				}
				else
				{
					l[3]++;
					ll[l[3]][3]=i;
					ans+=(long long)a[i][3];
				}
			}
		}
		if(l[1]>n/2)
		{
			int o;
			for(int i=1;i<=l[1];i++)
			{
				o=ll[i][1];
				if(a[o][2]>a[o][3])b[i]=a[o][1]-a[o][2];
				else b[i]=a[o][1]-a[o][3];
			}
			sort(b+1,b+1+l[1]);
			for(int i=1;i<=l[1]-n/2;i++)
			{
				ans-=(long long)b[i];
			}
		}
		if(l[2]>n/2)
		{
			int o;
			for(int i=1;i<=l[2];i++)
			{
				o=ll[i][2];
				if(a[o][1]>a[o][3])b[i]=a[o][2]-a[o][1];
				else b[i]=a[o][2]-a[o][3];
			}
			sort(b+1,b+1+l[2]);
			for(int i=1;i<=l[2]-n/2;i++)
			{
				ans-=(long long)b[i];
			}
		}
		if(l[3]>n/2)
		{
			int o;
			for(int i=1;i<=l[3];i++)
			{
				o=ll[i][3];
				if(a[o][2]>a[o][1])b[i]=a[o][3]-a[o][2];
				else b[i]=a[o][3]-a[o][1];
			}
			sort(b+1,b+1+l[3]);
			for(int i=1;i<=l[3]-n/2;i++)
			{
				ans-=(long long)b[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
