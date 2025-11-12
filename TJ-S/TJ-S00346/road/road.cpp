#include<bits/stdc++.h>
using namespace std;
int s[10005],n,m,k,ans;
struct edge{
	int u,v,w;
}ed[1000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int sfind(int x){
	return s[x]==x?x:s[x]=sfind(s[x]);
}
void kal(){
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=n;i++) s[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) return;
		int e1=sfind(ed[i].u),e2=sfind(ed[i].v);
		if(e1==e2) continue;
		else{
			s[e1]=e2;
			cnt++;
			ans+=ed[i].w;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	int l;
	for(int i=1;i<=k*n+k;k++) cin>>l;
	kal();
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
} 
