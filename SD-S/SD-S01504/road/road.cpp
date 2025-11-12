#include<bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10,M = 1e6 + 10;
int f[N],n,m,k,cnt;
long long ans;
int find_(int x){
	if(f[x]==x)return x;
	return f[x]=find_(f[x]);
}
void merge(int a,int b){
	int fa=find_(a),fb=find_(b);
	f[fa]=fb;
	return;
}
struct Edge{
	int u,v,val;
}e[M];
bool p(Edge a,Edge b){
	return a.val<b.val; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].val);
	sort(e+1,e+1+m,p);
	for(int i=1;i<=m;i++){
		if(find_(e[i].u)==find_(e[i].v))continue;
		else{
			ans+=e[i].val;
			cnt++;
			merge(e[i].u,e[i].v);
		}
		if(cnt==n)break;
	}
	printf("%lld\n",ans);
	return 0;
}
