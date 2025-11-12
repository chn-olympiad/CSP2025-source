#include<bits/stdc++.h>
using namespace std;
int f[10005];
int fnd(int x,int y){
	f[x]+=1;
	f[y]+=1;
}
struct road{
	int u,v,w;	
}r[1000005];
bool cmp(road a,road b){
	return a.w>b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0,cnt=m;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
		ans+=r[i].w;
		fnd(r[i].u,r[i].v);
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=m;i++){
		if(((f[r[i].u]-1)!=0)&&((f[r[i].v]-1)!=0)){
			ans-=r[i].w;
			cnt--;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
