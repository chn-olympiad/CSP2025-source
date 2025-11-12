#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200+5;
int T,n,a[maxn][4];
int f[maxn][maxn][maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int x=1;x<=n;x++){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int k=x-1-i-j;
					if(k<0)break;
//					cout<<i+1<<' '<<j<<' '<<k<<' '<<f[i+1][j][k]<<'\n',
//					cout<<i<<' '<<j+1<<' '<<k<<' '<<f[i][j+1][k]<<'\n',
//					cout<<i<<' '<<j<<' '<<k+1<<' '<<f[i][j][k+1]<<'\n';
					if((i+1)<=n/2)f[i+1][j][k]=max(f[i][j][k]+a[x][1],f[i+1][j][k]);
					if((j+1)<=n/2)f[i][j+1][k]=max(f[i][j][k]+a[x][2],f[i][j+1][k]);
					if((k+1)<=n/2)f[i][j][k+1]=max(f[i][j][k]+a[x][3],f[i][j][k+1]);
					ans=max({ans,f[i+1][j][k],f[i][j+1][k],f[i][j][k+1]});			
				}
			}		
		}
		cout<<ans<<'\n';
		for(int i=0;i<=n;i++){
			a[i][1]=a[i][2]=a[i][3]=0;
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					f[i][j][k]=0;		
		}
		
	}
	return 0;
}
