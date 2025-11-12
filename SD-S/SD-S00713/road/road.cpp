#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL,pair<LL,LL> >
using namespace std;
const int N=1e6+9,INF=0x3f3f3f3f;
LL n,m,k,vis[N],city[11],cr[11][N],uc[11],nu,ans=INF,fa[N];
LL poww(LL x){
	LL sum2=1;
	for(int i=1;i<=x;i++){
		sum2*=2;
	}
	return sum2;
}
struct node{
	LL v,w;
};
vector<node>mp[N];
priority_queue<PLL,vector<PLL>,greater<PLL> >q;
LL find(LL x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
	fa[find(x)]=find(y);
	return ;
}
void findt(LL x){	
	LL sum=0,cnt=0,sc=0;nu=0;
	for(int i=0;i<=n+k;i++){fa[i]=i;}
	for(int i=0;i<=k;i++){uc[i]=0;}
	LL xx=x;
	while(xx){
		nu++;
		if(xx%2==1){
			uc[nu]=1;
			sum+=city[nu];
			sc++;
		}
		xx/=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<mp[i].size();j++){
			q.push({mp[i][j].w,{i,mp[i][j].v}});
		}
	}
	for(int i=1;i<=k;i++){
		if(!uc[i])continue;
		for(int j=1;j<=n;j++){q.push({cr[i][j],{i+n,j}});}
	}
	while(!q.empty()){
		PLL now=q.top();
		q.pop();
		LL c=now.first,a=now.second.first,b=now.second.second;
		if(find(a)==find(b))continue;
		merge(a,b);
		sum+=c;
		cnt++;
	}
	if(cnt>=n+sc-1)if(ans>sum)ans=sum;
	return ;
}
int main(){
	LL ac=1;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&city[i]);
		if(city[i])ac=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&cr[i][j]);
		}
	}
	LL p2=poww(k);
	if(!ac){
		for(int i=0;i<=p2-1;i++){
			findt(i);
		}
	}
	else find(p2-1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
