#include<iostream>
#include<cstring>
using namespace std;
long long n,m,k,st[10010],p[10010][10010],flag,ans=1e18;
struct pint{
	long long c,l[10010];
}a[10010];
void dfs(int s,long long sum){
	int u=0;
	for(int i=1;i<=n;i++){
		if(st[i]!=1){
			u=1;
		}
	}
	if(u==0) ans=min(ans,sum);
	else{
		for(int i=1;i<=n;i++){
			if(p[s][i]!=-1&&st[i]==0){
				st[i]=1;
				dfs(i,sum+p[s][i]);
				st[i]=0;
			}
		}
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(p,-1,sizeof(p)); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		p[x][y]=z;
		p[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i].c;
		if(a[i].c!=0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i].l[j];
			if(a[i].l[j]!=0) flag=1;
		}
	}
	if(k==0) flag=1;
	if(flag==0) cout<<0;
	else{
		st[1]=1;
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}

