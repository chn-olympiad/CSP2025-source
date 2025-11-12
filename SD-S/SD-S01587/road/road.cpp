#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define qqq printf("------ qqq ------\n");
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int K=10+10;
ll T,n,m,k,ans;
ll c[K],a[K][N];
struct edge{
	ll u,v,w;
}t[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll fa[N];
ll find_(ll x){
	return (fa[x]==x)?(fa[x]):(fa[x]=find_(fa[x]));
}
void fun_1(ll len){
	for(ll i=1;i<=n;i++)
		fa[i]=i;
	sort(t+1,t+len+1,cmp);
	ll res=0,cnt=0;
	for(ll i=1;i<=len;i++){
		ll x=t[i].u,y=t[i].v;
		if(x>y)	swap(x,y);
		if(find_(x)!=find_(y))
			fa[x]=y,res++,cnt+=t[i].w;
	}
	ans=cnt;
	printf("%lld\n",ans);
	return ;
}
ll res;
void fun(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&t[i].u,&t[i].v,&t[i].w);
		res+=t[i].w;
	}
	bool fl=0;
	ll len=m;
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0)			fl=1;
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			t[++len]={i,j,a[i][j]};
			res+=a[i][j];
		}
	}
//	qqq;
	if(fl==0){
		fun_1(len);
	}
	else{
		ans=res;
		printf("%lld\n",ans);
	}
	return ;
}
int main(){
	fun();
	return 0;
}
/*
5 6 0
1 2 2
1 3 1
3 4 4
3 5 3
5 2 1
5 4 2
*/
