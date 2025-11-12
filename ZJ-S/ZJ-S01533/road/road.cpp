#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+5,N=1e4+5;
int n,mm,m,K,fa[N],cnt,c[15],cn,res,num,L,R;
ll ans=0,sum;
struct node{
	int len,l,r;
}G[M],g[N],a[15][N],f[M],C[M];
bool cmp(node p,node q){
	return p.len<q.len;
}
int find(int x){
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
bool check(int x,int y){
	return (find(x)==find(y));
}
void hb(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>mm>>K;
	for(int i=1;i<=n+K;i++)fa[i]=i;
	for(int i=1;i<=mm;i++){
		cin>>G[i].l>>G[i].r>>G[i].len;
	}
	sort(G+1,G+mm+1,cmp);
	for(int i=1;i<=mm;i++){
		if(check(G[i].l,G[i].r))continue;
		hb(G[i].l,G[i].r);
		g[++m]=G[i];
		cnt++;
		ans+=g[m].len;
		if(cnt==n-1)break;
	}
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
			a[i][j]={t,i+n,j};
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	for(int k=1;k<(1<<K-1);k++){
		num=res=sum=cnt=0;
		for(int t=1;t<=K;t++){
			if(((1<<t-1)&k)==0)continue;
			sum+=c[t];
			cn=0;
			res++;
			L=1,R=1;
			while(L<=num&&R<=n){
				if(f[L].len<a[t][R].len)C[++cn]=f[L],L++;
				else C[++cn]=a[t][R],R++;
			}
			while(L<=num)C[++cn]=f[L],L++;
			while(R<=n)C[++cn]=a[t][R],R++;
			num=cn;
			for(int i=1;i<=num;i++)f[i]=C[i];
		}
		cn=0;
		L=1,R=1;
		while(L<=num&&R<=m){
			if(f[L].len<g[R].len)C[++cn]=f[L],L++;
			else C[++cn]=g[R],R++;
		}
		while(L<=num)C[++cn]=f[L],L++;
		while(R<=m)C[++cn]=g[R],R++;
		num=cn;
		for(int i=1;i<=num;i++)f[i]=C[i];
		for(int i=1;i<=n+K;i++)fa[i]=i;
		for(int i=1;i<=num;i++){
			if(check(f[i].l,f[i].r))continue;
			hb(f[i].l,f[i].r);
			sum+=f[i].len;
			cnt++;
			if(cnt==n+res-1)continue;
		}
		//cout<<sum<<" ";
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

