#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define lb lower_bound
int n,m,k;
struct eeg{
	int u,v;
	ll w;
}eg[1000005];
struct vgg{
	int idv,id;
	ll w;
}vg[12][10505];
ll ans=1e18,c[15];
bool cmp(eeg x,eeg y){
	return x.w<=y.w;
}
bool cmp1(vgg x,vgg y){
	return x.w<=y.w;
}
int fa[150050];int s[100050];
int f(int x){
	if(fa[x]==x)return x;
	return fa[x]=f(fa[x]);
}
ll ct[100005];int lt[100005],rt[100005];
int vis[12];
ll st[2000000];int l[2000000],r[2000000];
ll s0[100005][2];int l0[100005][2],r0[100005][2];
void ck(){
	int op=0,s1=0;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			op^=1;
			int t1=1,t2=1,t3=0;
			while(t3<n+s1){
				t3++;
				if(t1>n){
					s0[t3][op]=s0[t2][op^1],l0[t3][op]=l0[t2][op^1],r0[t3][op]=r0[t2++][op^1];
					continue;
				}
				if(t2>s1){
					s0[t3][op]=vg[i][t1].w,l0[t3][op]=vg[i][t1].id,r0[t3][op]=vg[i][t1++].idv;
					continue;
				}
				if(t1<=n&&t2<=s1&&s0[t2][op^1]<=vg[i][t1].w){
					s0[t3][op]=s0[t2][op^1],l0[t3][op]=l0[t2][op^1],r0[t3][op]=r0[t2++][op^1];
				}else if(t1<=n&&t2<=s1){
					s0[t3][op]=vg[i][t1].w,l0[t3][op]=vg[i][t1].id,r0[t3][op]=vg[i][t1++].idv;
				}
			}
			s1+=n;
			//printf("%d %d %d  ",t1,t2,s);
		}
	}
	for(int i=1;i<=s1;i++)ct[i]=s0[i][op],lt[i]=l0[i][op],rt[i]=r0[i][op];
	//for(int i=1;i<=s;i++)printf("%lld %d %d  ",ct[i],lt[i],rt[i]);
	//printf("    %d  \n ",s);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d%d%lld",&eg[i].u,&eg[i].v,&eg[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&vg[i][j].w);
			vg[i][j].idv=i+n;vg[i][j].id=j;
		}
		sort(vg[i]+1,vg[i]+n+1,cmp1);
		//for(int j=1;j<=n;j++)printf("%lld ",vg[i][j].w);
	}
	sort(eg+1,eg+m+1,cmp);
	for(int qq=0;qq<(1<<k);qq++){
		int t0=0,tt=0,d1=qq;
		for(int i=1;i<=k;i++)vis[i]=0;
		while(d1){
			vis[++t0]=d1%2;
			tt+=d1%2;
			d1/=2;
		}
		ll anss=0;
		for(int i=1;i<=k;i++)anss+=vis[i]*c[i];
		ck();
		int t1=1,t2=1,t3=0;
		while(t3<m+n*tt){
			t3++;
			if(t1>m){
				st[t3]=ct[t2],l[t3]=lt[t2],r[t3]=rt[t2++];
				continue;
			}
			if(t2>n*tt){
				st[t3]=eg[t1].w,l[t3]=eg[t1].v,r[t3]=eg[t1++].u;
				continue;
			}
			if(t1<=m&&t2<=n*tt&&eg[t1].w<=ct[t2]){
				st[t3]=eg[t1].w,l[t3]=eg[t1].v,r[t3]=eg[t1++].u;
			}else if(t1<=m&&t2<=n*tt){
				st[t3]=ct[t2],l[t3]=lt[t2],r[t3]=rt[t2++];
			}
		}
		for(int i=1;i<=n+k+k;i++)fa[i]=i,s[i]=1;
		for(int i=1;i<=t3;i++){
			if(f(l[i])!=f(r[i])){
				anss+=st[i];
				s[f(r[i])]+=s[f(l[i])];
				fa[f(l[i])]=f(r[i]);
				//printf("%d %d %lld %d  ",l[i],r[i],st[i],m+n*t0);
				if(s[f(r[i])]==n+tt)break;
			}
		}
		//printf("%lld\n",anss);
		ans=min(ans,anss);
	}
	printf("%lld",ans);
	return 0;
}
