#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,tiao[11];
struct Edge{
	int x,y,w;
}e[M],e2[M<<1];
struct Xiang{
	int c;
	Edge e[N];
}x[11];
int ans=0x3f3f3f3f3f3f3f3f,fa[N],siz[N];
bool flag[11],you[11];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	return (fa[x]==x)?x:find(fa[x]);
}
void solve(int x2){
	int xx=x2;
	int sum=0;
	int zong=0;
	for(int i=1;i<=k;i++){
		if(xx&1)
			flag[i]=1,sum+=x[i].c,zong++;
		else
			flag[i]=0;
		xx=xx>>1;
	}
	int cnt=m;
	for(int i=1;i<=m;i++)
		e2[i]=e[i];
	for(int i=1;i<=k;i++){
		if(flag[i]){
			for(int j=1;j<=n;j++)
				e2[++cnt]=x[i].e[j];
		}
	}
	for(int i=1;i<=n+k;i++)
		fa[i]=i,siz[i]=1;
	sort(e2+1,e2+cnt+1,cmp);//
	int cnt2=0;
	for(int i=1;i<=cnt;i++){
		int xx=find(e2[i].x);
		int yy=find(e2[i].y);
		if(xx==yy)
			continue;
		sum+=e2[i].w;
		if(siz[xx]>siz[yy]){
			fa[yy]=xx;
			siz[yy]+=siz[xx],siz[xx]=0;
		}else{
			fa[xx]=yy;
			siz[xx]+=siz[yy],siz[yy]=0;
		}
		cnt2++;
		if(cnt2==n+zong-1)
			break;
	}
	ans=min(ans,sum);
}
signed main(){
	//Ö±½Ó±©Á¦
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].w;
	bool flagg=1;
	for(int i=1;i<=k;i++){
		cin>>x[i].c;
		if(x[i].c!=0)	flagg=false;
		for(int j=1;j<=n;j++){
			x[i].e[j].x=i+n;
			x[i].e[j].y=j;
			cin>>x[i].e[j].w;
			if(x[i].e[j].w!=0)
				flagg=false;
		}
	}
	if(flagg){
		int ww=(1<<k);
		solve(ww-1);
		cout<<ans<<"\n";
		return 0;
	}
	if(k<=5){
		for(int i=0;i<(1<<k);i++){
			solve(i);
		}
	}
	else{
		for(int i=0;i<(1<<k);i++){
			int ccnt=0;
			for(int j=1;j<=k;j++){
				if(i&(1<<j-1))
					ccnt++;
			}
			if(ccnt<=3)
				solve(i);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
