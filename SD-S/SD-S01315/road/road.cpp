#include<bits/stdc++.h>
using namespace std;
#define itn int
int vis[7000][7000];
int kv[12][7000],a[10020];
struct wb{
	int u;
	int v;
	int w;
}mi[1000200];
int wbxl(int n){
	int ctt=0;
	for(int i=0;i<n;i++){
		if(a[mi[i].v]==1) continue;
		a[mi[i].u]=1;a[mi[i].v]=1;
		ctt+=mi[i].w;
	}
	return ctt;
}
bool cmp(wb a,wb b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);//我不行了，4年oi一场空，开了ull也不好使 100pts- 放弃挣扎了 
	cin.tie(0);cout.tie(0);
	int n,m,k,uu,vu,wu;	
	cin>>n>>m>>k;
	int kk[k];
	for(int i=0;i<m;i++){
		cin>>uu>>vu>>wu;
		mi[i].u=uu;mi[i].v=vu;mi[i].w=wu;
	}
	sort(mi,mi+m,cmp);
	for(int i=0;i<k;i++){
		cin>>kk[i];
		for(int j=0;j<n;j++){
			cin>>kv[i][j];
			
		}
	}
	cout<<wbxl(n);
	return 0;
}
