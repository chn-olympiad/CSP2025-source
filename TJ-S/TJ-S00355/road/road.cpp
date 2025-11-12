#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+10,M=1e6+10;

struct Edge{
	int l,r,val,k;
	friend bool operator<(const Edge x,const Edge y){
		return x.val<y.val;
	}
}e[M],e2[M+N*11],e3[20][N];

int K[20],n,m,k,vis[20],p[N+20],ans,cnt;

int find(int x){
	if(x==p[x])return x;
	return p[x]=find(p[x]); 
}

void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return ;
	p[x]=y;
	return ;
}

void Minn(int x){
	int nd=n,cst=0;
	for(int i=1;i<=k;i++){
		vis[i]=0;
		if((x>>(i-1))%2==1){
			vis[i]=1;
			nd++;
			cst+=K[i];
		}
	}
	for(int i=1;i<=n+k;i++){
		p[i]=i;
	}
	int t=1;
	for(int i=1;i<=cnt;i++){
		if(e2[i].k!=0 && !vis[e2[i].k])continue;
		int u=e2[i].l,v=e2[i].r;
		if(find(u)!=find(v)){
			merge(u,v);
			cst+=e2[i].val;
			t++;
		}
		if(t==nd)break;
	}
	ans=min(ans,cst);
	return ;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0x3f3f3f3f3f3f3f3f;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].l>>e[i].r>>e[i].val;
		e2[++cnt]=e[i];
		e2[cnt].k=0;
	}
	for(int i=1;i<=k;i++){
		cin>>K[i];
		for(int j=1;j<=n;j++){
			cin>>e3[i][j].val;
			e3[i][j].l=n+i;
			e3[i][j].r=j;
			e2[++cnt]=e3[i][j];
			e2[cnt].k=i;
		}
	}
	sort(e2+1,e2+1+cnt);
	for(int i=0;i<(1<<k);i++){
		//cout<<'^'<<endl;
		Minn(i);
	}
	cout<<ans<<endl;
	
	return 0;
}

