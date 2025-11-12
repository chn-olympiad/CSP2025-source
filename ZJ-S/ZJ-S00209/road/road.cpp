#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>mp;
struct node{
	int u,v,w;
	friend bool operator < (const node a,const node b){
		return a.w<b.w;
	}
}a[1000005];
vector<int>ve[10005];
int fa[10005];
int c[15];
long long down[10][10005],sp[10005];
long long f[10005];
int getint(){
	int res=0;
	char ch;
	ch=getchar();
	while (!isdigit(ch))ch=getchar();
	while (isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int find(int u){
	if (fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
void dfs(int fa,int u,int fr){
	for (int x:ve[u]){
		int v=x,w=f[v];
		if (v==fa)continue;
		int t=mp[make_pair(u,v)];
		if (w<a[t].w)down[fr][t]=a[t].w-w;
		else down[fr][t]=0;
		dfs(u,v,fr);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,w,tot=0;
	int u,v;
	n=getint();m=getint();k=getint();
	for (int i=1;i<=m;i++){
		a[i].u=getint();a[i].v=getint();a[i].w=getint();
	}
	for (int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1);
	int kk=n-1;
	long long ans=0;
	u=0;v=0;
	for (int i=1;i<=m;i++){
		u=a[i].u;v=a[i].v;w=a[i].w;
		int rootu=find(u),rootv=find(v);
		if (rootu!=rootv){
			ve[u].push_back(v);
			ve[v].push_back(u);
			fa[rootu]=rootv;
			a[++tot].u=u;a[tot].v=v;a[tot].w=w;
			ans+=w;
			mp[make_pair(u,v)]=tot;
			mp[make_pair(v,u)]=tot;
			kk--;
			if (kk==0)break;
		}
	}
	f[0]=1e18;
	for (int i=1;i<=k;i++){
		c[i]=getint();
		int minid=0;
		for (int j=1;j<=n;j++){
			f[j]=getint();
			if (f[j]<f[minid])minid=j;
		}
		sp[i]=f[minid]+c[i];
		dfs(0,minid,i);
	}
	long long out=1e18;
	for (int i=(1<<k)-1;i>=0;i--){
		int i1=i;
		long long spe=0,dow=0;
		memset(f,0,sizeof(f));
		for (int j=1;j<=k;j++){
			if (i1%2==1){
				spe+=sp[j];
				for (kk=1;kk<n;kk++)f[kk]=max(f[kk],down[j][kk]);
			}
			i1/=2;
		}
		for (int j=1;j<n;j++){
			dow+=f[j];
		}
		out=min(out,ans-dow+spe);
	}
	printf("%lld\n",out);
	return 0;
}
