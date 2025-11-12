#include<bits/stdc++.h>
using namespace std;
struct DSU{
	vector<int> parent;
	DSU(int n):parent(n+1){
		for(int i=0;i<n+1;i++)
			parent[i]=i;
	}
	
	int find(int x){
		if(parent[x]!=x) 
			return parent[x]=find(parent[x]);
		return parent[x];
	}
	
	void merge(int x,int y){
		int rx=find(x),ry=find(y);
		if(rx!=ry){
			int u=min(rx,ry),v=max(rx,ry);
			parent[v]=u;
		}
	}
	
	bool is_merge(int x,int y){
		return find(x)==find(y);
	}
};
typedef long long ll;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int c[N];
int per[N];
bool vis[N];
int presum[N];
int res=0;
void dfs(int step){
	if(step>n){
//		for(int i=1;i<=n;i++)
//			cout<<per[i]<<" ";
//		cout<<"\n";
		int r=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0')
				r++;
			else if(presum[i-1]>=c[per[i]])
				r++;
		}
//		cout<<n-r<<"\n";
		if((n-r)>=m)
			res++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			per[step]=i;
			vis[i]=true;
			dfs(step+1);
			vis[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	presum[0]=(s[0]=='0');
	for(int i=1;i<n;i++){
		presum[i]=presum[i-1]+(s[i]=='0');
	}
//	for(int i=0;i<n;i++)
//		cout<<presum[i]<<" ";
//	cout<<"\n";
	dfs(1);
	cout<<res<<"\n";
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
