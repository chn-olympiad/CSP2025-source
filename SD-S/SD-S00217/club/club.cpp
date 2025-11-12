#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const int M=111;
typedef long long ll;
int T,n;
int a[N][4],f[M][M];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=2;j++) cin>>a[i][j];
		for(int k=1;k<=n;k++){
			for(int i=0;i<=min(k,n>>1);i++){
				for(int j=0;j<=min(k,n>>1);j++){
					if(i+j<=k-n<<1||i+j>k) continue;
					if(i>0&&i+j<=k) f[i][j]=max(f[i][j],f[i-1][j]+a[k][0]);
					if(j>0&&i+j<=k) f[i][j]=max(f[i][j],f[i][j-1]+a[k][1]);
					if(i+j+1==k) f[i][j]=max(f[i][j],f[i][j]+a[k][2]);
				}
			}
		}
//		cout<<f[n][n]<<"\n";
		for(int i=1;i<=n>>1;i++){
			for(int j=1;j<=n>>1;j++) ans=max(ans,f[i][j]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
