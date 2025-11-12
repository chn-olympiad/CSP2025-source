#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define pb push_back

const int N=1e6+5;
const int M=1e4+5;

struct node{
	int x,y,z;
}a[N];

int n,m,k;

struct nd{
	int x,y,z,id;
}c[M*10];

node b[M];
nd d[M*10];

bool cmp(node A,node B){return A.z<B.z;}
bool cmp2(nd A,nd B){return A.z<B.z;}

int va[11];
int cnt;
int fa[M+10];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	fa[find(x)]=find(y);
}

void solver_008(){
	int ans=0;
	cin>>n>>m>>k;
	rep(i,1,m)cin>>a[i].x>>a[i].y>>a[i].z;
	rep(i,1,k){
		cin>>va[i];
		rep(j,1,n){
			int x;cin>>x;
			c[++cnt]={i+n,j,x,i};
		}
	}
	sort(c+1,c+cnt+1,cmp2);
	cnt=0;
	sort(a+1,a+m+1,cmp);
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		if(find(a[i].x)==find(a[i].y))continue;
		b[++cnt]=a[i];
		merge(a[i].x,a[i].y);
		ans+=a[i].z;
	}
	cnt=0;
	rep(p,1,k){
		rep(i,1,n+k)fa[i]=i;
		int l1=1,l2=1;
		while(l1<=n-1||l2<=n*k){
			if(l2<=n*k&&c[l2].id!=p){l2++;continue;}
			int v1=1e10,v2=1e10;
			if(l1<=n-1)v1=b[l1].z;
			if(l2<=n*k)v2=c[l2].z;
			int x,y,F=0;
			if(v1<v2){
				x=b[l1].x,y=b[l1].y;
				l1++;
			}else{
				x=c[l2].x,y=c[l2].y;
				l2++;
				v1=v2;
				F=1;
			}
			if(find(x)==find(y))continue;
			merge(x,y);
			if(F)d[++cnt]=c[l2-1];
		}
	}
	sort(d+1,d+cnt+1,cmp2);
	rep(s,1,(1<<k)-1){
		int sum=0;
		rep(i,1,n+k)fa[i]=i;
		rep(i,1,k)if(s&(1<<i-1))sum+=va[i];
		int l1=1,l2=1;
		while(l1<=n-1||l2<=cnt){
			if(l2<=cnt&&!(s&(1<<d[l2].id-1))){l2++;continue;}
			int v1=1e10,v2=1e10;
			if(l1<=n-1)v1=b[l1].z;
			if(l2<=cnt)v2=d[l2].z;
			int x,y;
			if(v1<v2){
				x=b[l1].x,y=b[l1].y;
				l1++;
			}else{
				x=d[l2].x,y=d[l2].y;
				l2++;
				v1=v2;
			}
			if(find(x)==find(y))continue;
			sum+=v1;
			merge(x,y);
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __T=1;
	while(__T--){
		solver_008();
	}
	return 0;
}
