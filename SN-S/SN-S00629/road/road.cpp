#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,c[15],tot,fa[N+15];
bool op[N+15];
ll ans;
struct node{
	int x,y,w;
} e[M+N*10];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int a){
	if(fa[a]==a)return a;
	return fa[a]=find(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	cin>>n>>m>>k;
	bool ts=true;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		e[++tot]={x,y,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)ts=false;
		for(int j=1;j<=n;j++){int a;cin>>a;e[++tot]={j,n+i,a};if(a!=0)ts=false;}
	}
	if(n==1){cout<<0<<endl;return 0;}
	if(ts){cout<<0<<endl;return 0;}
	sort(e+1,e+tot+1,cmp);ans=1e18;
	for(int st=0;st<(1<<k);st++){
		ll sum=0;int q=0;
		for(int i=1;i<=n;i++)fa[i]=i,op[i]=true;
		for(int i=1;i<=k;i++){
			op[i+n]=false;fa[i+n]=n+i;
			if((st&(1<<(i-1))))sum+=c[i],op[i+n]=true,++q;
		}
		int cnt=0;
		for(int i=1;i<=tot;i++){
			int x=find(e[i].x),y=find(e[i].y),val=e[i].w;
			if(!op[x]||!op[y]||x==y)continue;
			fa[x]=y;sum+=val;++cnt;
			if(cnt==n+q-1)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
