#include<bits/stdc++.h>
using namespace std;
const int M=1e6+20;
const int N=1e4+20;
int n,m,k,f[N],c;
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
struct edge{
	int u,v,w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//		{
//			if(i!=j)
//			e[i][j]=1e9;
//		}
//			
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		e[i].u=x;
		e[i].v=y;
		e[i].w=z;
	}
	sort(e+1,e+m+1,cmp);
	int t=-1;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].u)!=find(e[i].v)){
			c+=e[i].w;
			f[e[i].u]=-1;
			f[e[i].v]=-1;
			//cout<<e[i].u<<' '<<e[i].v<<endl;
			//cout<<find(e[i].u)<<' '<<find(e[i].v)<<endl;
		}
//		for(int i=1;i<=n;i++)
//			cout<<find(i)<<' ';
//		cout<<endl;
	}
	cout<<c;
}
//	queue q;
//	q.push_back(1);
//	while(!q.empty){
//		int u=q.front(),v,w;
//		int minn=1e9;
//		q.pop();
//		for(auto x:edge[u]){
//			if(minn>x.second){
//				minn=x.second;
//				v=x.first;
//			}
//		}
//		cnt+=minn;
//		q.push(v);
//	}
//}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4


