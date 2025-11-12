#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,M=1e6+5;
int n,m,k;
struct road{
	int x,y,w;
	bool operator <(const road &a)const{
		return w<a.w;
	}
}a[M],b[N<<1],e[15][N];
struct village{
	int x;
	road a[N];
}c[15];
int st[15];
int rd[N],rl;
int ans;
int fa[N];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main(){
//	system("fc road.out road4.ans");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=k;i++){
		cin>>c[i].x;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			c[i].a[j].x=i+n;
			c[i].a[j].y=j;
			c[i].a[j].w=w;
		}
		sort(c[i].a+1,c[i].a+n+1);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y;
		x=find(x),y=find(y);
		if(x!=y){
			rd[++rl]=i;
			fa[x]=y;
			ans+=a[i].w;
		}
	}
	for(int s=1;s<(1<<k);s++){
		int cnt=0,res=0,d=0,sum=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=1;i<=k;i++){
			if(s&(1<<i-1)){
				d++;
				res+=c[i].x;
				for(int j=1;j<=n;j++){
					e[d][j]=c[i].a[j];
					++cnt;
				}
			}
		}
		for(int i=1;i<=d;i++){
			st[i]=1;
		}
		int now=1,p=0,mx=1e14l,id=1;
		cnt+=rl;
		for(int i=1;i<=cnt+rl;i++){
			id=1;
			mx=1e14l;
			for(int j=1;j<=d;j++){
				if(st[j]<=n&&e[j][st[j]].w<mx){
					mx=e[j][st[j]].w;
					id=j;
				}
			}
			if(now<=rl&&a[rd[now]].w<mx){
				b[i]=a[rd[now++]];
			}
			else{
				b[i]=e[id][st[id]++];
			}
		}
		for(int i=1;i<=cnt;i++){
			int x=b[i].x,y=b[i].y;
			x=find(x),y=find(y);
			if(x!=y){
				fa[x]=y;
				res+=b[i].w;
				sum++;
				if(sum==n+d-1){
					break;
				}
				if(res>ans){
					break;
				}
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
