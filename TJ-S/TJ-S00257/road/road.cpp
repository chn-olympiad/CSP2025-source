#include<bits/stdc++.h>

using namespace std;
struct l{
	int u,v,w;
}a[100005];
struct s{
	int w,s[1000005];
}s[15];
struct c{
	int u,v;
};
vector<c> c;
bool v[1000005],v2[15],v3[1000005];
int ans=2000000000,n,m,k;

bool check(){
	for(int i=0;i<c.size();i++){
		for(int j=0;j<c.size();j++){
			if(j==i){
				continue;
			}else if(c[j].u==c[i].v){
				c[j].u==c[i].u;
			}else if(c[j].v==c[i].u){
				c[j].v=c[j].u;
				c[j].u=c[i].u;
			}else if(c[j].v==c[i].v){
				c[j].v=c[j].u;
				c[j].u=c[i].u;
			}
		}
	}
	bool f[1000005];
	memset(f,0,sizeof(f));
	for(int i=0;i<c.size();i++){
		f[c[i].u]=1;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			return 0;
		}
	}
	return 1;
}
void dfs(int p,int d){
	if(c.size()>=n-1 && check()){
		ans=min(ans,p);
		return ;
	}
	for(int i=1;i<=k;i++){
		if(v2[i]){
			continue;
		}
		v2[i]=1;
		for(int j=1;j<=n;j++){
			if(v3[j]==0){
				v3[j]=1;
				c.push_back({0,j});
				dfs(p+s[i].w+s[i].s[j],d+1);
				v3[j]=0;
				c.pop_back();
			}
		}
		v2[i]=0;
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin >> s[i].w;
		for(int j=1;j<=n;j++){
			cin >> s[i].s[j];
		}
	}
	dfs(0,1);
	cout << ans;
	return 0;
}
