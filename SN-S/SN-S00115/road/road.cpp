// cfl 422 

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define fir first
#define sec second
#define mkp make_pair
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define strep(i,s) for(int i=0;i<sz(s);i++)
#define streps(i,s) for(auto i:s)
#define fastread ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define Min(x,y) x=min((x),(y))
#define Max(x,y) x=max((x),(y))
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define release 1   //交卷时一定要改成1，测sample时改为2，控制台交互时改为0
string filename="road";   //改为当前文件名 ! ! ! ! !
string testcase;

/*
注意fc时如果找不到文件，检查一下filename的值 
*/
#define is_digit(x) (((x)>='0')&&((x)<='9'))
inline ll rd(){
	ll ret=0;
	int flag=1;
	char c=getchar();
	while(!is_digit(c)&&c!='-') c=getchar();
	if(c=='-'){
		flag=-1;
		c=getchar();
	}
	while(is_digit(c)){
		ret=ret*10+(c-'0');
		c=getchar();
	}
//	cout<<ret*flag<<endl;
	return ret*flag;
}
#define int long long 
const int maxn=1e4+202,maxm=1e6+202,maxk=12;
int n,m,k;
struct EDGE{
	int u,v,w;
}edge[maxm];
int val[maxk][maxn],cost[maxk];
bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}
int f[maxn];
int find(int i){
	return f[i]==i?i:f[i]=find(f[i]);
}
ll ans;
vector<EDGE> newe;
vector<EDGE> ke[maxk];
void merge(vector<EDGE> & v1,const vector<EDGE> & v2){
	vector<EDGE> ret;
	int j=0,o=0;
	while(true){
		if(j==sz(v1)&&o==sz(v2)){
			break;
		}
		if(j==sz(v1)){
			ret.pb(v2[o++]);
		}
		else if(o==sz(v2)){
			ret.pb(v1[j++]);
		}
		else {
			if(v1[j].w<v2[o].w){
				ret.pb(v1[j++]);
			}
			else{
				ret.pb(v2[o++]);
			}
		}
	}
	v1=ret;
}
void del(vector<EDGE> & v,int step){
	vector<EDGE> ret;
	strep(i,v)
		if(v[i].u!=step+n)
			ret.pb(v[i]);
	v=ret;
}
bool flag[maxk];
//#define DEBUG 1
void checkans(int ge,ll startsum){
	ll sum=startsum;
	for(int i=1;i<=n+k;i++) f[i]=i;
	int tot=0;
	strep(i,newe){
		if(tot>=ge-1) break;
		int u=newe[i].u,v=newe[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fu]=fv;
			tot++;
//			newe.pb(edge[i]);
			sum+=newe[i].w;
		}
	}
	#ifdef DEBUG
	cout<<startsum<<" "<<ge<<" "<<sum<<endl;
	#endif 
	Min(ans,sum);
}
void dfs(int step,int ge,ll startsum){
	if(step==k+1){
		checkans(ge,startsum);
		return ;
	}
	dfs(step+1,ge,startsum);
	merge(newe,ke[step]);
	flag[step]=true;
	dfs(step+1,ge+1,startsum+cost[step]);
	del(newe,step);
	flag[step]=false;
}
void solve(){
	#if release == 1 || release == 2
	fastread;
	#endif
//	cin>>n>>m>>k;
	n=rd();
	m=rd();
	k=rd();
//	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=m;i++){
		edge[i].u=rd();
		edge[i].v=rd();
		edge[i].w=rd();
	}
	for(int i=1;i<=k;i++){
//		cin>>cost[i];
		cost[i]=rd();
		for(int j=1;j<=n;j++) {
//			cin>>val[i][j];
			val[i][j]=rd();
		}//如果选城市化某个村镇，那么该村镇必定连向val最小的那个城市 
		for(int j=1;j<=n;j++) ke[i].pb(EDGE{n+i,j,val[i][j]});
		sort(all(ke[i]),cmp);
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	int tot=0;
	for(int i=1;i<=m;i++){
		if(tot>=n-1) break;
		int u=edge[i].u,v=edge[i].v;
		int fu=find(u),fv=find(v);
//		cout<<u<<" "<<v<<" "<<fu<<" "<<fv<<endl;
		if(fu!=fv){
			f[fu]=fv;
			tot++;
			newe.pb(edge[i]);
			ans+=edge[i].w;
//			cout<<edge[i].w<<endl;
		}
	}
	#ifdef DEBUG 
	cout<<ans<<endl;
	#endif 
	dfs(1,n,0);
	cout<<ans<<endl;
}
signed main(){
	#if release == 1
	freopen((filename+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#elif release ==2
	cin>>testcase;
	freopen((filename+testcase+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#endif
	solve();
	return 0;
}
















// florr
