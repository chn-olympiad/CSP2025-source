#include<iostream>
using namespace std;
int t,n;
bool A;
long long ans;
int v[100005][3];
long long f[205][5][105][105];
bool check(int a,int b)
{
	if(a>(n>>1)||b>(n>>1)||a+b<(n>>1)) return 0;
	return 1; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		A=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) scanf("%d",&v[i][j]);
			if(v[i][3]!=0||v[i][2]!=0) A=1;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) for(int a=0;a<=(n>>1);a++) for(int b=0;b<=(n>>1);b++) f[i][j][a][b]=0;
		if(!A)
		{
			for(int i=1;i<=(n>>1);i++) ans+=v[i][1];
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int a=0;a<=(n>>1);a++)
			{
				for(int b=0;b<=(n>>1);b++)
				{
					if(a) for(int j=1;j<=3;j++) f[i][1][a][b]=max(f[i][1][a][b],f[i-1][j][a-1][b]+v[i][1]);
					if(b) for(int j=1;j<=3;j++) f[i][2][a][b]=max(f[i][2][a][b],f[i-1][j][a][b-1]+v[i][2]);
					if(a+b!=i) for(int j=1;j<=3;j++) f[i][3][a][b]=max(f[i][3][a][b],f[i-1][j][a][b]+v[i][3]);
					if(i==n&&check(a,b)) for(int j=1;j<=3;j++) ans=max(ans,f[i][j][a][b]);
//					for(int j=1;j<=3;j++) cout<<i<<' '<<j<<' '<<a<<' '<<b<<' '<<f[i][j][a][b]<<endl;
				}
			}
		}
		printf("%lld\n",ans);
		ans=0;
	}
}
