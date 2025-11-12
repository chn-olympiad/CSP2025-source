#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,c[105],fa[100005],cnt,ans;
pair<long long,pair<int,int> > B[15][100005],t[1000005];
pair<long long,int> ht[15][10005];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void dfs(int x,long long z,int h){
	if(x==k){
		long long an=z+c[x];
		for(int i=1;i<=n+h;i++){
			fa[i]=i;
		}
		int j=1,fl=1;cnt=0;
		B[h][n+h-2].first=1e18;
		ht[x][n+1].first=1e18;
		for(int i=1;cnt<n+h-1;i++){
			if(B[h][fl].first<ht[x][j].first){
			if(find(B[h][fl].second.first)!=find(B[h][fl].second.second)){
				fa[find(B[h][fl].second.first)]=find(B[h][fl].second.second);
				an+=B[h][fl].first;cnt++;
			}
			fl++;
			}
			else{
			if(find(h+n)!=find(ht[x][j].second)){
				fa[find(h+n)]=find(ht[x][j].second);
				an+=ht[x][j].first;cnt++;
			}
			j++;
			}
		}
		ans=min(an,ans);
		return ;
	}
	dfs(x+1,z,h);
	long long an=z+c[x];
	for(int i=1;i<=n+h;i++){
		fa[i]=i;
	}
	cnt=0; 
	int j=1,fl=1;
	B[h][n+h-2].first=1e18;
	ht[x][n+1].first=1e18;
	for(int i=1;cnt<n+h-1;i++){
		if(B[h][fl].first<ht[x][j].first){
		if(find(B[h][fl].second.first)!=find(B[h][fl].second.second)){
			fa[find(B[h][fl].second.first)]=find(B[h][fl].second.second);
			an+=B[h][fl].first;
			cnt++;
			B[h+1][cnt]=B[h][i];
		}
		fl++;
		}
		else{
		if(find(h+n)!=find(ht[x][j].second)){
			fa[find(h+n)]=find(ht[x][j].second);
			an+=ht[x][j].first;
			cnt++;
			B[h+1][cnt]=(pair<long long,pair<int,int> >
			{ht[x][j].first,pair<int,int>{h+n,ht[x][j].second}});
		}
		j++;
		}
	}
	ans=min(an,ans);
	dfs(x+1,z+c[x],h+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>t[i].second.first>>t[i].second.second>>t[i].first;
	}
	sort(t+1,t+1+m);
	for(int i=1;i<=m;i++){
		if(find(t[i].second.first)!=find(t[i].second.second)){
			fa[find(t[i].second.first)]=find(t[i].second.second);
			cnt++;
			ans+=t[i].first;
			B[1][cnt]=t[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ht[i][j].first;
			ht[i][j].second=j;
		}
		sort(ht[i]+1,ht[i]+1+n);
	}
	if(k!=0) dfs(1,0,1);
	cout<<ans;
	return 0;
}