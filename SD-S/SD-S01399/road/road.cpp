using namespace std;
#include<bits/stdc++.h>
#define ll long long
const ll N=2e4+7;
const ll M=3e6+7;
ll fa[N];
ll roott(ll x){
	if(fa[x]==x){
		return x;
	}else{
		fa[x]=roott(x);
	}
	return fa[x];
}
ll cntt=0;
struct ed{
	ll u,v,w;
};
ed edge[M];
bool cmp(ed a,ed b){
	return a.w<b.w;
}
ll n,m,k;
ll cost[100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll uu,vv,ww;
		cin>>uu>>vv>>ww;
		edge[i].u=uu;edge[i].v=vv;edge[i].w=ww;
		
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	ll numm=0;ll anss=0;
	sort(edge+1,edge+1+n,cmp);
	if(k==0){
		
		for(int i=1;i<=m;i++){
			ll uu=edge[i].u;ll vv=edge[i].v;ll ww=edge[i].w;
			ll ra=roott(uu);ll rb=roott(vv);
//			ll ra,rb;
			if(ra!=rb){
//				cout<<"uu"<<uu<<' '<<vv<<endl;
				fa[uu]=vv;
				numm++;anss+=ww;
			}
			if(numm==(n-1)){
				break;
			}	
		}
		cout<<anss;
		
//		for(int i=1;i<=m;i++){
//			
//		} 
		
	}

	
	
	
	
	
	
	return 0;
} 
