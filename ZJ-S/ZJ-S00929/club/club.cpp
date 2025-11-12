#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100010],b[100010],c[100010],maxn,f[110][110][110];
long long suma,sumb,sumc,tota[100010],totb[100010],totc[100010],sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		suma=sumb=sumc=sum=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(a[i],max(b[i],c[i]));
			sum+=maxn;
			if(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]){
				continue;
			}
			else
			{
				if(maxn==a[i])
				{
					suma++;
					tota[suma]=a[i]-max(b[i],c[i]);
				}
				if(maxn==b[i])
				{
					sumb++;
					totb[sumb]=b[i]-max(a[i],c[i]);
				}
				if(maxn==c[i])
				{
					sumc++;
					totc[sumc]=c[i]-max(b[i],a[i]);
				}
			}
		}
		if(suma>n/2)
		{
			sort(tota+1,tota+suma+1);
			for(int i=1;i<=suma-n/2;i++)
			{
				sum-=tota[i];
			}
			cout<<sum<<endl;
		}
		else if(sumb>n/2)
		{
			sort(totb+1,totb+sumb+1);
			for(int i=1;i<=sumb-n/2;i++)
			{
				sum-=totb[i];
			}
			cout<<sum<<endl;
		}
		else if(sumc>n/2)
		{
			sort(totc+1,totc+sumc+1);
			for(int i=1;i<=sumc-n/2;i++)
			{
				sum-=totc[i];
			}
			cout<<sum<<endl;
		}
		else
		{
			cout<<sum<<endl;
		}
	}
	return 0;
}
