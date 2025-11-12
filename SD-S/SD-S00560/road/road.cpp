#include<bits/stdc++.h>

using namespace std;

#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long

const int N=2e6+10;//×¢ÒâÐÞ¸Ä
const int M=4e6+10;

bool ST;

struct node{
	ll u,v,w;
}e[N];
int fa[N];
int findf(int x){
	return fa[x]==x?x:fa[x]=findf(fa[x]);
}
int n,m,k;
bool ED;
bool cmp(node a,node b){
	return a.w<b.w;
}
void kru(){
	ll sum=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=findf(e[i].u),v=findf(e[i].v),w=e[i].w;
		if(u==v) continue;
		fa[v]=u;
		sum+=w;
	}
	cout<<sum<<endl;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cout<<abs(&ED-&ST)/1024.0/1024.0<<endl;

	fst
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(!k){
		kru();
		return 0;
	}
//	kru();
	//cout<<1;
//	return 0;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			e[++m]={i,j,w};
		}
	}
	kru();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

*/ 
