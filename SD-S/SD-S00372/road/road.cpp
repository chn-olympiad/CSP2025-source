#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5; 
int n,m,k;
struct Node{
	int u;
	int v;
	int w;
}a[N*2],a2[N*2];
ll ans=1e18;
int n2;
int g[15],d[15][N/5];
int f[N/5],s[N/5];
bool pf=1;
inline int read(){
	int k=0,k2=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k2=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*k2;
}
bool cmp(Node x,Node y){ return x.w<y.w; }
void chushi(int x){ for(int i=1;i<=x;i++) f[i]=i,s[i]=1; }
int fa(int x){ return x==f[x]?x:f[x]=fa(f[x]); }
void hebing(int x,int y,int w,ll &o,int &n2){
	int _x=fa(x),_y=fa(y);
	if(_x==_y) return;
	if(s[_x]>s[_y]) swap(_x,_y);
	s[_y]+=s[_x];
	n2--,o=(ll)(o+w);
	f[_x]=_y;
}
void dfs(int p,int m2,ll o,int n2){
	if(p>k){
		for(int i=1;i<=m2;i++) a2[i].w=a[i].w,a2[i].u=a[i].u,a2[i].v=a[i].v;
		stable_sort(a2+1,a2+m2+1,cmp);
		for(int j=1;j<=m2;j++){
			hebing(a2[j].u,a2[j].v,a2[j].w,o,n2);
			if(n2<=1){
				ans=min(o,ans);
				chushi(n*2);
				return;
			}
		}
		chushi(n*2);
		return; 
	}
	for(int i=1;i<=n;i++) ++m2,a[m2].w=d[p][i],a[m2].u=n2+1,a[m2].v=i;
	o+=g[p];
	dfs(p+1,m2,o,n2+1);
	o-=g[p];
	dfs(p+1,m2-n,o,n2);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	n2=n;
	chushi(n*2);
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
	for(int i=1;i<=k;i++){
		g[i]=read();
		if(g[i]!=0) pf=0;
		for(int j=1;j<=n;j++) d[i][j]=read();
	}
	g[0]=0;
	if(pf){
		int m2=m;
		for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		++m2,a[m2].w=d[i][j],a[m2].u=n+i,a[m2].v=j;
	
		ll o=0;
		n+=k;
		stable_sort(a+1,a+m2+1,cmp);
		for(int j=1;j<=m2;j++){
			hebing(a[j].u,a[j].v,a[j].w,o,n);
			if(n<=1){
				ans=min(o,ans);
				chushi(n*2);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,m,0,n);
	cout<<ans;
	return 0;
}

