#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include <ext/pb_ds/exception.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/list_update_policy.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
#define int long long
using namespace std;
namespace road___fei_zhou_ji_zhen_shi_tai_hao_rua_le{//wo qi shi shi ke ai da feng feng ! !
	int n,m,k;
	struct node{
		int u,v,w,i;
		node(){}
		node(int a,int b,int c){u=a,v=b,w=c;}
	};
	int a[11][10011],mx=1e18+1;
	vector<node>G,mst,dian[11];
	int ans;
	inline bool cmp(node a,node b){
		return a.w<b.w;
	}
	int fa[11111],h[11111];
	inline void init(){
		for(int i=1;i<=n+k;++i){
			fa[i]=i,h[i]=0;
		}
	}
	inline int find(int x){
		return(x==fa[x]?x:fa[x]=find(fa[x]));
	}
	inline int merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y){
			return 0;
		}
		if(h[x]>h[y]){
			swap(x,y);
		} 
		fa[y]=x;
		if(h[x]==h[y])h[x]++;
		return 1;
	}
	void hebing(vector<node>a,vector<node>b,vector<node>&ans){
		ans.clear();
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		while(a.size()&&b.size()){
			if(a.back().w>b.back().w){
				ans.push_back(b.back());
				b.pop_back();
			}else{
				ans.push_back(a.back());
				a.pop_back();
			}
		}
		if(b.size()){
			swap(a,b);	
		}
		if(a.size()){
			for(auto x:a){
				ans.push_back(x); 
			}
		}
	}
	inline int kelusikaer(int nn,vector<node>&G){//wo de ying yu hen cha !!!!
		int cnt=nn-1;
		int ans=0;
		init();
		for(int i=0;i<G.size();++i){
			int isok=merge(G[i].u,G[i].v);
			if(isok){
				cnt--;
				ans+=G[i].w;
				if(nn==n)mst.push_back(G[i]),mx=max(mx,G[i].w);
			}
			if(!cnt){
				break;
			}
		}
		return ans;
	}
	inline void dfs(int i,int cnt,int tmp){
		if(tmp>=ans)return; 
		if(i==k+1){
			if(cnt!=n)ans=min(kelusikaer(cnt,mst)+tmp,ans);
			return;
		}
		dfs(i+1,cnt,tmp);
		cnt++;
		vector<node>tmpQ=mst;
		tmp+=a[i][0];
		hebing(tmpQ,dian[i],mst);
		dfs(i+1,cnt,tmp);
		mst=tmpQ;
	}
	void mian(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin>>u>>v>>w;
			G.emplace_back(u,v,w);
		}
		for(int j=1;j<=k;++j)for(int i=0;i<=n;++i){
			cin>>a[j][i];
		}
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				dian[i].emplace_back(i+n,j,a[i][j]);
			}
			sort(dian[i].begin(),dian[i].end(),cmp);
		}
		sort(G.begin(),G.end(),cmp);
		ans=kelusikaer(n,G);
		sort(mst.begin(),mst.end(),cmp);
		dfs(1,n,0); 
		cout<<ans;
	}
};
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	road___fei_zhou_ji_zhen_shi_tai_hao_rua_le::mian();
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

*/

