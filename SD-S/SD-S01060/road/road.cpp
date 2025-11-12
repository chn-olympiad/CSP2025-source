#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}edges[1000100];
int rk[1001000];
int fa[1001000];
int v[110];
int n,m,k; 
int idx;
bool st[100010];
int find(int p){
	if(fa[p]==p) return p;
	fa[p]=find(fa[p]);
	return find(fa[p]);
}
void marge(int a,int b){
	int x=find(a),y=find(b);
	if(x==y) return ;
	if(rk[x]<=rk[y]) fa[x]=y;
	else fa[y]=x;
	if(x!=y&&rk[x]==rk[y]) rk[y]++;
}
bool cmp(Node a,Node b){
	return a.c<b.c;
}
long long  cru(){
	int cnt=1;
	long long  res=0;
	for(int i=0;i<idx;i++){
		//cout<<"-1"<<endl;
		int a=edges[i].a,b=edges[i].b,c=edges[i].c;
		int x=find(a),y=find(b);
	//	if((a>n||b>n)&&i>0) continue;
		if(x==y) continue;
		else{
			res+=c;
			marge(a,b);
			cnt++;
		//		cout<<res<<endl;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		rk[i]=1;
	}
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
	//	scanf("%d%d%d",&a,&b,&c);
		edges[idx].a=a;
		edges[idx].b=b;
		edges[idx].c=c;
		idx++;
	//	cout<<idx<<endl;
	}
	sort(edges,edges+idx,cmp);	
	long long ans=cru();
	for(int i=1;i<=k;i++){
		scanf("%d",&v[i]);
		for(int j=1;j<=n;j++){
		 int c;
		 scanf("%d",&c);
		edges[idx].a=n+i;
		edges[idx].b=j;
		edges[idx].c=c;
		idx++;
		}
	}
	sort(edges,edges+idx,cmp);	
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		rk[i]=1;
	}

	ans=min((long long)(ans),	cru());
	

	cout<<ans;
	return 0;
} 
