#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug 0
struct tow{
	
	int to,w;
};
struct leg{
	int u,v,w;
};
bool cmp(leg a,leg b){
	return a.w<b.w;
}
int c[11][12232];
vector<tow>g[1030303];
leg legs[2030303];
leg legt[2030303];
int lcnt=1;
int n,m,k;
bitset<11>fix;
void work();
void dfs(int i){
#if debug==1
	cout<<"dfs in    "<<i<<endl;
#endif
	if(i==k+1){
		work();
		return;
	}
	fix[i]=1;
	dfs(i+1);
	fix[i]=0;
	dfs(i+1);
	
}
ll ans=LONG_LONG_MAX;
struct ababab{
	int fa[12020];
	int num;

	void clear(){
		for(int i=1;i<=num;i++)
			fa[i]=i;
	}
	int get_fa(int a){
		return (a==fa[a])?(a):(fa[a]=get_fa(fa[a]));
	}
	void leg(int a,int b){//连接a,b
		fa[a]=get_fa(a);
		fa[b]=get_fa(b);
		if(fa[a]==fa[b])return;
		fa[fa[b]]=fa[a];
	}
	void out(){
		cout<<">>>bcj:\n";
		for(int i=1;i<=num;i++){
			cout<<i<<": "<<get_fa(i)<<" || ";
		}
		cout<<"------\n\n";
	}
	
} bcj;
void work(){
#if debug==1
	cout<<"===============================================\n\nnow :\n";
	cout<<fix<<endl;
#endif
	bcj.clear();
	ll this_ans=0;
	memset(legt,0,sizeof legt);
	for(int i=1;i<=m;i++){
		legt[i]=legs[i];
	}
	int now=m+1;
	int nk=0;
	for(int i=1;i<=k;i++){
		if(fix[i]==0)continue;
		this_ans+=c[i][0];
		nk++;
		for(int j=1;j<=n;j++){
			legt[now]={n+i,j,c[i][j]};now++;
		}
	}
	sort(legt+1,legt+now,cmp);
#if debug==1
	cout<<"\n+++++++++\n";
	for(int i=0;i<=now;i++){
		cout<<legt[i].u<<"-->"<<legt[i].v<<" : "<<legt[i].w<<endl;
	}
	cout<<"\n+++++++++\n";
	
	

#endif
	
	//最小生成树！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	int max_point=nk+n;
	bcj.clear();
	int legses=0;
#if debug==1
	bcj.out();
	cout<<"max_p:: -_> "<<max_point<<endl;
	cout<<"now"<<now<<endl;
#endif
	for(int i=1;i<=now-1;i++){
		#if debug==1
		cout<<"i: "<<i<<endl;
		
		cout<<"u: "<<legt[i].u<<"  v: "<<legt[i].u<<endl;
		cout<<"u fa: "<<bcj.get_fa(legt[i].u)<<"  v fa: "<<bcj.get_fa(legt[i].v)<<endl;
		#endif		
		if(bcj.get_fa(legt[i].u)!=bcj.get_fa(legt[i].v)){
			bcj.leg(legt[i].u,legt[i].v);			
			#if debug==1
			cout<<"leg "<<legt[i].u<<"  "<<legt[i].v<<endl;
			#endif
			this_ans+=legt[i].w;
			legses++;
		}
		if(legses==max_point-1)break;
	}
	
#if debug==1
	bcj.out();
	cout<<"this_ans "<<this_ans<<endl;
	cout<<"===============================================\n\n";
	
#endif
	ans=min(ans,this_ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin>>n>>m>>k;
	bcj.num=n+k+3;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		legs[lcnt]={u,v,w};lcnt++;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	ll cnt_V__V=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			cnt_V__V+=c[i][j];
		}
	}
//	cout<<cnt_V__V;
	if(cnt_V__V==0){
		ans=0;
		int max_point=n;
		bcj.clear();
		int legses=0;
		for(int i=1;i<=m;i++){	
			if(bcj.get_fa(legs[i].u)!=bcj.get_fa(legs[i].v)){
				bcj.leg(legs[i].u,legs[i].v);			
				ans+=legs[i].w;
				legses++;
			}
			if(legses==max_point-1)break;
		}
		cout<<ans;
		return 0;
	}
//	cout<<1145<<endl;
	dfs(1);
	cout<<ans;
	return 0;
}