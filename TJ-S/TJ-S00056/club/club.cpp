#include<bits/stdc++.h>
#include<queue>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
ll sum;
int t;
struct nodess{
	int x[4],maxx,maxji,midx,midji,minji,minx;
	int otn;
}a[100009];
struct node{
	int dif,curi;
	bool operator > (node y) const{
		return dif>y.dif;
	}
};
int n;
struct nodes{
	priority_queue<node,vector<node>,greater<node> >q;
}b[4][4];
int vis[4];
void upd(int cur,int ji){
	a[cur].otn=ji;
	for(int i=1;i<=3;i++){
		if(i==ji)continue;
		b[ji][i].q.push({a[cur].x[ji]-a[cur].x[i],cur});
	}
}
void checkandupd(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i!=j){
				if(!b[i][j].q.empty()&&(a[b[i][j].q.top().curi].otn==j||a[b[i][j].q.top().curi].otn!=i))b[i][j].q.pop();
			}
		}
	}
}
void Main(){
	scanf("%d",&n); 
	sum=0;
	vis[1]=vis[0]=vis[2]=vis[3]=0;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(i!=j){
				while(!b[i][j].q.empty()){
					b[i][j].q.pop();
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
		a[i].maxx=max(a[i].x[1],max(a[i].x[2],a[i].x[3]));
		if(a[i].x[1]==a[i].maxx){
			a[i].maxji=1;
			if(a[i].x[2]>a[i].x[3]){
				a[i].midji=2;
				a[i].minji=3;
			}
			else{
				a[i].midji=3;
				a[i].minji=2;
			}
		}
		else if(a[i].x[2]==a[i].maxx){
			a[i].maxji=2;
			a[i].midx=max(a[i].x[1],a[i].x[3]);
			if(a[i].x[1]>a[i].x[3]){
				a[i].midji=1;
				a[i].minji=3;
			}
			else{
				a[i].midji=3;
				a[i].minji=1;
			}
		}
		else{
			a[i].maxji=3;
			a[i].midx=max(a[i].x[1],a[i].x[2]);
			if(a[i].x[1]>a[i].x[2]){
				a[i].midji=1;
				a[i].minji=2;
			}
			else{
				a[i].midji=2;
				a[i].minji=1;
			}
		}
		a[i].midx=a[i].x[a[i].midji];
		a[i].minx=a[i].x[a[i].minji];
	}
	for(int i=1;i<=n;++i){
		checkandupd();
		if(vis[a[i].maxji]<n/2){
			sum+=a[i].maxx;
			++vis[a[i].maxji];
			upd(i,a[i].maxji);
		}
		else if(a[i].maxx-a[i].midx>min(b[a[i].maxji][a[i].midji].q.top().dif,b[a[i].maxji][a[i].minji].q.top().dif)){
			sum+=a[i].maxx;
			sum-=min(b[a[i].maxji][a[i].midji].q.top().dif,b[a[i].maxji][a[i].minji].q.top().dif);
			upd(i,a[i].maxji);
			if(b[a[i].maxji][a[i].midji].q.top().dif<b[a[i].maxji][a[i].minji].q.top().dif){
				vis[a[i].midji]++;
				upd(b[a[i].maxji][a[i].midji].q.top().curi,a[i].midji);
				b[a[i].maxji][a[i].midji].q.pop();
			}
			else{
				vis[a[i].minji]++;
				upd(b[a[i].maxji][a[i].minji].q.top().curi,a[i].minji);
				b[a[i].maxji][a[i].minji].q.pop();
			}
		}
		else{
			vis[a[i].midji]++;
			sum+=a[i].midx;
			upd(i,a[i].midji);
		}
	}
	printf("%lld",sum);
	puts("");
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)Main();
	return 0;

}

