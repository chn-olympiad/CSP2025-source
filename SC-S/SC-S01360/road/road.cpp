#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+10,M=1e6+10,K=15,inf=LONG_LONG_MAX;
struct edge{
	int u,v,w;
	bool vi;
	int c;
	bool operator <(const edge &b)const{
		if(vi)return c<b.c;
		else return w<b.w;
	}
}a[M+K*N];
int fa[N+K];
int n,m,k,tot;
int via[K][N];
int c[K];
int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
class asdf;
void kruskal(){
	long long ans=inf,res=0;
	int cnt=0;
	sort(a+1,a+1+tot);
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		res=0;
		for(int j=1;j<=m+k;j++){
			int u=a[j].u,v=a[j].v;
			if(u>n)res+=c[u-n];
			int uu=find(u),vv=find(v);
			//cout<<uu<<" "<<vv<<endl;
			if(uu==vv)continue;
			res+=a[j].w;
			fa[uu]=vv;
			cnt++;
			if(cnt==n+i-1){
				//cout<<res<<" ";
				ans=min(ans,res);
				break;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	tot=m;
	bool flag;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=false;
		for(int j=1;j<=n;j++){
			cin>>via[i][j];
			if(via[i][j]!=0)flag=false;
			a[++tot].u=n+i,a[tot].v=j,a[tot].w=via[i][j],a[tot].vi=1,a[tot].c=c[i];
		}
	}
	if(flag){
		cout<<0<<endl;
		return 0;
	}
	kruskal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}