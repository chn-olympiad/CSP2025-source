#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e4+5;
struct edge{
	int u,v,w;
}r[N];
int n,m,k,u1,v1,w1,c[15][N],ans=0,si=0,flag[N];
bool vis[N],vr[N];
vector<edge> l[N];
void prim(){
	u1=1;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<l[u1].size();j++){
			v1=l[u1][j].v;
			if(!vis[v1]){
				r[i-1]=l[u1][j];
				vis[v1]=1;
				break;
			}
			if(j==l[u1].size()-1){
				u1=r[i-2].u;
			}
		}
	}
}
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
struct lll{
	int val,id;
}w3[N];
bool cmp2(const lll &a,const lll &b){
	return a.val<b.val;
}
bool serach(int x,int a[]){
	for(int i=0;i<si;i++){
		if(a[i]==x)return true;
	}
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u1,&v1,&w1);
		l[u1].push_back({u1,v1,w1});
		l[v1].push_back({v1,u1,w1});
	}
	for(int i=1;i<=n;i++)sort(l[i].begin(),l[i].end(),cmp);
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%d",&c[i][j]);
	}
	prim();
	for(int i=1;i<n;i++)ans+=r[i].w;
	sort(r+1,r+n,cmp);
	while(k--){
		for(int j=n-1;j>=1;j--){
			int w1=r[j].w,w2=c[k][0]+c[k][r[j].u]+c[k][r[j].v];
			w3[j].val=w1-w2;
			w3[j].id=j;
		}
		sort(w3+1,w3+n,cmp2);
		for(int i=n-1;i>=1;i--){
			if(w3[i].val>0&&!serach(w3[i].id,flag)){
				ans-=w3[i].val;
				flag[si]=w3[i].id;
				si++;
			}
			if(w3[i].val<=0)break;
		}
	}
	printf("%d",ans);
	return 0;
} 
/*
9 10 0
1 3 1
2 3 2
3 9 3
9 8 4
8 7 5
8 6 6
7 6 7
5 6 8
5 4 9
4 3 10
*/
