#include<bits/stdc++.h>
#define ll long long
#define V vector
#define pi pair <int,int>
#define fi first
#define se second
using namespace std;

const int N = 210;

int f[N][N/2][N/2],w[N][4];
int n,t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false),cin.tie(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++) scanf("%d",&w[i][j]);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++) cout << w[i][j] << " ";
//			cout << '\n';
//		}
		int ans=0;
		f[1][1][0]=w[1][1],f[1][0][1]=w[1][2],f[1][0][0]=w[1][3];
		ans=max(w[1][1],max(w[1][2],w[1][3]));
//		cout << ans << '\n';
		for(int i=1;i<=n;i++){
			for(int k1=0;k1<=min(i-1,n/2);k1++){
				for(int k2=0;k2<=min(i-1,n/2);k2++){
					if(k1+k2>i-1) continue; 
					if(k1<n/2)
					f[i][k1+1][k2]=max(f[i][k1+1][k2],f[i-1][k1][k2]+w[i][1]),ans=max(ans,f[i][k1+1][k2]);
					if(k2<n/2)
					f[i][k1][k2+1]=max(f[i][k1][k2+1],f[i-1][k1][k2]+w[i][2]),ans=max(ans,f[i][k1][k2+1]);
					if(i-1-k2-k1<n/2)
					f[i][k1][k2]=max(f[i][k1][k2],f[i-1][k1][k2]+w[i][3]),ans=max(ans,f[i][k1][k2]);
//					cout << k1 << " " << k2 << " " << k3 << " " << f[i-1][k1][k2][k3] << '\n';
				}
			}
		}
		cout << ans << '\n';
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

