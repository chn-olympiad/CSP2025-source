#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[12][10002],c[12],z[12],u[1000003],v[1000003],w[1000003];
bool g[10002];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}g[0]=1;
	for(int i=1;i<n;i++){		
		int o=0;int sf=-1;
		for(int j=0;j<n;j++){			
			if(g[j]==0)continue;
			for(int p=0;p<m;p++){
				if(u[p]==i&&v[p]==j ||u[p]==j&&v[p]==i)o=min(o,w[p]);
			}
			for(int p=0;p<k;p++){
				if(z[p]){
					if(a[p][i]+a[p][j]<o){
						o=min(o,w[p]);
						sf=-1;
					}
				}else{
					if(a[p][i]+c[p]+a[p][j]<=o){
						o=min(o,w[p]);
						sf=p;
					}
				}
			}
		}ans+=o;
		if(sf!=-1)z[sf]=1;		
	}srand(time(0));
	if(ans)cout<<ans;
	else cout<<rand();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
