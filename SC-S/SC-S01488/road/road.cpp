#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e4+20,M=1e6+10;
int n,m,k;
struct node{
	int u,v,w;
	bool operator>(const node &s) const{
		return w>s.w;
	}
}c[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int f[N];
int find(int x){
	return x==f[x]?f[x]:f[x]=find(f[x]);
}
int lowbit(int x){
	return x&(-x);
}
int xf[1030],a[15][N],re[N];

signed main(){
	freopen("road.in","r",stdin);	
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		c[i].u=read(),c[i].v=read(),c[i].w=read();
	}
	sort(c+1,c+1+m,cmp);
	for(int i=1;i<=k;i++){
		int t=read();
		xf[1<<(i-1)]=t;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=c[i].u,v=c[i].v;
		if(find(u)==find(v))continue;
		else {
			f[u]=v;
			re[++cnt]=i;
			ans+=c[i].w;
		}
		if(cnt==n-1)break;
	}
	if(k==0){
		printf("%lld\n",ans);
		return 0;
	}
	
	int h[15]={0};
	int sum=1e63;
	for(int s=0;s<(1<<k);s++){
		ans=0;
		cnt=0;
		priority_queue<node,vector<node> ,greater<node> >q;
		
		for(int i=1;i<n;i++)q.push(c[re[i]]);
		int l=0;
		int t=s;
		while(t!=0){
			int lt=lowbit(t);
			h[++l]=log2(lt)+1;
			for(int i=1;i<=n;i++){
				q.push({h[l]+n,i,a[h[l]][i]});
			}
			xf[s]+=xf[lt];
			t-=lt;
		}
		for(int i=1;i<=n+k;i++)f[i]=i;
		while(!q.empty()){
			int u=q.top().u,v=q.top().v,w=q.top().w;
			q.pop();
			if(find(u)==find(v))continue;
			else{
				f[u]=v;
				cnt++;
				ans+=w;
			}
			if(cnt==n+l-1)break;
		}
		sum=min(sum,ans+xf[s]);
	}
	printf("%lld\n",sum);
	return 0;
}