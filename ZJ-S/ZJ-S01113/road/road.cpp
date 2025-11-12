#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10,N=1e3+10;
int n,m,k;
int ans=0;
int f[N*10];
struct node{
	int u,v,w;
}b[M];
int c[12][N];

int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int zxscs(int n,int m){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++)f[i]=i;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=b[i].u,v=b[i].v;
		if(f[u]!=f[v]){
			f[u]=f[v];
			cnt++;
			sum+=b[i].w;
			if(cnt==n-1){
				return sum;
			}
		}
	}
	
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	if(k==0){
		cout<<zxscs(n,m)<<endl;
	}
	else if(n<=1e3){
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				cin>>c[i][j];
			}
		}
		for(int i=0;i<=1<<k;i++){
			int cnt=0,cn=n,cm=m;
			for(int j=0;j<=k;j++){
				if((1<<j)&i){
					cnt+=c[j][0];
					cn++;
					for(int id=m+1;id<=m+n;id++){
						b[id].u=cn;
						b[id].v=id-m;
						b[id].w=c[j][id-m];
					}
				}
			}
			cnt+=zxscs(cn,cm);
			ans=max(cnt,ans);
		}
	}
	else{
	}
	return 0;
}
