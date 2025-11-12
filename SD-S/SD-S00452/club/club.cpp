#include<bits/stdc++.h>
#define int long long
#define bug cout<<"songge888"<<'\n';
using namespace std; 
int t;
int n;
int a[100010],b[100010],c[100010];
int f[111][111][111];
struct lyl{
	int x,y;
}e[100010];
bool operator <(lyl a,lyl b){
	return a.x>b.x;
}
int ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int fl=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i]){
				fl=1;
			}
		}
		if(n<=222){
			for(int i=0;i<=n/2+1;i++){
				for(int j=0;j<=n/2+1;j++){
					for(int k=0;k<=n/2+1;k++){
						f[i][j][k]=0;
					}
				} 
			}
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i+j+k>n){
							continue;
						}
						int now=i+j+k;
						if(i-1>=0){
	//						cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[now]);
						}
						if(j-1>=0){
	//						cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
							f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+b[now]);
						}
						if(k-1>=0){
	//						cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
							f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+c[now]);	
						}
						
	//					cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
						ans=max(ans,f[i][j][k]);
					}
				}
			}
		}
		else if(!fl){
			sort(a+1,a+1+n,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			} 
		}
		else{
			for(int i=1;i<=n;i++){
				e[i]={a[i],b[i]};
			} 
			sort(e+1,e+1+n);
			for(int i=1;i<=n/2;i++){
				ans+=e[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=e[i].y;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
// ?²»Ð´ÁË
 
