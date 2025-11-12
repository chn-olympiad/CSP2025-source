#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(b);i>=(a);i--)
using namespace std;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2-±³°üÈÝÁ¿n; f[na][nb][nc] f[i][j][k]=f[i-1][j][k]+a[i][1];f[0][0][0]=0;
rep(i,1,n) rep(j,1,3) if(j==1) f[na+1][nb][nc] = f[na][nb][nc],f[][0][0]+a[i]
10 9 8 
4 0 0
int vis[N];			2
int dfs(na,nb,nc,now){
	if(now==0) return 0;
	rep(i,1,n){
		if(vis[i]==1) continue;
		int ans1;
		vis[i]=1;
		rep(j,1,3){
			if(j==1&&na<=n/2){
				ans1=dfs(na-1,nb,nc,now-1)+a[i][j];
			}
			if(j==2&&nb<=n/2){ 
				ans1=max(ans1,dfs(na,nb-1,nc,now-1)+a[i][j]);
			}
			if(j==3&&nc<=n/2){ 
				ans1=max(ans1,dfs(na,nb,nc-1,now-1)+a[i][j]);
			}
		}
		vis[i]=0;
		return ans1;
	}

}
 
*/
const int N=300;
int t,n;
int a[N][10];
int vis[N];int f[N][N][N];
int dfs(int na,int nb,int nc,int now){
	if(now==0) return 0;
	if(f[na][nb][nc]>0) return f[na][nb][nc];
	rep(i,1,n){
		if(vis[i]==1) continue;
		int ans1=0;
		vis[i]=1;
		rep(j,1,3){
			if(j==1&&na<n/2){
				ans1=dfs(na+1,nb,nc,now-1)+a[i][j];
			}
			if(j==2&&nb<n/2){ 
				ans1=max(ans1,dfs(na,nb+1,nc,now-1)+a[i][j]);
			}
			if(j==3&&nc<n/2){ 
				ans1=max(ans1,dfs(na,nb,nc+1,now-1)+a[i][j]);
			}
		}
		vis[i]=0;
		f[na][nb][nc] = ans1;
		return ans1;
	}

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>1000){
			memset(vis,0,sizeof vis);
			rep(i,1,n){
				cin>>vis[i]>>a[i][2]>>a[i][3];
			}
			sort(vis+1,vis+1+n);
			int ans=0;
			pre(i,n/2+1,n){
				ans+=vis[i];
			}
			cout<<ans<<endl;
			continue;
		}
		memset(vis,0,sizeof vis);
		memset(f,0,sizeof f);
		memset(a,0,sizeof a);
//		rep(i,1,N) rep(j,1,N) rep(k,1,N) if(0) cout<<"nononono";
		rep(i,1,n){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<dfs(0,0,0,n)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
