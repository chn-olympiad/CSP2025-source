#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int n,m,pre[1100010],k,siz[1010000],f[15][10010],c[100100],used[100010],idu,preu[100010],fa[100010],id;
long long dis[11010];
struct edges{
	int from,to,val;
}e[1100010],u[1100001]; 
void add(int x,int y,int z){
	id++;
	e[id].from=x;
	e[id].to=y;
	e[id].val=z;
	return;
}
bool cmp(edges &x,edges &y){
	return x.val<y.val;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
long long getans(){
	long long s=0,re=0;
	sort(e+1,e+id+1,cmp);
//	for(int i=1;i<=id;i++){
//		cout << e[i].val << " ";
//	}
	for(int i=1;i<=id;i++){
		edges nw=e[i];
		int fr=e[i].from,t=e[i].to;
//		cout << nw.val << "   *******\n"; 
		int f1=find(fr),f2=find(t);
//		cout << fr << " " << t << " " << f1 << " " << f2 << endl;
		if(f1!=f2){fa[f1]=f2,s+=e[i].val;}
		else continue;
		re++;
		if(re>=n)break;
	} 
	return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>f[i][j];
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	long long ans=getans();
	cout << ans;
	return 0;
}// 5 5 0 1 2 1 1 3 1 1 4 2 1 5 2 1 5 4
