#include<bits/stdc++.h> 
using namespace std;
long long a[100005];
long long b[100005];
long long c[100005],e[100005];
int suma=0,sumb=0,sumc=0;
struct node
{
	int num,d,x;
};
struct node f[1000005];
long long ans;
bool cmp(struct node a,struct node b)
{
	if(a.d>b.d) return 0;
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,k;
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			f[i].x=i;
			e[1]=a[i];e[2]=b[i];e[3]=c[i];
			sort(e+1,e+4);
			f[i].num=e[3];
			f[i].d=e[3]-e[2];
			if(a[i]==f[i].num) suma++;
			if(b[i]==f[i].num) sumb++;
			if(c[i]==f[i].num) sumc++;
		}
		k=n/2;
		for(i=1;i<=n;i++)
		{
			ans+=f[i].num;
		}
		int jian;
		if(suma>k)
		{
			int g=suma-k;
			sort(f+1,f+n+1,cmp);
			for(i=1;i<=g;i++)
			{
				jian+=f[i].d;
			}
		}
		if(sumb>k)
		{
			int g=sumb-k;
			sort(f+1,f+n+1,cmp);
			for(i=1;i<=g;i++)
			{
				jian+=f[i].d;
			}
		}
		if(sumc>k)
		{
			int g=sumc-k;
			sort(f+1,f+n+1,cmp);
			for(i=1;i<=g;i++)
			{
				jian+=f[i].d;
			}
		}
		cout << ans-jian << endl;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		suma=0;sumb=0;sumc=0;ans=0;jian=0;
	}
	return 0;
}
