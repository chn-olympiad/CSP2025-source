#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5,K=25;
int n,m,k,c[K],a[K][N],use[K];
struct node{
	int x,y,z;
	bool operator<(const node &b)const{
		return z<b.z;
	}
}q[M];
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool check(){
	for(int i=1;i<=k;i++){
		int flg=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]!=0){flg=1;break;}
		}
		if(flg==0)return true;
	}
	return false;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q[i].x=u,q[i].y=v,q[i].z=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0){
		sort(q+1,q+m+1);
		int sum=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=q[i].x,y=q[i].y,z=q[i].z;
			x=find(x),y=find(y);
			if(x==y)continue;
			fa[x]=y;sum+=z;
		}
		cout<<sum<<"\n";
		return 0;
	}
	if(check()){
		cout<<0<<"\n";
		return 0;
	}
	vector<pair<pair<int,int>,int> > v;
	sort(q+1,q+m+1);
	int sum=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=q[i].x,y=q[i].y,z=q[i].z;
		x=find(x),y=find(y);
		if(x==y)continue;
		fa[x]=y;sum+=z;
		v.push_back({{q[i].x,q[i].y},q[i].z});
	}
	for(auto e:v){
		int x=e.first.first,y=e.first.second,z=e.second;
		cout<<x<<" "<<y<<" "<<z<<"\n";
		for(int i=1;i<=k;i++){
			if(a[i][x]+a[i][y]+(use[i]==0?c[i]:0)<=z){
				sum-=(z-(a[i][x]+a[i][y]+(use[i]==0?c[i]:0)));
				if(use[i]==0)use[i]=1;
			}
		}
	}
	cout<<sum<<"\n";
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

13
*/
