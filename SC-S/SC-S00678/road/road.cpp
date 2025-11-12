#include <bits/stdc++.h>
using namespace std;

const int N=1e4+100;

int n,m,k,c[N],www[11][N];
bool ope[N];
struct node{
	int to,w;
	bool operator <(const node &a)const{
		return w>a.w;
	}
};
vector <node> e[N];

bool v[N];
long long ans=0;

priority_queue <node> q;
void krustal_init(){
	memset(v,0,sizeof(v));
	for(node x:e[1]){
		q.push({x.to,x.w});
	}
	v[1]=1;
	node h;
	int too,ww;
	while(!q.empty()){
		h=q.top();
		too=h.to,ww=h.w;
		q.pop();
		if(v[too])continue;
		//cout<<too<<endl;
		ans+=ww;
		v[too]=1;
		for(node x:e[too]){
			if(v[x.to])continue;
			q.push({x.to,x.w});
		}
	}
}
long long part_ans=0;
void krustal(){
	memset(v,0,sizeof(v));
	for(int i=1; i<=n+k; i++){
		if(!ope[i])v[i]=1;
	}
	for(node x:e[1]){
		if(v[x.to])continue;
		q.push({x.to,x.w});
	}
	v[1]=1;
	node h;
	int too,ww;
	while(!q.empty()){
		h=q.top();
		too=h.to,ww=h.w;
		q.pop();
		if(v[too])continue;
		//cout<<"-------------"<<too<<endl;
		part_ans+=ww;
		if(ans<=part_ans)return;
		v[too]=1;
		for(node x:e[too]){
			if(v[x.to])continue;
			q.push({x.to,x.w});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,ww;
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&u,&v,&ww);
		e[u].push_back({v,ww});
		e[v].push_back({u,ww});
	}
	
	bool flag=0;
	for(int i=1; i<=k; i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)flag=1;
		for(int j=1; j<=n; j++){
			scanf("%d",&www[i][j]);
			if(www[i][j]!=0){
				flag=1;
			}
//			e[n+i].push_back({j,www[i]});
//			e[j].push_back({n+i,www[i]});
		}
	}
	if(flag==0){
		cout<<0<<endl;
		return 0;
	}
	krustal_init();
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			e[n+i].push_back({j,www[i][j]});
			e[j].push_back({n+i,www[i][j]});
		}
	}
	if(m>=800000){
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++)ope[i]=1;
	int numstate=1,tmp,ind;
	for(int i=1; i<=k; i++)numstate*=2;
	for(int i=1; i<=numstate-1; i++){
		tmp=i;
		ind=1;
		while(tmp){
			if(tmp&1)ope[n+ind]=1;
			tmp>>=1;
			ind++;
		}
		//cout<<endl;
		//for(int j=1; j<=n+k; j++)cout<<ope[j]<<endl;
		part_ans=0;
		for(int j=1; j<=k; j++)if(ope[n+j])part_ans+=c[j];
		krustal();
		//cout<<part_ans<<endl;
		ans=min(ans,part_ans);
		for(int i=1; i<=k; i++)ope[n+i]=0;
	}
	cout<<ans;
	return 0;
}