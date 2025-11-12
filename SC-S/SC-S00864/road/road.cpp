#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 5050000

int cnt,n,m,K,U,V,W,anss=1e17,ans,cg,maxc=0;
int fa[N],gai[N],a[15][1500000],c[N];

struct l{
	int from,to,w;
}e[N*5];

void add(int u,int v,int w){
	e[++cnt].from=u;
	e[cnt].to=v;
	e[cnt].w=w;
}

int cmp(l a,l b){
	return a.w<b.w;
}
int cmp2(l a,l b){
	return a.w>b.w;
}

int find(int a){
	if(fa[a]==a)	return a;
	return fa[a]=find(fa[a]);
}

void Ku(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n+K;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int a=e[i].from,b=e[i].to,w=e[i].w;
		int af=find(a),bf=find(b);
		if(af==bf){
			e[i].w=-1;
			continue ;
		}	
		fa[af]=fa[bf];
		ans+=w;
	}
	sort(e+1,e+1+m,cmp2);
	cnt=m;
	for(int i=m;i>=1;i--){
		if(e[i].w>=0)	break ;
		cnt--;
	}
}

void kuscal(){
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n+K;i++)
		fa[i]=i;
	for(int i=1;i<=cnt;i++){	
		int a=e[i].from,b=e[i].to,w=e[i].w;
		int af=find(a),bf=find(b);
		if(af==bf){
			continue ;
		}	
		fa[af]=fa[bf];
		ans+=w;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		cin>>U>>V>>W;
		add(U,V,W);
	}
	for(int i=1;i<=K;i++){
		cin>>c[i];
		maxc=max(maxc,c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	Ku();
	if(K==0){
		cout<<ans;
		return 0;
	}
	int yuancn=cnt;//原来边的数量 
	if(maxc==0){
		ans=0;
		for(int i=1;i<=K;i++){
			gai[++cg]=i;
		}
		cnt=yuancn;
		for(int j=1;j<=cg;j++){
			int vii=0;
			for(int k=1;k<=n;k++){
				add(gai[j]+n,k,a[gai[j]][k]);
				if(a[gai[j]][k]==0)	vii=1;
			}
			if(!vii)	cout<<endl;
		}
		kuscal();
		anss=min(ans,anss);
		cout<<anss;
		return 0;
	}
	for(int i=0;i<(1<<K);i++){
		cg=0;ans=0;cnt=yuancn;
//		for(int j=yuancn+1;j<=cnt;j++){
//			e[j].from=0;e[j].to=0;e[j].w=0;
//		}
//		memset(gai,0,sizeof(gai));
		for(int j=1;j<=K;j++){
			if((i&(1<<(j-1)))){
				gai[++cg]=j;//要建设的是哪些城市 
			}
		}
		for(int j=1;j<=cg;j++){
			//加边 
			ans+=c[gai[j]];
			for(int k=1;k<=n;k++){
				add(gai[j]+n,k,a[gai[j]][k]);
//				cout<<a[gai[j]][k]<<" "<<a[k][gai[j]]<<endl;
			}
		}
//		for(int j=1;j<=cnt;j++){
//			cout<<e[j].from<<" "<<e[j].to<<" "<<e[j].w<<endl; 
//		}
		//针对每次加边来一遍生成树 
		kuscal();
//		cout<<ans<<endl;
		anss=min(ans,anss);
	}
	cout<<anss;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/