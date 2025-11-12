#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
typedef long long ll;
const int maxn=2e6+27;

int n,m,k;
int op;
int a[maxn],fa[maxn];

int res=INT_MAX;

struct road{
	int u,v;
	ll w;
}e[maxn];

road t[maxn];

bool cmp(road x,road y){
	return x.w<y.w;
}

void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

void clea(){
	for(int i=1;i<=m;i++){
		t[i].u=e[i].u;
		t[i].v=e[i].v;
		t[i].w=e[i].w;
	}
}

int find(int x){
	if(x!=fa[x])
		fa[x]=find(fa[x]);
	return fa[x];
}

bool merge(int a,int b){
	int p=find(a);
	int q=find(b);
	if(p==q) return false;
	fa[q]=p;
	return 1;
}

int kruskal(){
	int ans=0;
	int tot=0;
	for(int i=1;i<=m+k;i++){
		if(merge(t[i].u,t[i].v)==1){
			ans+=t[i].w;
			tot++;
			if(tot==n-1)
				return ans;
		}
	}
	return INT_MAX;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int j=m+1;j<=k+m;j++){
		clea();
		cin>>op;
		for(int i=1;i<=n;i++){
			ll ww;
			cin>>ww;
			t[j].u=op;
			t[j].v=i;
			t[j].w=ww;
		}
		sort(t+1,t+m+k,cmp);
		init();
		res=min(res,kruskal());
	}
	cout<<res<<endl;
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
