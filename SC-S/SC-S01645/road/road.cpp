#include<bits/stdc++.h>
#define froepen freopen
/*rp+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++++++
+++++++++++++++++++++
++++++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++
++++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++++++
+++++++++++++++++++++
++++++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++
++++++++++++++++++*/
using namespace std;
const int ts=false;
struct node{
	int u;
	int v;
	int e;
};
class unionfind{
	public:
		vector<int>f;
		unionfind(int n):f(n+2){
			for(int i=1;i<=n;++i){
				f[i]=i;
			}
		}
		int getfa(int i){
			return f[i]==i?i:f[i]=f[getfa(f[i])];
		}
		bool merge(int i,int j){
			i=getfa(i);j=getfa(j);
			if(i==j)return false;
			else {
				f[i]=j;
				return true;
			}
		}
};
int main(){
	if(!ts){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		froepen("road.in","r",stdin);
		froepen("road.out","w",stdout);
	}
	int n,m,k;
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}else{
		vector<node>a;
		for(int i=0;i<m;++i){
			int u,v,e;
			cin>>u>>v>>e;
			a.push_back({u,v,e});
		}
		sort(a.begin(),a.end(),[](node a,node b){
			return a.e<b.e;
		});
		int edgcnt=0;
		long long ans=0;
		unionfind uf(n);
		for(int i=0;edgcnt<n-1;++i){
			node cur=a[i];
			if(uf.merge(cur.u,cur.v)){
				++edgcnt;
				//cout<<cur.u<<" "<<cur.v<<"  ";
				ans+=cur.e; 
			}
		}
		cout<<ans;
	}
}