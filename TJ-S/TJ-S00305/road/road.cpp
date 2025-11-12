#include<bits/stdc++.h>
using namespace std;
int n,m,k,vel[10005],cnt;
struct egde{
	int fr,to,w;
}e[1000005];
bool cmp(egde a,egde b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].fr>>e[i].to>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(vel[e[i].fr]==1&&vel[e[i].to]==1)continue;
		ans+=e[i].w;
		if(vel[e[i].fr]==0)vel[e[i].fr]=1,cnt++;
		if(vel[e[i].to]==0)vel[e[i].to]=1,cnt++;
		if(cnt==n)break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
