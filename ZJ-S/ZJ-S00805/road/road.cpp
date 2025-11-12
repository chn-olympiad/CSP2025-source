#include<bits/stdc++.h>
using namespace std;
int c[11],K,n,m,d[10001][10001],ans,sum,fa[10001];
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
struct x{
	int val,x,y;
	
	
};
bool operator<(const x&th,const x& other) {
		return th.val<other.val;
}
x init(int a,int b,int c){
		x xx;
		xx.x=a;
		xx.y=b;
		xx.val=c;
		return xx;
	}
map<pair<int,int>,int> mp;
vector<x> a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		a.push_back(init(x,y,z));
		a.push_back(init(y,x,z));
		mp[{x,y}]=a.size()-2;
        mp[{y,x}]=a.size()-1;
	}
	//cout<<K<<"\n";
	for(int i=1;i<=K;i++){
		//cout<<"n\n";
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>d[i][j];
			for(int k=1;k<j;k++){
				if(mp.find({j,k})!=mp.end()) {
					a[mp[{j,k}]].val=min(d[i][j]+d[i][k],a[mp[make_pair(k,j)]].val);
					a[mp[{k,j}]].val=min(d[i][j]+d[i][k],a[mp[make_pair(j,k)]].val);
				}
				else {
					a.push_back(init(j,k,d[i][j]+d[i][k]));
					mp[{i,j}]=a.size()-1;
				}
			}
		}
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<a.size();i++){
		int x1=a[i].x,y1=a[i].y;
		fa[x1]=find(x1),fa[y1]=find(y1);
		if(fa[x1]!=fa[y1]){
			fa[x1]=fa[y1];
			ans+=1;
			if(ans==n-1) break;
			sum+=a[i].val;
		}
	}
	cout<<sum;
}
