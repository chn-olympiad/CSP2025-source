#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cnt,h;
struct ml{
	int v,w,u;
}y[1000110];
bool cmp(ml a,ml b){
	if(a.w!=b.w)return a.w<b.w;
	else if(a.u!=b.u) return a.u<b.u;
	else return a.v<b.v;
}
int t[1000010];
int fp[1000010];
int o[15][1000010];
int q_find(int x){
	if(fp[x]==x) return x;
	return fp[x]=q_find(fp[x]);
}
void q_push(int x,int y){
	fp[y]=fp[x];
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);
	memset(fp,0,sizeof(fp));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>y[i].u>>y[i].v>>y[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>o[i][j];
			if(o[i][j]!=0) h=1;
		}
	}
	if(!h&&k!=0){
		cout<<0;
		return 0;
	}
	sort(y+1,y+1+m,cmp);
	for(int i=1;i<=m;i++){
		int root1=q_find(y[i].u);
		int root2=q_find(y[i].v);
		if(root1&&root2){
			if(root1!=root2){
				q_push(root1,root2);
				ans+=y[i].w;
				cnt++;
				//cout<<'!';
			}
		}else{
			ans+=y[i].w;
			cnt++;
			if(root1||root2){
				if(!root1){
					q_push(root2,y[i].u);
				}else{
					q_push(root1,y[i].v);
				}
			}else{
				fp[y[i].u]=y[i].u;
				q_push(root1,root2);
				//cout<<'%';
			}
		}
		//cout<<i<<' '<<ans<<'\n';
		if(cnt>=n-1) break;
	}
	cout<<ans;
	return 0;
}

