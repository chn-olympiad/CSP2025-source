#include<bits/stdc++.h>
#define ll long long
const ll N=1e4+100;
using namespace std;
ll read(){
	ll f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return f*k;
}
void print(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
} 
ll n,m,K,ans;
struct E{
	ll a,b,c;
}p[N*200],q[N*200];
ll w[20][N];
bool cmp(E x,E y){
	return x.c<y.c;
}
ll fa[N];
ll find(ll x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(ll cnt,ll len,ll cost){
	if(cost>=ans)return;
	if(cnt==K+1){
		for(ll i=1;i<=n+K;i++)fa[i]=i;
		for(ll i=1;i<=len;i++)q[i]=p[i];
		sort(q+1,q+1+len,cmp);
		ll sum=cost;
		for(ll i=1;i<=len;i++){
			ll a=find(q[i].a),b=find(q[i].b);
			if(a!=b){
				fa[a]=b;
				sum+=q[i].c;
			}
			if(sum>=ans)return;
		}
		ans=sum;
		return;
	}
	for(ll i=1;i<=n;i++){
		p[len+i]=(E){n+cnt,i,w[cnt][i]};
	}
	dfs(cnt+1,len+n,cost+w[cnt][0]);
	dfs(cnt+1,len,cost);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();K=read();
	ll flag=0;
	for(ll i=1;i<=m;i++){
		p[i].a=read();p[i].b=read();p[i].c=read();
	}
	for(ll i=1;i<=K;i++){
		ll FLAG=0;
		for(ll j=0;j<=n;j++){
			w[i][j]=read();
			if(j&&!w[i][j])FLAG=1;
		}
		if(w[i][0]||!FLAG)flag=1;
	}
	if(!K||!flag){
		for(ll i=1;i<=K;i++){
			for(ll j=1;j<=n;j++){
				if(!w[i][j]){
					for(ll k=1;k<j;k++){
						p[++m]=(E){k,j,w[i][k]};
					}
					for(ll k=j+1;k<n;k++){
						p[++m]=(E){j,k,w[i][k]};
					}
					break;
				}
			}
		}
		for(ll i=1;i<=n;i++)fa[i]=i;
		sort(p+1,p+1+m,cmp);
		for(ll i=1;i<=m;i++){
			ll a=find(p[i].a),b=find(p[i].b);
			if(a!=b){
				fa[a]=b;
				ans+=p[i].c;
			}
		}
		print(ans);
		return 0;
	}
	ans=2e18;
	dfs(1,m,0);
	print(ans);
	return 0;
} 
