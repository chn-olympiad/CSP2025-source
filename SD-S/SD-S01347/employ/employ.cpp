#include<bits/stdc++.h>
#define endl "\n"
#define int long long 
#define PII pair<int,int>
using namespace std;
const int maxN=1e6+10,INF=INT_MAX,mod=998244353;
vector<int> v;
//priority_queue<PII,vector<PII>,greater<PII> >pq;
int m,k,n,a[maxN],dis[maxN],ans,f[maxN],vis[maxN];
string s;
int ck(){
	int ps=0,res=0,e=1;
	for(auto i:v){
		if(s[e]=='1'&&ps<a[i]) res++;
		else ps++;
		e++;
	}
	//cout<<res<<endl;
	return res;
}
void dfs(int x){
	if(x>n){
		ans+=(ck()>=m);
		//if(ck()>=m){
//		cout<<ck()<<endl;
//		for(auto e:v) cout<<e<<' ';
//		cout<<endl;
		//}
		return;
	}
	//cout<<"?"<<endl;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(i);
		dfs(x+1);
		vis[i]=0;
		v.pop_back();
	}
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans%mod;
	return 0;
}//Ren5Jie4Di4Ling5%
