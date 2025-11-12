#include<bits/stdc++.h>
using namespace std;
int n,m,k,kc[10001],kc2[10001],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int q[n+1][n+1],xc[k+1][n+1];
	bool sf[n+1][n+1];
	memset(sf,0,sizeof(sf));
	memset(q,0,sizeof(q));
	memset(xc,0,sizeof(xc));
    
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		q[a][b]=c;
		q[b][a]=c;
		sf[a][b]=1;
		sf[b][a]=1;
		ans+=c;
	}
	for(int i=1;i<=k;i++){
		cin>>kc[i];
		for(int j=1;j<=n;j++){
			cin>>xc[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			for(int h=1;h<=n;h++){
				if(q[i][h]&&q[h][j]&&q[i][j]&&q[i][h]+q[j][h]<q[i][j]){
					if(sf[i][j]) {
					    ans=ans-q[i][j];
					    sf[i][j]=0;
					    sf[j][i]=0;
			    	}
			    	q[i][j]=q[i][h]+q[j][h];
			    	q[j][i]=q[i][j];
				}
				if(q[i][j]==0&&q[i][h]!=0&&q[j][h]!=0){
					q[i][j]=q[i][h]+q[j][h];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int flag=0;
			if(j==i) continue;
			for(int h=1;h<=k;h++){
				if(xc[h][i]&&xc[h][j]&&q[i][j]&&xc[h][i]+xc[h][j]+kc[h]<q[i][j]){
					if(flag!=0){
						kc2[flag]--;
						if(kc2[flag]==0) ans-=kc[flag];
					}
					if(sf[i][j]) ans=ans-q[i][j];
					if(kc2[h]==0) ans+=kc[h];
					ans+=xc[i][k]+xc[j][k];
					q[i][j]=xc[h][i]+xc[h][j];
					q[j][i]=q[i][j];
					sf[i][j]=1;
					sf[j][i]=1;
					kc2[h]++;
					flag=h;
				}
				if(q[i][j]==0&&q[i][h]!=0&&q[j][h]!=0){
					q[i][j]=q[i][h]+q[j][h];
					if(kc2[h]==0) ans+=kc[h];
					kc2[h]++;}
			}
		}
}
	cout<<ans;
	return 0;
}


