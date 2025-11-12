#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;int f=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) f=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	if(f) x=-x; 
}
int n,m,k;
struct edges{
	int x,y,z;
}a[N],b[11][N],b2[11][N];
bool cmp(edges a,edges b){
	return a.z<b.z;
}
int c[N];

int fa[N],siz[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y) return 0;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y;siz[y]+=siz[x];
	return 1;
}

ll ans=0x3f3f3f3f3f3f3f3f;
void dfs(int x,int s,int sz){
	if(x==k){
		ll sum=0;
		for(int i=1;i<=k;i++) if(s&(1<<i-1)) sum+=c[i];
		for(int i=1;i<=sz;i++) sum+=b2[x][i].z;
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=sz;i++) b2[x+1][i]=b2[x][i];
	dfs(x+1,s,sz);
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	int p=0,i=1,j=1;
	while(i<=sz||j<=n){
		if(i>sz){
			if(merge(b[x+1][j].x,b[x+1][j].y)) b2[x+1][++p]=b[x+1][j];
			j++;
		}else if(j>n){
			if(merge(b2[x][i].x,b2[x][i].y)) b2[x+1][++p]=b2[x][i];
			i++;
		}else if(b2[x][i].z<b[x+1][j].z){
			if(merge(b2[x][i].x,b2[x][i].y)) b2[x+1][++p]=b2[x][i];
			i++;
		}else{
			if(merge(b[x+1][j].x,b[x+1][j].y)) b2[x+1][++p]=b[x+1][j];
			j++;
		}
	}
	dfs(x+1,s+(1<<x),sz+1);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++) read(a[i].x),read(a[i].y),read(a[i].z);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	int cnt=0;
	for(int i=1;i<=m;i++) if(merge(a[i].x,a[i].y)) b2[0][++cnt]=a[i];
	sort(b2[0]+1,b2[0]+n,cmp);
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			int z;
			read(z);
			b[i][j]={i+n,j,z};
		}
		sort(b[i]+1,b[i]+n+1,cmp);
	}
	dfs(0,0,n-1);
	cout<<ans<<"\n";
	return 0;
}

/*

4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4

*/
