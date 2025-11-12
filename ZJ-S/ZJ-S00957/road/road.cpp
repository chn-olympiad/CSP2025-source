#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rg register
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=1e4+20;
const int M=1e6+10;
int f[N],siz[N];
inline int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
struct edge{
	int u,v,w;
	bool operator < (const edge &ee)const{
		return w<ee.w;
	}
}e[M];
int a[11][N];
int n,m,k;
int ans=LONG_LONG_MAX;
bool fl[11];
inline void solve(){
	vector<edge>v;
	int an=0,cn=0;
	for(rg int i=1;i<=k;i++){
		if(fl[i]){
			cn++;
			an+=a[i][0];
			for(rg int j=1;j<=n;j++)v.push_back({n+i,j,a[i][j]});
		}
	}
	sort(v.begin(),v.end());
	for(rg int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
	int t1=1,t2=0,cnt=0;
	while(cnt<n+cn-1){
		if(an>=ans)break;
		if(t1>m&&t2>=v.size())break;
		if(t1>m||t2<v.size()&&v[t2].w<e[t1].w){
			int f1=find(v[t2].u),f2=find(v[t2].v);
			if(f1!=f2){
				if(siz[f1]<siz[f2])swap(f1,f2);
				f[f2]=f1;
				an+=v[t2].w,cnt++;
			}
			t2++;
		}else{
			int f1=find(e[t1].u),f2=find(e[t1].v);
			if(f1!=f2){
				if(siz[f1]<siz[f2])swap(f1,f2);
				f[f2]=f1;
				an+=e[t1].w,cnt++;
			}
			t1++;
		}
	}
	ans=min(ans,an);
}
inline void dfs(int x){
	if(x==k+1){
		solve();
		return ;
	}
	dfs(x+1);
	fl[x]=1;
	dfs(x+1);
	fl[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(rg int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	for(rg int i=1;i<=k;i++){
		a[i][0]=read();
		for(rg int j=1;j<=n;j++)a[i][j]=read();
	}
	dfs(1);
	write(ans);
}
