#include<bits/stdc++.h>
using namespace std;
struct u{
	int u,v;
	long long w;
}a[1000005];
int n,m,k,u1,v1,b[15][100005],f[100005],c[100005];
long long ans;
long long w1;
int find(int x){
	if(x!=f[x]) return f[x]=find(f[x]);
	return x;
}
void hb(int x,int y){
	f[find(x)]=find(y);
}
bool cmp(u a,u b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>u1>>v1>>w1;
		a[i]={u1,v1,w1};
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].v)) continue;
		hb(a[i].u,a[i].v);
		ans+=a[i].w;
		//cout<<a[i].w;
	}
	cout<<ans;
	return 0;
} 
