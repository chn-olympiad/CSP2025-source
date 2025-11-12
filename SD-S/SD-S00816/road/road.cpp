#include<bits/stdc++.h>
using namespace std;
int n,m,k,t=1,ans=0,ans2=0,d[10005];
int u[1000005],v[1000005],w[1000005],c[11],a[11][10005];
int s[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0){
				t=0;
			}
		}
	}
	if(t==1){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				d[j]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(d[u[i]]!=1||d[v[i]]!=1){
				ans=ans+w[i];
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				s[j]=a[i][j]+c[i];
			}
		}
		for(int i=1;i<=m;i++){
			if((s[u[i]]+s[v[i]])<w[i]&&s[u[i]]!=0&&s[v[i]]!=0){
				s[u[i]]=s[u[i]];
				s[v[i]]=s[v[i]];
			}else{
				s[u[i]]=w[i]/2;
				s[v[i]]=w[i]/2;
			}
		}
		for(int i=1;i<=n;i++){
			ans2=ans2+s[i];
		}
		cout<<ans2;
	}
	return 0;
}

