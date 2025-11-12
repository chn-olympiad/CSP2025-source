#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+9;
const ll inf=1e18;
ll fr(){
	ll x=0;
	char c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
struct ed{
	ll u,v,val;
}e[N],en[N];
int n,m,k,tot;
ll c[N],a[15][N],ans=inf,sum;
int flag1=1,flag2,flag3=1;
int fa[N];
void add(int t){
	for(int i=1;i<=m;i++) en[i]=e[i];
	for(int i=1;i<=k;i++){
		if((t>>(i-1))&1){
			sum+=c[i];
			for(int j=1;j<=n;j++) en[++tot]={n+i,j,a[i][j]};
		}
	}
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(ed x,ed y){return x.val<y.val;};

void solve1(){
	ans=0;
	tot=m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		int t;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				t=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(j!=t){
				e[++tot].u=t;
				e[tot].v=j;
				e[tot].val=a[i][j];
			}
		}
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int uu=find(e[i].u),vv=find(e[i].v);
		if(uu!=vv) ans+=e[i].val,fa[uu]=vv;
	}
	printf("%lld",ans);
}
void solve2(){
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<=(1<<k)-1;i++){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		tot=0;
		int cnt1=1,cnt2=1;
		sum=0;
		add(i);
		if(sum>ans) continue;
		sort(en+1,en+tot+1,cmp);
		for(int i=1;i<=tot+m;i++){
			if((cnt1<=m&&e[cnt1].val<en[cnt2].val)||cnt2>tot){
				int uu=find(e[cnt1].u),vv=find(e[cnt1].v);
				if(uu!=vv) sum+=e[cnt1].val,fa[uu]=vv;
				cnt1++;
			}
			else{
				int uu=find(en[cnt2].u),vv=find(en[cnt2].v);
				if(uu!=vv) sum+=en[cnt2].val,fa[uu]=vv;
				cnt2++;
			}
			if(sum>ans) break;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=fr(),m=fr(),k=fr();
	for(int i=1;i<=m;i++) e[i].u=fr(),e[i].v=fr(),e[i].val=fr();
	for(int i=1;i<=k;i++){
		c[i]=fr();
		if(c[i]!=0) flag1=0;
		flag2=0;
		for(int j=1;j<=n;j++) {
			a[i][j]=fr();
			if(a[i][j]==0) flag2=1; 
		}
		if(!flag2) flag3=0;
	}
	if(flag1&&flag2) solve1();
	else solve2();
	return 0;
}

