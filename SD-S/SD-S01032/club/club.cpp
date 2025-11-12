#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include <ext/pb_ds/exception.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/list_update_policy.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
#define int long long
using namespace std;//wo bu shi p__h__y
namespace club_cute_fzj_kuai_rua_rua{
	struct node{//三个分别是多少 
		int a[3];
		node(){}
		node(int q,int w,int e){
			a[0]=q,a[1]=w,a[2]=e;
		}
		int getmax(){
			return max(a[0],max(a[1],a[2]));
		}
		int getmin(){
			return min(a[0],min(a[1],a[2]));
		}
		int getmid(){
			return a[0]+a[1]+a[2]-getmax()-getmin(); 
		}
	};
	int n,ans;
	bool cmp(node a,node b){
		int valA=a.getmax()-a.getmid(),valB=b.getmax()-b.getmid();
		return valA<valB;
	}
	vector<node>a[3];
	void init(){
		ans=0;
		a[0].clear();
		a[1].clear();
		a[2].clear();
		cin>>n;
		for(int i=1;i<=n;++i){
			int A,B,C;
			cin>>A>>B>>C; 
			node tmp(A,B,C);
			ans+=tmp.getmax();
			if(tmp.getmax()==A){
				a[0].push_back(tmp); 
			}else if(tmp.getmax()==B){
				a[1].push_back(tmp);
			}else{
				a[2].push_back(tmp);
			}
		}
	}
	void mian(){
		init();
		vector<node>&b=a[0];
		if(b.size()<a[1].size()){
			b=a[1];
		}
		if(b.size()<a[2].size()){
			b=a[2]; 
		}
		sort(b.begin(),b.end(),cmp);
		int Q=b.size();
		for(int i=0;i!=Q;++i){
			if(Q-i<=n/2){
				break;
			}
			ans-=b[i].getmax()-b[i].getmid();
		}
		cout<<ans<<'\n'; 
	} 
};
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		club_cute_fzj_kuai_rua_rua::mian();
	}
	return 0;
}
//可以认为事梁桥匹配同款贪心？ 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
