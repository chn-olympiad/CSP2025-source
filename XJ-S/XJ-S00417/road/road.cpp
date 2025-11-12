#include<bits/stdc++.h>
using namespace std;
const int N=3e6+2,M=1e4+12;
int n,m,k,u,v,w,c[10],cnt[M],p,head[N],net[N],to[N],cd[N];
unsigned long long ans;
bool flag;
void add(int a,int b,int d){
	to[++p]=b;
	cd[p]=d;
	net[p]=head[a];
	head[a]=p;
}
void dfs(int fa,int so,int now,unsigned long long sum){
	if(now==n){
		flag = 1;
		for(int i=1;i<=n&&flag;i++)
			if(!cnt[i]) 
				flag=0;
		if(flag&&sum>ans) ans=sum;
		return;
	}
	for(int i=head[so];i;i=net[i])
		if(fa!=to[i]){
			if(i<=n&&!cnt[to[i]]){
				cnt[to[i]]=1;
				dfs(so,to[i],now+1,sum+cd[i]);
				cnt[to[i]]=0;
			}
			else{
				if(!cnt[to[i]]){
					cnt[to[i]]=1;
					dfs(so,to[i],now,sum+cd[i]+c[i-n-1]);
					cnt[to[i]]=0;
				}
				else dfs(so,to[i],now,sum+cd[i]);
			}
		}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=0;i<k;i++){
		cin >> c[k];
		for(int j=0;j<n;j++){
			cin >> w;
			add(j+1,n+k+1,w);
			add(n+k+1,j+1,w);
		}
	}
	cnt[1]=1;
	dfs(1,1,1,0);
	cout << ans;
	return 0;
} 

