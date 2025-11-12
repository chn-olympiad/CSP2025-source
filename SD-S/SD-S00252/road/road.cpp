#include <bits/stdc++.h>
using namespace std ;
int n,m,k ;
const long long MAX=0x3f3f3f3f ;
long long rd[10005][10005] ;
bool mapp[100005]={0} ;
int minn=MAX ;
void dfs(int pos,int dls){
	bool flag=0 ;
	for(int i=1 ;i<=n ;i++){
		if(mapp[i]==0){
			flag=1 ;
		}
	}
	if(flag==0){
		minn=min(minn,dls) ;
		return ;
	}
	for(int i=1 ;i<=n ;i++){
		if(rd[pos][i]!=MAX&&mapp[i]==0){
			mapp[i]=1 ;
			dfs(i,dls+rd[pos][i]) ;
			mapp[i]=0 ;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false) ;
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	cin>>n>>m>>k ;
	for(int i=0 ;i<=10001 ;i++){
		for(int j=0 ;j<=10001 ;j++){
			rd[i][j]=MAX ;
		}
	}
	for(int i=1 ;i<=m ;i++){
		long long t1,t2,t3 ;
		cin>>t1>>t2>>t3 ;
		rd[t1][t2]=min(rd[t1][t2],t3) ;
		rd[t2][t1]=min(rd[t2][t1],t3) ;
	}
	for(int i=1 ;i<=k ;i++){
		int ck ;
		cin>>ck ;
		int tmp1[10005] ;
		for(int j=1 ;j<=n ;j++){
			cin>>tmp1[j] ;
		}
		for(int ii=1 ;ii<=n ;ii++){
			for(int jj=1 ;jj<=n ;jj++){
				if(ii==jj){
					continue ;
				}else{
					long long cst=ck+tmp1[ii]+tmp1[jj] ;
					rd[ii][jj]=min(rd[ii][jj],cst) ;
				}
			}
		}
	}
	mapp[1]=1 ;
	dfs(1,0) ;
	cout<<minn ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
