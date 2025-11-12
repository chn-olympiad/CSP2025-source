#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e6;
int n,m,k;
int vs[10050];
int f[10010],c[15],hhkk;
ll wy,kkk;
ll a[10050][15];
struct bp{
	int a,b;
	ll c;
}p[1200010];
bool cmp(bp l,bp r){
	return l.c<r.c;
}
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
void sol(int now,int cnt,ll sum){
	if(now==k+1){
		if(sum>=wy)return;
		if(!cnt)return;
		hhkk=0;
		int tld=m;
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=n;j++){
				p[++tld]={c[i],j,a[c[i]][j]};
			}
		}
		for(int i=1;i<=n+k;i++)f[i]=i,vs[i]=0;
		sort(p+1,p+1+tld,cmp);
		for(int i=1;i<=tld;i++){
		//	printf("%d %d %lld\n",p[i].a,p[i].b,p[i].c);
			int x=find(p[i].a),y=find(p[i].b);
			if(x==y)continue;
			f[x]=y;
			sum+=p[i].c;
			if(sum>=wy)return;
			if(!vs[p[i].a])vs[p[i].a]=1,hhkk++;
			if(!vs[p[i].b])vs[p[i].b]=1,hhkk++;
			if(hhkk==n+cnt){
				wy=min(wy,sum);
				return;
			}
		}
	//	printf("\n");
		wy=min(wy,sum);
		return;
	}
	if(sum>=wy)return;
	c[cnt+1]=now+n;
	sol(now+1,cnt+1,sum+a[now+n][0]);
	c[cnt+1]=0;
	sol(now+1,cnt,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(!k){
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			int u,v;
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			p[i]={u,v,w};
		}
		sort(p+1,p+1+m,cmp);
		for(int i=1;i<=m;i++){
			int x=find(p[i].a),y=find(p[i].b);
			if(x==y)continue;
			f[x]=y;
			wy+=p[i].c;
		}
		printf("%lld",wy);
		return 0;
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		p[i]={u,v,w};
	}
	int cnt=0;
	for(int i=n+1;i<=n+k;i++){
		scanf("%lld",&a[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		//	p[++cnt]={i,j,a[i][j]};
		}
	}
	sort(p+1,p+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(p[i].a),y=find(p[i].b);
		if(x==y)continue;
		f[x]=y;
		wy+=p[i].c;
	}
	kkk=wy;
//	printf("%lld\n",wy);
	sol(1,0,0);
	/**/
	printf("%lld",wy);
	return 0;
}
//51wyçþÒÃ

