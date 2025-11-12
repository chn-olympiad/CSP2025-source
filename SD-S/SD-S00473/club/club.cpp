#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int T;
int n,m;
struct node{
	int x,y,z,idx;
}a[N];
bool f[N];
bool fa,fb,fc;
int ans;
int cnt;
bool cmp(node a,node b){
	if(a.x>b.x){
		return a.x>b.x;
	}
	else return a.idx<b.idx;
}
void dfs(int idxx,int nowa,int nowb,int nowc,int sum){
	if(nowa>n/2||nowb>n/2||nowc>n/2||idxx>n) return ;
	if(nowa<=n/2&&nowb<=n/2&&nowc<=n/2&&nowa+nowb+nowc==n){
		ans=max(ans,sum);
		return ;
	}
	dfs(idxx+1,nowa+1,nowb,nowc,sum+a[idxx+1].x);
	
	dfs(idxx+1,nowa,nowb+1,nowc,sum+a[idxx+1].y);
	
	dfs(idxx+1,nowa,nowb,nowc+1,sum+a[idxx+1].z);
}
int tota,totb,totc;
void dfs1(int idxx,int nowa,int nowb,int sum){
	if(nowb>n/2||nowa>n/2||idxx>n) return ;
	if(nowa==n/2&&nowb==n/2&&nowb+nowa==n){
		ans=max(ans,sum);
		return ;
	}
	dfs1(idxx+1,nowa+1,nowb,sum+a[idxx+1].x);
	
	dfs1(idxx+1,nowa,nowb+1,sum+a[idxx+1].y);
}
void solve(){
	cnt=0;
	tota=totb=totc=0;
	memset(f,0,sizeof f);
	ans=0;
	fa=fb=fc=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		a[i].idx=i;
		if(a[i].x!=0) fa=1,tota++;
		else if(a[i].y!=0) fb=1,totb++;
		else if(a[i].z!=0) fc=1,totc++;
	}
	if(n<=40){
		dfs(0,0,0,0,0);
		printf("%lld\n",ans);
		return;
	}
	else{
		if(!fb&&!fc&&fa){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x; 
			}
			printf("%lld\n",ans);
			return;
		}
		if(!fc){
			dfs1(0,0,0,0);
			printf("%lld\n",ans);
			return;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	
	return 0;
}

/*
3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0


*/
