#include<bits/stdc++.h>
using namespace std;
class cmp{
	public:
		operator()(pair<long long,long long>a,pair<long long,long long>b){
			return a.second>b.second;
		}
};
struct Edge{
	long long to,val;
};
vector<vector<Edge> >mp(10004);
long long mind[10004];
bool vis[10004];
long long Prim(int n,int s){
	for(int i=0;i<10004;i++){
		mind[i]=LONG_LONG_MAX;
		vis[i]=0;
	}
	queue<pair<long long,long long> >q;
	mind[s]=0;
	q.push({s,0});
	vis[s]=1;
	long long ans=0;
	while(!q.empty()){
		pair<long long,long long>curr=q.front();
		q.pop();
		long long minn=LONG_LONG_MAX,vv=-1;
		for(int i=0;i<mp[curr.first].size();i++){
			Edge v=mp[curr.first][i]; 
			if(vis[v.to]==0)mind[v.to]=min(mind[v.to],v.val);
			if(v.val<minn&&vis[v.to]==0){
				minn=v.val;
				vv=v.to;
			} 
		}
		if(vv!=-1){
			vis[vv]=1;
			q.push({vv,mind[vv]});
		}
		
	}
	for(int i=1;i<=n;i++){
		ans+=mind[i];
		
	}
	return ans;
}
struct C{
	long long val;
	vector<Edge>E;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	long long ans=Prim(n,1);
	C new_c[11];
	for(int i=0;i<k;i++){
		scanf("%lld",&new_c[i].val);
		for(int j=0;j<n;j++){
			long long val;
			scanf("%lld",&val);
			new_c[i].E.push_back({j+1,val});
		} 
	}
	long long new_ans;
	long long better[15]{};
	for(int i=0;i<k;i++){
		new_ans=ans+new_c[i].val;
		long long min_val=LONG_LONG_MAX;
		int mini=-1;
		for(long long j=0;j<new_c[i].E.size();j++){
			Edge v=new_c[i].E[j];
			if(v.val<min_val){
				mini=j;
			} 
			min_val=min(min_val,v.val);
		}
		for(long long j=0;j<new_c[i].E.size();j++){
			Edge v=new_c[i].E[j];
			if(mind[v.to]>v.val&&j!=mini){
				new_ans-=mind[v.to]-v.val;
				mind[v.to]=v.val;
			}
			
		}
		new_ans+=min_val;
		better[i]=ans-new_ans;
		
	} 
	long long x=0;
	for(int i=0;i<k;i++){
		if(better[i]>0){
			x+=better[i];
		}
	}
	cout<<ans-x;
	return 0;
} 