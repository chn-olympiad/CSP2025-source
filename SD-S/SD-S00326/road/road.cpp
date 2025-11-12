#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+100,M=2e6+10;
int n,m,k;
struct L{
	int a,b,w;
}edges1[M],edges2[M];
int p[N];
int cnt,sm,sk;
LL res,ans=LLONG_MAX;
bool ok[N];
int c[N];

bool cmp(L a,L b){
	return a.w<b.w;
}

int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}

bool check(int a,int b){
	if(a>n&&!ok[a-n]) return false;
	if(b>n&&!ok[b-n]) return false;
	return true;
}

void solve(){
	for(int i=1;i<=n+k;i++) p[i]=i;
	cnt=sk;
	for(int i=1;i<=sm;i++){
		int a=edges2[i].a,b=edges2[i].b,c=edges2[i].w;
		int pa=find(a),pb=find(b);
		if(pa!=pb&&check(a,b)){
			res+=c;
			cnt--;
			p[pa]=pb;
		}
		if(cnt==1) break;
	}
	ans=min(ans,res);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edges1[i]={a,b,c};
	}
	sort(edges1+1,edges1+m+1,cmp);
	for(int i=1;i<=m;i++){
		int a=edges1[i].a,b=edges1[i].b,c=edges1[i].w;
		int pa=find(a),pb=find(b);
		if(pa!=pb){
			edges2[++sm]={a,b,c};
			p[pa]=pb;
		}
	}
	
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			edges2[++sm]={j,i+n,x};
		}
	}
	
	sort(edges2+1,edges2+sm+1,cmp);
	for(int i=0;i<(1<<k);i++){
		res=0;
		sk=n;
		memset(ok,0,sizeof(ok));
		for(int j=0;j<k;j++)
			if((i>>j)&1){
				sk++;
				res+=c[j+1];
				ok[j+1]=1;
			}
		solve();
	}
	printf("%lld\n",ans);
	return 0;
}
