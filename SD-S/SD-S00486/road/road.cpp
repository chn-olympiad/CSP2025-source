#include<bits/stdc++.h>
using namespace std;
#define int long long
struct uq{
	int u,v,w;
}d[1100005],minar[15][10015],qzz[100005];
int f[10015],minh[15],n,m,k,c[15],ans,ans1,szq;
bool aaa=1,qy[15];
int ff(int a){
	return f[a]==0?a:f[a]=ff(f[a]);
}
void merg(int a,int b,int w){
	int fa=ff(a),fb=ff(b);
	if(fa==fb) return;
	else{
		ans+=w;
		f[fb]=fa;
	}
}
bool cmp(uq a,uq b){
	return a.w<b.w;
}
int dfs(int cs,uq dd[],int siz){
	int minn=0x3f3f3f3f3f3f3f3f;
	if(cs<=k){
		qy[cs]=0;
		int jh=dfs(cs+1,dd,siz);
		minn=min(minn,jh);
//		cout<<cs<<' '<<minn<<' '<<jh<<endl;
		qy[cs]=1;
		merge(dd+1,dd+1+siz,minar[cs]+1,minar[cs]+1+n,dd,cmp);
		int ty=minh[cs]+dfs(cs+1,dd,siz+n);
		minn=min(minn,ty);
//		cout<<cs<<' '<<minn<<' '<<ty<<endl;
		return minn;
	}
	else{
		ans=0;
		memset(f,0,sizeof f);
		for(int i=1;i<=m;i++){
			merg(d[i].u,d[i].v,d[i].w);
		}
		return ans;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d[i].u>>d[i].v>>d[i].w;
	}
	sort(d+1,d+1+m,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			merg(d[i].u,d[i].v,d[i].w);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>minh[i];
		if(minh[i]!=0) aaa=0;
		for(int j=1;j<=n;j++){
			minar[i][j].v=j+n;
			minar[i][j].u=i;
			cin>>minar[i][j].w;
			if(minar[i][j].w!=0) aaa=0;
		}
		sort(minar[i]+1,minar[i]+n,cmp);
		if(minh[i]==0) merge(minar[i]+1,minar[i]+1+n,qzz+1,qzz+szq+1,qzz,cmp);
		szq+=n;
	}
	merge(qzz+1,qzz+1+szq,d+1,d+n+1,d,cmp);
	if(aaa){
		cout<<0;
		return 0;
	}
	cout<<dfs(1,d,m);
	return 0;
} 
