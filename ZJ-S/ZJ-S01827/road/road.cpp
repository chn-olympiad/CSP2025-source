#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,m,k;
struct EDGE{
	int fro,to,len;
}edge[MAXN];
bool cmp(EDGE x,EDGE y){
	return x.len<y.len;
}
int fa[MAXN];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int c[15];
int w[15][MAXN];
int kruscal(int num){
	int ans=0;
	sort(edge+1,edge+1+num,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=num;i++){
		int eu=find(edge[i].fro);
		int ev=find(edge[i].to);
		if(eu==ev) continue;
		fa[eu]=ev;
		ans+=edge[i].len;
	}
	return ans;
}
int cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].fro>>edge[i].to>>edge[i].len;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
		if(c[i]==0){
			for(int j=1;j<=n;j++){
				edge[++m].fro=++n;
				edge[m].to=j;
				edge[m].len=w[i][j];
			}
			cnt++;
		}
	}
	k-=cnt;
	if(k==0){
		cout<<kruscal(m);
	}
	return 0;
}

