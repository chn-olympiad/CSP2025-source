#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010,MOD=998244353;
int n,a[N],p=1;
struct N{
	int x,y,z;
}f[N][N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	sort(a,a+n);
	f[3][3].x=a[3]+a[2]+a[1];
	f[3][3].y=max(a[1],max(a[2],a[3])); 
	f[3][3].z=1;
	if(n<=300){
		int z=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++){
					int xx=a[i]+a[j]+a[k],yy=max(a[i],max(a[j],a[k]));
					if(xx>yy*2){
						z++;
						z=z%MOD;
					}
				}
		}
		p=z;
	}
	for(int i=3;i<=n;i++)
		for(int j=3;j<=n;j++){
			if(f[i-1][j-1].x+a[i]>2*max(f[i-1][j-1].y,a[i])){
				f[i][j].z+=f[i-1][j-1].z*2;
				f[i][j].x=f[i-1][j-1].x+a[i];
				f[i][j].y=max(f[i-1][j-1].y,a[i]);
			}else{
				f[i][j].x=f[i-1][j-1].x;
				f[i][j].y=f[i-1][j-1].y;
				for(int k=0;k<=j/2;k++)
					f[i][j].z+=f[i-1][j-k].z+f[i-1][k].z;
			}
			f[i][j].z%=MOD; 
		}
	cout<<f[n][n].z*p%MOD;
	return 0;
}
