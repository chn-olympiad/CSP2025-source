#include<bits/stdc++.h>
using namespace std;
int mp[10015][10015],fx[10],v[10],way[10005];
int n,m,k,an=0,ans=0x3f3f3f,sum;

void dfs(int st);
void nw(int x,int t);

int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	memset(mp,10010,0x3f3f3f);
	for(int i=1;i<=m;i++){
		cin>>u,v,w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>fx[i];
		for(int j=0;j<=n;j++){
			cin>>mp[i+10000][j];
			mp[j][i+10000]=mp[i+10000][j];
		}
	}
	for(int i=1;i<=n;i++)nw(1,i);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void nw(int x,int t){
	if(x==11){
		dfs(t);
		return;
	}
	v[x]=1;
	an+=fx[x];
	sum=an;
	nw(x+1,t);
	v[x]=0;
	an-=fx[x];
	sum=an;
	nw(x+1,t);
}

void dfs(int st){
	memset(way,10010,0x3f3f3f);
	way[st]=0;
	int o;
	for(int i=0;i<n+10;i++){
		if(i>10000&&!v[i-10000])continue;
		o=(st+i)%n;
		if(o==0)o=n;
		for(int j=1;j<=n+10;j++){
			if(j>10000&&!v[j-10000])continue;
			if(mp[o][j]<0x3f3f3f){
				way[j]=min(way[j],way[o]+mp[o][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)sum+=way[i];
	ans=min(sum,ans);
	return;
}

