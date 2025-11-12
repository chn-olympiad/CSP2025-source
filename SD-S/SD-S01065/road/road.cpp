#include<bits/stdc++.h>
using namespace std;
pair<long long,pair<int,int> > p[1000010];
pair<long long,pair<int,int> > pp[1000010];
int c[20],a[20][10010];
int fa[10010];
int f(int x){
	return fa[x]==x?x:fa[x]=f(fa[x]);
}
bool flag[20];
int n,m,k;
long long ans=1e18;
long long s;
void kru(int mm,long long wwh){
	sort(p+1,p+mm+1);
	for(int i=1;i<=n+k;i++)fa[i]=i; 
	long long ret=wwh;
	for(int i=1;i<=mm;i++){
		int x=p[i].second.first,y=p[i].second.second;
		int fx=f(x),fy=f(y);
		if(fx!=fy){
			fa[fx]=fy;
			ret+=p[i].first;
		}
		if(ret>=ans)return;
	}
	ans=min(ans,ret);
	return;
}
void dfs(int x){
	if(s>=ans)return;
	if(x==k+1){
		//long long wwh=s;
		long long tot=m;
		for(int i=1;i<=m;i++)p[i]=pp[i];
		for(int i=1;i<=k;i++){
			if(flag[i]){
				for(int j=1;j<=n;j++){
					p[++tot]={a[i][j],{n+i,j}};
				}
			}
		}
		kru(tot,s);
		//ans=min(ans,wwh);
		return;
	}
	dfs(x+1);
	flag[x]=1;
	//cout<< "aa";
	s+=c[x];
	dfs(x+1);
	flag[x]=0;
	s-=c[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> pp[i].second.first >> pp[i].second.second >> pp[i].first;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	sort(pp+1,pp+m+1);
	for(int i=1;i<=n;i++)fa[i]=i; 
	int eee=0;
	for(int i=1;i<=m;i++){
		int x=pp[i].second.first,y=pp[i].second.second;
		int fx=f(x),fy=f(y);
		if(fx!=fy){
			fa[fx]=fy;
			p[++eee]=pp[i];
		}
	}
	m=eee;
	for(int i=1;i<=m;i++)pp[i]=p[i];
	if(k==0){
		kru(m,0);
		cout << ans;
		return 0; 
	}
	dfs(1);
	cout << ans;
	return 0;
}
