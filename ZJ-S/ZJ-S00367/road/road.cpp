#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
#define ll long long
struct edge {
	ll u,v,w;
} eg[M];
bool cmp(edge x,edge y) {
	return x.w<y.w;
}
int checke[N];
int checkt[13];
long long n,m,k,c[13][N+1];
int checkf() {
	for(int i=1; i<=n; i++) {
		if(!checke[i])return 0;
	}
	return 1;
}
ll cost=0;
void mkrd() {
	if(checkf())return;	
	ll rcost=eg[0].w;
	ll chpos=-1;
	for(int j=0; j<k; j++) {
		ll chcost=(c[j][0]+c[j][eg[0].u])+c[j][eg[0].v];
		if(chcost<rcost) {
			rcost=chcost;
			chpos=j;
		}
	}
	if(chpos!=-1) {
		checkt[chpos]=1;
	}
	checke[eg[0].u]=1;
	checke[eg[0].v]=1;
	cost+=rcost;
	for(int i=1; i<m; i++) {
		if(checkf())return;
		if(checke[eg[i].v]==0&&checke[eg[i].u]==1){
		rcost=eg[i].w;
		chpos=-1;
		for(int j=0; j<k; j++) {
		ll chcost=c[j][eg[i].v];
			if(checkt[i]==0){
				ll minco=1000006;
				for(int i=1;i<=n;i++){
					if(checke[i]==1){
						minco=min(minco,c[j][i]);
					}
				}
				chcost+=(c[j][0]+minco);	
			}
			if(chcost<rcost) {
				rcost=chcost;
				chpos=j;
			}
		}
		if(chpos!=-1) {
			checkt[chpos]=1;
		}
		checke[eg[i].v]=1;
		cost+=rcost;
		}else if(checke[eg[i].u]==0&&checke[eg[i].v]==1){
			rcost=eg[i].w;
		chpos=-1;
		for(int j=0; j<k; j++) {
		ll chcost=c[j][eg[i].u];
			if(checkt[i]==0){
				ll minco=1000006;
				for(int i=1;i<=n;i++){
					if(checke[i]==1){
						minco=min(minco,c[j][i]);
					}
				}
				chcost+=(c[j][0]+minco);	
			}
			if(chcost<rcost) {
				rcost=chcost;
				chpos=j;
			}
		}
		if(chpos!=-1) {
			checkt[chpos]=1;
		}
		checke[eg[i].u]=1;
		cost+=rcost;
		}
		}
		
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%ld%ld%ld",&m,&n,&k);
	for(int i=0; i<m; i++) {
		scanf("%ld%ld%ld",&eg[i].u,&eg[i].v,&eg[i].w);
	}
	for(int i=0; i<k; i++) {
		scanf("%ld",&c[i][0]);
		for(int h=1; h<=n; h++) {
			scanf("%ld",&c[i][h]);
		}
	}
	sort(eg,eg+m,cmp);
	mkrd();
	printf("%ld",cost);
	return 0;
}
