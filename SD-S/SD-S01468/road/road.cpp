#include<bits/stdc++.h>//先凹一个最小生成树
using namespace std;//现在是15：07  5h前的我：最小生成树肯定不考  不复习了 //我应该没写错吧
//这玩意wa了可不是很好调 
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
int cnt=0;
int n,m,k;
priority_queue<pii,vector<pii>,greater<pii> >q;//fi存长度，se存边的编号 
int read(){
	int x=0,f=0;char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')x*=10,x+=c-'0',c=getchar();
	return x;
}
struct edge{
	int u,v,w;
}e[1500010];
int c[50010];
int sa[15];
int f[50010];
int a[15][50010];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void uniue(int x,int y){f[find(x)]=find(y);}
void init(){for(int i=1;i<=n;i++)f[i]=i;}
int kul(){
	init();
	int ans=0;
	int sum=0;
	for(int i=1;i<=cnt;i++){
		int w=q.top().fi;
		int x=q.top().se;
		q.pop();
		if(find(e[x].u)==find(e[x].v))
		continue;
		sum++;
		ans+=w;
		uniue(e[x].u,e[x].v);
		if(sum==n-1)
		break;
	}
	return ans;
}
signed main(){//lld!
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		cnt++;
		e[cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
		q.push({w,cnt});
	}
	if(k==0){
		printf("%lld",kul());
		return 0;
	}
	int pd=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0)pd=1;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	if(pd==0){//每一个都不需要代价 
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				cnt++;
				e[cnt].u=n+i;
				e[cnt].v=j;
				e[cnt].w=a[i][j];
				q.push({a[i][j],cnt});
			}
		}
		n+=k;
		printf("%lld\n",kul());
		return 0;
	}
	else{//2^k
		int ans=LLONG_MAX;
		for(int T=0;T<=(1ll<<k)-1;T++){
			while(q.size())q.pop();
			cnt=0;
			for(int i=1;i<=m;i++){
				cnt++;
				q.push({e[cnt].w,cnt});
			}
			int ii=T,num=0;
			while(ii){
				sa[++num]=ii%2;
				ii/=2;
			}
			int sum_=0;
			int cnt__=0;
			for(int i=1;i<=num;i++){
				if(sa[i]==1){
					for(int j=1;j<=n;j++){
						cnt++;
						e[cnt].u=n+i;
						e[cnt].v=j;
						e[cnt].w=a[i][j];
						q.push({a[i][j],cnt});
					}
					sum_++;
					cnt__+=c[i];
				}
			}
			int nn=n;
			n+=sum_;
			ans=min(ans,kul()+cnt__);
			n=nn;
		}
		printf("%lld",ans);
		return 0;
	}
}//lld!
//时间复杂度O(m*log(m)*(2^k)) 
//现在的重点就变成了 现在已经拿了64pts  要不要去卡常再拿8分
//纯常数现在要卡4s 
//还有2.5h 
//先不卡了  去写T3 
