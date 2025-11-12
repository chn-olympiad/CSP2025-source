#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[105];
int tong[105];
int k;
int nn,mm;
int flag=1;
signed main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	nn=1;
	mm=1;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
		tong[a[i]]++;
	}
	for(int i=100;i>=a[1];i--)
		k+=tong[i];
	//cout<<k<<endl;
	while(--k)
	{	
//		cout<<k<<endl;
//		cout<<nn<<' '<<mm<<endl;
		if(flag==1)
		{
			nn++;
			if(nn>n)
			{
				mm++;
				flag=2;
				nn--;
			}
		}
		else if(flag==2)
		{
			nn--;
			if(nn<1)
			{
				mm++;
				nn++;
				flag=1;
			}
		}
	}
	printf("%lld %lld",mm,nn);
	return 0;//完结撒花
}