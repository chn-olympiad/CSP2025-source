#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10,MAXM=2e6+10;
struct node{
	int u,v;
	long long w;
}e[MAXM];
int top=0;
void add(int u,int v,int w){
	e[top].u=u;
	e[top].v=v;
	e[top].w=w;
	top++;
}
int c[11][MAXN];
int fath[MAXN];
int fat(int x){
	if(fath[x]==x)return x;
	return fath[x]=fat(fath[x]);
}
bool find(int a,int b){
	return fat(a)==fat(b);
}
void merg(int a,int b){
	fath[fat(a)]=fat(b);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
long long klsker(int n){
	for(int i=1;i<=n;i++)fath[i]=i;
	long long ans=0;
	int cnt=0;
	int m=top;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++){
		if(find(e[i].u,e[i].v)==0){
			merg(e[i].u,e[i].v);
			ans+=e[i].w;
//			cout<<e[i].w<<"m"<<'\n';
			cnt++;
			if(cnt==n-1){
				return ans;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n,m,k;
	int u,v;
	long long w;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	bool A=1;
	for(int j=0;j<k;j++){
		cin>>w;
		c[j][0]=w;
		if(w!=0)A=0;
		for(int i=1;i<=n;i++){
			cin>>w;
			c[j][i]=w;
			if(w!=0)A=0;
		}
	}
	if(k==0){
		cout<<klsker(n)<<'\n';
	}else if(A){
		cout<<0<<'\n';
	}
	return 0;
}


/*

5 6 0
1 2 1
2 3 0
1 4 2
1 5 2
1 3 4
5 1 0

*/
