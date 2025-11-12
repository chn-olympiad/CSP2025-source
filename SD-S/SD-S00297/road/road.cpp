#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+105;
const int N=1e4+105;
int n,m,k;
struct nd{
	int x,y,z;
}a[M];
vector<nd> v;
struct node{
	int cnt;
	int val[N];
}c[15];
struct edge{
	int y,z;
};
vector<edge> t[N];
int ans;
int f[N];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int pre_check[15],check_cnt,root;
void dfs(int x,int fa,int maxx){
	for(int i=1;i<=k;i++){
		if(c[i].val[root]+c[i].val[x]<maxx){
			if(pre_check[i]==0) check_cnt++;
			pre_check[i]++;
		}
	}
	for(int i=0;i<t[x].size();i++){
		if(t[x][i].y==fa) continue;
		dfs(t[x][i].y,x,max(maxx,t[x][i].z));
	}
}int sum=0;
vector<nd> vec;
bool cmp(nd x,nd y){
	return x.z<y.z;
}
signed main(){
//	freopen("road4.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		int val=a[i].z;
		if(fx==fy) continue;
		sum+=val;
		f[fx]=fy;
		t[a[i].x].push_back({a[i].y,a[i].z});
		t[a[i].y].push_back({a[i].x,a[i].z});
		v.push_back({a[i].x,a[i].y,a[i].z});
	}
	ans=sum;sum=0;
	for(int i=1;i<=k;i++){
		cin>>c[i].cnt;
		for(int j=1;j<=n;j++) cin>>c[i].val[j];
	}
	if(n>1e3&&k>5)for(int i=1;i<=n;i++){
		root=i;
		dfs(i,i,0);
		if(check_cnt==k) break;
	}
	if(n>1e3&&k>5)for(int i=1;i<=k;i++){
		if(c[i].cnt>=ans) pre_check[i]=0;
	}
	for(int rt=1;rt<(1ll<<k);rt++){
		sum=0;int flagg=0;
		vec.clear();
		int ncnt=n;
		for(int i=1;i<=k;i++){
			if(rt&(1ll<<(i-1))){
				if(n>1e3&&k>5)if(pre_check[i]==0){
					flagg=1;
					break;
				}
				sum+=c[i].cnt;
				ncnt++;
				for(int j=1;j<=n;j++) vec.push_back({j,i+n,c[i].val[j]});
			}
		}
		if(flagg||sum>=ans) continue;
		for(int i=0;i<v.size();i++) {
			vec.push_back(v[i]);
		}
		for(int i=1;i<=n+k;i++) {
			f[i]=i;
		}
		sort(vec.begin(),vec.end(),cmp);
		
		for(int i=0;i<vec.size();i++){
			int fx=find(vec[i].x),fy=find(vec[i].y);
			int val=vec[i].z;
			if(fx==fy) continue;
			sum+=val;f[fx]=fy;
			if(sum>=ans) break;
			ncnt--;
			if(ncnt==1) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
