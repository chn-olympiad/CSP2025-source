#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge{
	int x,y,z;
}e[M];
int n,m,k;
int fa[N];
bool cmp(edge a,edge b){
	return a.z<b.z;
}
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int getfa(int x){
	if(fa[x]==x)return x;
	else return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	int fx=getfa(x),fy=getfa(y);
	if(fx==fy)return;
	else fa[fx]=fy;
}
int kru(){
	init(n);
	int ans=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(getfa(e[i].x)==getfa(e[i].y))continue;
		else {
			ans+=e[i].z;
			merge(e[i].x,e[i].y);
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	int gt=0;
	for(int i=1;i<=k;i++)cin>>gt;
	int res=kru();
	cout<<res;
	return 0;
}
//真是讽刺啊……
//赛前准备拿240，现在看来，140都是奢望啊………
//去他的一等吧，现在我只想进一次NOIP……
//RP++…… 
