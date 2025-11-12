#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=1e6+5;
int n,m,k,u,v,w,fa[N],siz[N],c,aa,nn;
long long ans;
/*
int Find(int x){
	if(x==fa[x])return x;
	int fx=Find(fa[x]);
	fa[x]=fx;
	return fx;
}
void merge(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(siz[fx]<siz[fy]){
		fa[fx]=fy;
	}
	else if(siz[fx]>siz[fy]){
		fa[fy]=fx;
	}
	else fa[fx]=fy,siz[fy]++;
}*/
int Find(int x){return x==fa[x]?x:x=Find(fa[x]);
}
void merge(int x,int y){fa[Find(x)]=Find(y);
}
struct edge{
    int u,v,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge>a;
long long solve(int tar){//最小生成树要包含几条边
    sort(a.begin(),a.end(),cmp);
    for(int i=1;i<=10010;i++)fa[i]=i,siz[i]=1;
    int cnt=0;
	long long res=0;
    for(auto it:a){
        if(cnt>=tar)break;
        int u=it.u,v=it.v,w=it.w;
        if(Find(u)!=Find(v))merge(u,v),res+=w,cnt++;
    }
    return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a.push_back({u,v,w});
    }
    ans=solve(nn=n-1);
    for(int i=1;i<=k;i++){
        cin>>c;
        nn++;
        for(int j=1;j<=n;j++){
            cin>>aa;
            a.push_back({j,n+i,aa});
        }
        int cost=solve(nn)+c;
        if(cost>ans){
            for(auto it:a)
                if(it.v==n+i)it.w=2e9;
            nn--;
        }
        else ans=cost;
    }
    cout<<ans;
	return 0;
}//freopen
