#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100005][5];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int f[102][102][102];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		n=read();
		int m=n/2;
		for(int i=1;i<=n;i++){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
		}
		f[1][0][0]=a[1][1];
		f[0][1][0]=a[1][2];
		f[0][0][1]=a[1][3];
		for(int i=2;i<=n;i++){
			int jmin=min(i,m);
			for(int j=jmin;j>=0;j--){
				int kmin=min(i-j,m);
				for(int k=kmin;k>=0;k--){
					int lmin=min(i-j-k,m);
					for(int l=lmin;l>=0;l--){
						if(j!=0)f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+a[i][1]);
						if(k!=0)f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i][2]);
						if(l!=0)f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i][3]);
						if(i==n)ans=max(ans,f[j][k][l]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
