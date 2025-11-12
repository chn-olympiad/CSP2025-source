#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Edge{
	int u,v,w;
}a[1200005],h[1000005];
int n,m,k,c[15],b[15][10005],f[10005],s[10005];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void merge(int a,int b){
	int u=find(a),v=find(b);
	if(u==v)return;
	if(s[u]<s[v])swap(u,v);
	f[v]=u;
	s[u]+=s[v];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		h[i]=a[i];
	}bool flg=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];if(c[i])flg=false;
		bool t=true;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			if(!b[i][j])t=false;
		}
		if(t)flg=false;
	}
	if(flg){
		for(int i=1;i<=k;i++){
			int r=0;
			for(r=1;r<=n;r++){
				if(b[i][r]==0)break;
			}
			for(int j=1;j<=n;j++){
				if(j==r)continue;
				a[++m]={r,j,b[i][j]};
			}
		}
		sort(a+1,a+m+1,[](Edge a,Edge b){
			return a.w<b.w;
		});
		int ans=0,ct=0;
		for(int i=1;i<=m&&ct<n-1;i++){
			if(find(a[i].u)!=find(a[i].v)){
				ans+=a[i].w;
				merge(a[i].u,a[i].v);
				ct++;
			}
		}
		cout<<ans;
	}else{
		int ans=LONG_LONG_MAX;
		for(int o=0;o<=(1<<(k))-1;o++){
			for(int i=1;i<=m;i++)a[i]=h[i];
			for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
			int res=0,kk=m;
			for(int i=1;i<=k;i++){
				if(!(o&(1<<(i-1))))continue;
				int r=1;
				for(int rr=2;rr<=n;rr++){
					if(b[i][rr]<b[i][r])r=rr;
				}res+=c[i]+b[i][r];
				for(int j=1;j<=n;j++){
					if(j==r)continue;
					a[++kk]={r,j,b[i][j]};
				}
			}
			sort(a+1,a+kk+1,[](Edge a,Edge b){
				return a.w<b.w;
			});
			int ct=0;
			for(int i=1;i<=kk&&ct<n-1;i++){
				if(find(a[i].u)!=find(a[i].v)){
					res+=a[i].w;
					merge(a[i].u,a[i].v);
					ct++;
				}
			}
			// if(res==0)cerr<<o<<'\n';
			ans=min(ans,res);
		}
		cout<<ans;
	}
}