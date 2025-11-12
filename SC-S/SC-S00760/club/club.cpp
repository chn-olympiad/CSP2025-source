#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int hsh[N][5][5],dp[N][5],n,ans;
struct peo{
	int a[5];
}p[N];
int hsh2[N],jg[N];
void dfs(int k){
	for(int i=1; i<=3; i++){
		if(hsh2[i]<n/2){
			hsh2[i]++;
			jg[k]=i;
			if(k==n){
				int sum=0;
				for(int j=1; j<=n; j++){
					sum+=p[j].a[jg[j]];
				}
				if(sum>ans){
					ans=sum;
				}
			}else dfs(k+1);
			hsh2[i]--;
		}
	}
}
int f[205][205][205];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	for(; t; t--){
		memset(dp,0,sizeof dp);
		memset(hsh,0,sizeof hsh);
		cin>>n;
		bool fl1=1,fl2=1;
		for(int i=1; i<=n; i++){
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			fl1=min(fl1,(p[i].a[2]==0)),fl2=min(fl2,(p[i].a[3]==0));
		}
		if(n<=10){
			ans=0;
			dfs(1);cout<<ans<<'\n';
		}else if(n<=200){
			ans=0;
			for(int i=0; i<=n; i++){
				for(int j=0; j<=n; j++){
					for(int k=0; k<=n-i-j; k++){
						if(i>n/2 || j>n/2 || k>n/2 || i+j+k>n) continue;
						int &v=f[i][j][k];
						if(i>0) v=max(f[i-1][j][k]+p[i+j+k].a[1],v);
						if(j>0) v=max(f[i][j-1][k]+p[i+j+k].a[2],v);
						if(k>0) v=max(f[i][j][k-1]+p[i+j+k].a[3],v);
						if(i+j+k==n) ans=max(f[i][j][k],ans);
					}
				}
			}
			for(int i=0; i<=n/2; i++){
				for(int j=0; j<=n/2; j++){
					for(int k=0; k<=n/2; k++){
						f[i][j][k]=0; 
//						if(i+j+k<=n) printf("f[%d][%d][%d]:%d\n",i,j,k,f[i][j][k]);
					}
				}
			}
//			cout<<'\n';
			cout<<ans<<'\n';
		}else if(fl1||fl2){
			sort(p+1,p+n+1,[](peo a,peo b){
				peo c=a,d=b;
				sort(c.a+1,c.a+4,less<int>());
				sort(d.a+1,d.a+4,less<int>());
				return c.a[1]<d.a[1]||(c.a[2]<d.a[2]&&c.a[1]==d.a[2])||(c.a[2]==d.a[2]&&c.a[1]==d.a[2]&&c.a[3]<d.a[3]);});
//			cout<<'\n';	
//			for(int i=1; i<=n; i++){
//				cout<<p[i].a[1]<<' '<<p[i].a[2]<<' '<<p[i].a[3]<<'\n';
//			}	
			int ans=0;
			for(int i=1; i<=n; i++){
				for(int j=1; j<=3; j++){
					for(int k=1; k<=3; k++){
						if(hsh[i-1][k][j]<n/2){
							if(dp[i][j]<dp[i-1][k]+p[i].a[j]){
								dp[i][j]=dp[i-1][k]+p[i].a[j];
								for(int m=1; m<=3; m++){
									hsh[i][j][m]=hsh[i-1][k][m];
								}
								hsh[i][j][j]++;
							}
						}
					}
					if(dp[i][j]==0){
						for(int m=1; m<=3; m++){
							hsh[i][j][m]=n;
						}
					}
				}
			}
	//		cout<<'\n'; 
	//		for(int i=1; i<=n; i++){
	//			for(int j=1; j<=3; j++){
	//				cout<<dp[i][j]<<' ';
	//			}
	//			cout<<'\n';
	//		}
	//		for(int i=1; i<=n; i++){
	//			for(int j=1; j<=3; j++){
	//				printf("hsh[%d][%d]:%d %d %d\n",i,j,hsh[i][j][1],hsh[i][j][2],hsh[i][j][3]);
	//			}
	//		}
	//		cout<<'\n'; 
			cout<<max(max(dp[n][1],dp[n][2]),dp[n][3])<<'\n';  
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}