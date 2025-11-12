#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,i,x,y,z,ans=2e9,l,q[100010],f[20],c[20][10010],mi=2e18,qwq;
struct node{
	int x,y,z;
	bool operator <(node a)const{
		return a.z < z;
	}
}a[1000010];
priority_queue<node> b;
struct no{
	int x,y,z;
}rp[100010];
vector <no> p[100010];
int find(int x){
	if(x==q[x])return x;
	return q[x]=find(q[x]);
}
int sp(){
	int ans=0;
	for(int i=1;i<=qwq;i++)b.push(node{rp[i].x,rp[i].y,rp[i].z});
	for(int i=1;i<=k;i++)
		if(f[i]==1)
			for(int j=1;j<=n;j++)
				if(c[i][j]<rp[qwq].z)b.push(node{i+n,j,c[i][j]});
	for(int i=1;i<=n+k;i++)q[i]=i;
	while(!b.empty()){
		int fx,fy;
		fx=find(b.top().x);fy=find(b.top().y);
		if(fx!=fy){
			q[fx]=fy;
			if(fx>n)p[fx].push_back(no{fy,b.top().z,0});
			ans+=b.top().z;
		}b.pop();
	}
	for(int i=1;i<=k;i++)
		if(p[i].size()==1)
			ans-=p[i][0].y;
	return ans;
}
void dfs(int t,int sum){
	if(sum>=mi)return ;
	if(t>k){
		mi=min(mi,sp()+sum);
		return ;
	}
	f[t]=1;dfs(t+1,sum+c[t][0]);
	f[t]=0;dfs(t+1,sum);
}
bool cmp(node q,node h){
	return q.z<h.z;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)q[i]=i;
	for(int i=1;i<=m;i++){
		int fx,fy;
		fx=find(a[i].x);fy=find(a[i].y);
		if(fx!=fy){
			q[fx]=fy;
			if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
			rp[++qwq].x=a[i].x;rp[qwq].y=a[i].y;rp[qwq].z=a[i].z;
//			w[++qwq].l=a[i].x;w[qwq].r=a[i].y;w[qwq].val=a[i].z;
			ans+=a[i].z;
		}
	}
//	cout<<qwq<<'\n';
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>c[i][j];
	if(k==0)return cout<<ans,0;
	dfs(1,0);
	cout<<mi;
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
AC i hope
*/
