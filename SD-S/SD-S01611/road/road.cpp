#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void read(int &x){
	x=0;ll sign=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sign;
}
void read(ll &x){
	x=0;ll sign=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sign;
}
int n,m,k;
const int N=2e6+5;
const int M=1e4+5; 
struct node{
	int u,v,w;
}e[N],e1[N],e2[M];
int f[M],ck[N],c[M],a[15][M];
bool cmp(node x,node y){
	if(x.w!=y.w)return x.w<y.w;
	return x.u<y.u;
}
int find_fa(int x){
	if(x==f[x])return x;
	return f[x]=find_fa(f[x]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(e[i].u);read(e[i].v);read(e[i].w);
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int t=find_fa(e[i].u),t1=find_fa(e[i].v);
		if(t==t1){
			ck[i]=-1;
			continue;
		}
		f[t]=t1;
		ck[i]=1;
		cnt++;
		if(cnt>=n-1)break;
	}
	int cnt1=0;
	for(int i=1;i<=m;i++){
		if(ck[i]==1){
			e1[++cnt1]=e[i];
			e2[cnt1]=e1[cnt1];
		}
	}
	//cout<<cnt1<<endl;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j]);
		}
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		cnt1=n-1;
		ll ans1=0;
		for(int j=1;j<=n+k;j++)f[j]=j;
		int cntt=0;
		for(int j=0;j<k;j++){
			if(((i>>j)&1)){
				ans1+=c[j+1];
				for(int kk=1;kk<=n;kk++){
					node x;
					x.u=n+j+1,x.v=kk,x.w=a[j+1][kk];
					if(x.w>e2[n-1].w)continue;
					e1[++cnt1]=x;
				}
				cntt++;
			}
		}
		cnt=0;
		sort(e1+1,e1+cnt1+1,cmp);
		//for(int j=1;j<=cnt1;j++)cout<<e1[j].u<<" "<<e1[j].v<<" "<<e1[j].w<<endl;
		for(int j=1;j<=cnt1;j++){
			int t=find_fa(e1[j].u),t1=find_fa(e1[j].v);
			if(t==t1)continue;
			f[t]=t1;
			cnt++;
			ans1+=e1[j].w;
			if(cnt>=n+cntt-1)break;
		}
		for(int j=1;j<=n-1;j++)e1[j]=e2[j];
		if(cnt<n+cntt-1)continue;
		//cout<<ans1<<" "<<i<<endl; 
		ans=min(ans,ans1);
	}
	printf("%lld",ans);
	return 0;
}




