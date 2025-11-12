#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4+5;
int n,m,k,l,r,b[12],a[12][MAXN],f[MAXN],num;
ll ans;
int find(int x){
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}
struct abc{int u,v;ll w;};
vector<abc> e;
abc x;
bool cmp(abc n1,abc n2){return n1.w<n2.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		x.u=u;
		x.v=v;
		x.w=w;
		e.push_back(x);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		num=0;
		for(int j=1;j<=n;j++){
			if (a[i][j]==0){
				if (num==0){
					num=j;
					for(int o=1;o<=n;o++){
						if (a[i][o]==0) continue;
						x.u=o;
						x.v=j;
						x.w=a[i][o];
						e.push_back(x);
					}
				}else f[j]=num;
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		l=find(e[i].u);
		r=find(e[i].v);
		if (l!=r){
			ans+=e[i].w;
			f[l]=r;
		}
	}
	cout<<ans;
	return 0;
}
