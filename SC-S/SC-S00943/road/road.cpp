#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct zyx{
	int from,to,v;
}w[100005];
int num; 
int sss;
int fa[10005];
bool cmp(zyx a,zyx b){
	return a.v<b.v;
}
int find(int x){
//	cout<<x<<endl;
	if(x==fa[x]) return x;	
	return fa[x]=find(fa[x]);
} 
void merge(int x,int y){
	int a=find(x),b=find(b);
	fa[a]=b;
} 
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>w[++num].from>>w[num].to>>w[num].v;
	}
	sort(w+1,w+1+n,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	long long ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int aa=find(w[i].from),bb=find(w[i].to);
		if(aa!=bb){
			merge(w[i].from,w[i].to);
			ans+=w[i].v;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<endl;
	return 0;
} 