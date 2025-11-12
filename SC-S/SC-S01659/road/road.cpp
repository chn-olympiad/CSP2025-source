#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
template <typename T> void getmin(T &a,T b){
	if(b<a) a=b;
	return;
}
template <typename T> void getmax(T &a,T b){
	if(b>a) a=b;
	return;
}
int n,m,k;
struct EDGE{
	int x,y,id;
	ll z;
	bool operator < (const EDGE &w) const{
		return z<w.z;
	}
}E[1000005];
ll mp[15][10005];
bool ok[1000005];
int fa[20005];
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void init(){
	for(int i=1;i<=n+k;++i) fa[i]=i;
	return;
}
ll ans=9e18;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),z=read();
		E[i]={x,y,0,z};
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j) mp[i][j]=read();
	}
	init();
	sort(E+1,E+m+1);
	for(int i=1;i<=m;++i){
		int fx=getfa(E[i].x),fy=getfa(E[i].y);
		if(fx==fy) continue;
		fa[fx]=fy;
		ok[i]=1;
	}
	int ecnt=0;
	for(int i=1;i<=m;++i){
		if(ok[i]) E[++ecnt]=E[i];
	}
	m=ecnt;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			E[++m]={n+i,j,i,mp[i][j]};
		}
	}
	sort(E+1,E+m+1);
	for(int s=0;s<(1<<k);++s){
		init();
		ll sum=0;
		for(int i=1;i<=k;++i){
			if((s>>i)&1) sum+=mp[i][0];
		}
		if(sum>ans) continue;
		bool flag=1;
		for(int i=1;i<=m;++i){
			if(E[i].id==0||((s>>E[i].id)&1)){
				int fx=getfa(E[i].x),fy=getfa(E[i].y);
				if(fx==fy) continue;
				fa[fx]=fy;
				sum+=E[i].z;
				if(sum>ans){
					flag=0;
					break;
				}
			}
		}
		if(flag==0) continue;
		getmin(ans,sum);
//		if(ans==sum){
//			cout<<s<<endl;
//		}
	}
	cout<<ans<<endl;
	
	return 0;
}