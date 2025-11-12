#include<bits/stdc++.h>
using namespace std; 
long long int n,m,k,ans[50000005],r[10005][10005],u,v,w,c,w2[10004],ma=-1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(r,-1,sizeof(r));
    for(int i=1;i<=m;i++){
    	cin>>u>>v>>w;
    	r[u][v]=w;
    	r[v][u]=w;
    	ma=max(ma,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>w2[j];
		}
		for(int s=1;s<=n;s++){
			for(int e=s+1;e<=n;e++){
				long long int cnt=(c+w2[s]+w2[e]);
				if(r[s][e]==-1){
					r[s][e]=cnt;
					r[e][s]=cnt;
				}
				else {
					cnt=min(cnt,r[s][e]);
					r[s][e]=cnt;
					r[e][s]=cnt;
				}	
			}
		}
	}
	int d=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans[++d]=r[i][j];
		}
	}
	sort(ans+1,ans+1+d);
	long long int ans2=0;
	for(int i=1;i<n;i++){
		ans2+=ans[i];
	}
	cout<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
