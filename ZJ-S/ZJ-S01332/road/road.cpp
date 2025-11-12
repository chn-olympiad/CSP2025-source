#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int a[11][10005];
int fa[50005],c[50005];
struct Node{
	int u,v,w;
}x[5000005];
int find(int id){
	if(fa[id]==id) return id;
	return fa[id]=find(fa[id]);
}
bool cmp(Node x,Node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;	
	for(int i=1;i<=m;i++){
		if(i<=n){
			fa[i]=i;
		}
		int u,v,w;
		cin>>u>>v>>w;
		x[i].u=u,x[i].v=v,x[i].w=w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(flag){
		for(int i=1;i<=k;i++){
			n+=1;
			fa[n]=n;
			for(int j=1;j<=n-i;j++){
				m+=1;
				x[m]={n,j,a[i][j]};
			}
		}
		sort(x+1,x+1+m,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			if(find(x[i].u)!=find(x[i].v)){
				ans+=x[i].w;
				fa[x[i].u]=x[i].v;
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=0;i<pow(k,2);k++){
		for(int j=1;j<=n;j++) fa[i]=i;
		int k=i;
		int cnt=1;
		int xm=m;
		int xx=n;
		while(k){
			if(k%2==1){
				xx+=1;
				fa[xx]=xx;
				for(int i=1;i<=k;i++){
					for(int j=1;j<=n;j++){
						xm+=1;
						x[xm]={xx,j,a[i][j]};
					}
				}
			}
			k/=2;
			cnt++;
		}
		sort(x+1,x+1+xm,cmp);
		int ccnt=0;
		for(int kk=1;kk<=xm;kk++){
			if(find(x[kk].u)!=find(x[kk].v)){
				ccnt+=x[kk].w;
				fa[x[kk].u]=x[kk].v;
			}
		}
		ans=max(ccnt,ans);
	}	
	cout<<ans;
	return 0;
} 
