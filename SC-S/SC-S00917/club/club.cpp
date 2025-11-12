#include <bits/stdc++.h> 
using namespace std;
const int MAXN=1e5+10;
int T,n,a[MAXN][3],m;
int c[3],b[MAXN],ans;
int read()
{
	int x=0;char ch=getchar() ;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();ans=m=0;
		for(int i=1;i<=n;i++)
		{
			int id=0;
			for(int j=0;j<3;j++)
			{
				a[i][j]=read();
				if(a[i][id]<=a[i][j]) id=j;
			}
			++c[id],ans+=a[i][id];
		}
		if(max({c[0],c[1],c[2]})>n/2)
		{
			for(int j=0;j<3;j++)
			{
				if(c[j]>n/2)
				{
					for(int i=1;i<=n;i++)
					{
						int id=0;
						for(int j=0;j<3;j++) if(a[i][id]<=a[i][j]) id=j;
						if(id==j)
						{
							sort(a[i],a[i]+3);
							b[++m]=a[i][2]-a[i][1];
						}
					}
					sort(b+1,b+m+1);
					for(int i=1;i<=c[j]-n/2;i++) ans-=b[i];
					break;
				}
			}
		}
		for(int i=0;i<3;i++) c[i]=0;
		printf("%d\n",ans);
	}
}