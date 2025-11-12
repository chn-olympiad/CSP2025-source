#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int ed,w;
	int fl;//0:city->city, 1:city->vlg, 2:vlg->city.
	int st;
};
vector<edge> cty[20055],vlg[20];//city  village
vector<edge> es;//edges that can be gone
bool visc[10005],visv[105];
int cnt=1,vw[20],vnum[20];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		cty[u].push_back({v,w,0,u});
		cty[v].push_back({u,w,0,v});
//		cty[u].ed=v,cty[u].w=w;
//		cty[v].ed=u,cty[v].w=w;
	}
	for(int i=1;i<=k;i++){//village
		scanf("%d",&vw[i]);
		for(int j=1,w;j<=n;j++){//city
			scanf("%d",&w);
			vlg[i].push_back({j,w,2,i});
			cty[j].push_back({i,w,1,j});
		}
	}
	visc[1]=1;
	for(int i=0;i<cty[1].size();i++){
		es.push_back({cty[1][i].ed,cty[1][i].w,cty[1][i].fl,cty[1][i].st});
//		cout<<cty[1][i].st<<"->"<<cty[1][i].ed<<" "<<cty[1][i].w<<" "<<cty[1][i].fl<<endl;
	}
//	cout<<"--------------------\n";
	while(cnt<n){
//		cout<<endl;
		int mn=INT_MAX,mni=-1;
		for(int i=0;i<es.size();i++){//find edge \  st    ed
			if(es[i].fl==0 and visc[es[i].ed]==0){//city->city
				if(es[i].w<mn){
					mn=min(mn,es[i].w);
					mni=i;
				}
			}
			if(es[i].fl==1 and visv[es[i].ed]==0){//city->vlg
				if(vnum[es[i].ed]==0){
					if(es[i].w+vw[es[i].ed]<mn){
						mn=min(mn,es[i].w+vw[es[i].ed]);
						mni=i;
					}
				}
				else{
					if(es[i].w<mn){
						mn=min(mn,es[i].w);
						mni=i;
					}
				}
			}
			if(es[i].fl==2 and visc[es[i].ed]==0){//vlg->city
				if(es[i].w<mn){
					mn=min(mn,es[i].w);
					mni=i;
				}
			}
//			cout<<es[i].st<<"->"<<es[i].ed<<" "<<es[i].w<<" "<<es[i].fl<<endl;
		}
//		cout<<mni<<"(+1) "<<mn<<endl;
		if(es[mni].fl==0 or es[mni].fl==2) cnt++;//go to a new city
		if(es[mni].fl==0){//city->city
//			cout<<"A"<<endl;
			visc[es[mni].ed]=1;
			ans+=es[mni].w;
			for(int i=0;i<cty[es[mni].ed].size();i++){//add edges
				if(visc[cty[es[mni].ed][i].ed]==0) es.push_back({cty[es[mni].ed][i].ed,cty[es[mni].ed][i].w,cty[es[mni].ed][i].fl,cty[es[mni].ed][i].st});
			}
		}
		else if(es[mni].fl==1){//city->vlg
			visv[es[mni].ed]=1;
			if(vnum[es[mni].ed]==0) ans+=vw[es[mni].ed];
			ans+=es[mni].w;
			for(int i=0;i<vlg[es[mni].ed].size();i++){//add edges
				if(visv[vlg[es[mni].ed][i].ed]==0) es.push_back({vlg[es[mni].ed][i].ed,vlg[es[mni].ed][i].w,vlg[es[mni].ed][i].fl,vlg[es[mni].ed][i].st});
			}
			vnum[es[mni].ed]++;
//			cout<<"B "<<es[mni].ed<<endl;
		}
		else{//vlg->city
			visc[es[mni].ed]=1;
			ans+=es[mni].w;
			for(int i=0;i<cty[es[mni].ed].size();i++){//add edges
				if(visc[cty[es[mni].ed][i].ed]==0) es.push_back({cty[es[mni].ed][i].ed,cty[es[mni].ed][i].w,cty[es[mni].ed][i].fl,cty[es[mni].ed][i].st});
			}
			vnum[es[mni].st]++;
//			cout<<"C "<<es[mni].st<<endl;
		}
//		cout<<ans<<endl;
	}
//	cout<<endl<<endl;
//	for(int i=0;i<es.size();i++){
//		cout<<es[i].fl<<"  "<<es[i].ed<<endl;
//	}
//	cout<<ans<<endl<<endl;
	for(int i=0;i<es.size();i++){
		if(es[i].fl==1 and visv[es[i].ed]==1 and vnum[es[i].ed]==1){
			//cout<<"-: "<<es[i].ed<<" "<<vw[es[i].ed]<<" "<<es[i].w<<" "<<vnum[es[i].ed]<<endl;
			ans-=vw[es[i].ed];
			ans-=es[i].w;
			vnum[es[i].ed]=0;
			visv[es[i].ed]=0;
		}
	}
	printf("%lld",ans);
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

4 3 2
1 2 2
1 3 5
2 4 3
2 1 2 7 2
4 2 3 1 2
*/
