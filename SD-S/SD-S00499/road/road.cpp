#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e4+5,M=1e6+5,K=12;
vector <int> a[N];
int n,m,k,fa[N];
struct nood{
	int u,v;
	ll w;
}u[M];
ll c[K];
ll read(){
	char c=getchar();
	ll s=0,p=1;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
bool cmp(nood a,nood b){
	return a.w<b.w;
}
int zu(int x){
	if(x==fa[x]) return x;
	else return fa[x]=zu(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		u[i].u=read(),u[i].v=read(),u[i].w=read();
		a[u[i].u].push_back(i);
		a[u[i].v].push_back(i);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			u[m+k*n+j].u=i,u[m+k*n+j].u=j;
			u[m+k*n+j].w=read();
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(u+1,u+1+m,cmp);
//	for(int i=1;i<=m;i++) cout<<u[i].w<<" ";
	int pjr=0,i=1;
	ll ans=0;
	int vi,ui;
	ll wi;
//	cout<<n;
	while(pjr<(n-1)){
		vi=u[i].v,ui=u[i].u,wi=u[i].w;
		if(zu(vi)==zu(ui)){
			i++;
			continue; 
		}
		fa[fa[vi]]=fa[ui];
		ans+=wi;
		i++,pjr++;
	//	cout<<pjr<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
