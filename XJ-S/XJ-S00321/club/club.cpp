#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct QAQ{
	int a[4],maxv;
}a[N];
int T,n,f[2][4][4],maxv;
long long ans;
bool cmp(QAQ x,QAQ y){return x.maxv>y.maxv;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n,ans=0,maxv=n/2;
		for(int i=1;i<=n;i++) cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3],a[i].maxv=max(a[i].a[1],max(a[i].a[2],a[i].a[3]));
		sort(a+1,a+1+n,cmp);
		for(int t=1;t<=n;t++)
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(f[0][j][i]<maxv)
					{
						if(f[1][i][0]<f[0][j][0]+a[t].a[i])
						{
							f[1][i][0]=f[0][j][0]+a[t].a[i];
							for(int k=1;k<=3;k++) f[1][i][k]=f[0][j][k];
							f[1][i][i]++;
						}
					}
					else if(f[1][i][0]<f[0][j][0]) for(int k=0;k<=3;k++) f[1][i][k]=f[0][j][k];
				}
			}
			for(int i=1;i<=3;i++) for(int j=0;j<=3;j++) f[0][i][j]=f[1][i][j],f[1][i][j]=0;
		}
		cout<<max(f[0][1][0],max(f[0][2][0],f[0][3][0]))<<"\n";
		for(int i=1;i<=3;i++) for(int j=0;j<=3;j++) f[0][i][j]=0;
	}
	return 0;
}
