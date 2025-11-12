#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
//#define int long long

struct node{
	int u,v,w,nxt;
}e[2000010];
bool cmp(node x, node y){return x.w<y.w;}
int a[11][10010],f[10010];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool flag[10020],lit[10020];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	int cur=m;
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++) cin>>a[i][j],e[++cur]={n+i,j,a[i][j]};
	}
	sort(e+1,e+cur+1,cmp);
	long long res=1e18;
	for(int i=1;i<=n;i++) lit[i]=1;
	for(int qw=0;qw<(1<<k);qw++){
		int cnt=1,cntlt=0;
		long long ans=0;
		for(int i=1;i<=k;i++){
			if(((1<<(i-1))&qw)!=0) lit[n+i]=1,ans+=a[i][0],cntlt++;
			else lit[n+i]=0;
		}
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=cur;i++){
			if(!lit[e[i].u]) continue;
			if(find(e[i].u)!=find(e[i].v)){
				cnt++,ans+=e[i].w,f[find(e[i].v)]=find(e[i].u);
				if(cnt==n+cntlt) break;
			}
		}
		res=min(res,ans);
	}
	cout<<res<<'\n';
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
//freopen
//freopen
//Hope to be found.
//I've been retired from OI for more than half a year since ninth grade. I once doubted myself if I should to sign up for CSP this year and just now, I thought I couldn't solve T2.
// Luckily, I zhuiyi how to type zuixiaoshengchengshu, which helps me get 50pts;
//16.08 good luck.
//And, welcome all 9 graders to Hangzhou No.2 High School! Even if you're not planning to OI ahead, it's still a good place for learing as well as chouxiang.
