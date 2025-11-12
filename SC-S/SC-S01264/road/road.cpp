#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct st{
	int dis;
	int id;
};
vector<st> e[100010];
int fa[100010];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool marge(int a,int b){
	a=find(a),b=find(b);
	if(a==b){
		return 0;
	}
	fa[b]=a;
	return 1;
}
bool cmp(st a,st b){
	return a.dis<b.dis;
}
int fy[100010];
int dj[10][100010];
long long ku(){
	long long ans=0;
	int b=0;
	for(int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end(),cmp);
		for(int j=0;j<e[i].size();j++){
			if(b==n-1){
				return ans;
			}
			if(marge(i,e[i][j].id)){
				ans+=e[i][j].dis;
				b++;
				break;
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x!=y){
			e[x].push_back({z,y});
			e[y].push_back({z,x});
		}
	}
	for(int i=1;i<=k;i++){
		cin>>fy[i];
		for(int j=1;j<=n;j++){
			cin>>dj[i][j];
		}
	}
	cout<<ku();
	return 0;
}