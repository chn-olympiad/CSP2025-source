#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=2e6+5;
int n,m,k;
int c[15],a[15][10005];
struct node{
	int x,y,z;
	bool operator < (const node &p)const{
		return z<p.z;
	}
};
vector<node> v;
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
vector<node> pre;
bool vis[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z; 
		v.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	sort(v.begin(),v.end());
	int ans=0,cnt=0;
	for(int i=0;i<v.size();i++){
		int rx=find(v[i].x),ry=find(v[i].y);
		if(rx==ry) continue;
		pre.push_back(v[i]);
		fa[rx]=ry;
		ans+=v[i].z;
		cnt++;
		if(cnt==n-1) break;
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=0;i<pre.size();i++){
		int x=pre[i].x,y=pre[i].y,z=pre[i].z;
		fa[x]=x,fa[y]=y;
		int minn=1e18,pos=0;
		for(int j=1;j<=n;j++){
			if(find(j)==x) continue;
 			for(int t=1;t<=k;t++){
				if(a[t][j]+a[t][x]+(vis[t]?0:c[t])<minn){
					minn=a[t][j]+a[t][x]+(vis[t]?0:c[t]);
					pos=t;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(find(j)==y) continue;
			for(int t=1;t<=k;t++){
				if(a[t][j]+a[t][y]+(vis[t]?0:c[t])<minn){
					minn=a[t][j]+a[t][y]+(vis[t]?0:c[t]);
					pos=t;
				}
			}
		}
		if(minn>z) continue;
		fa[x]=y;
		vis[pos]=1;
		ans=ans-z+minn;
	}
	cout<<ans;
	return 0;
}
/*
求这个图的最小生成树
问题在于怎么在最小生成树中加入点值的影响
题目保证了原有的图是联通的，应该是比较关键的性质
先求出原图的最小生成树，再枚举断掉一条树边换成其他点看是否更优 
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
15
*/