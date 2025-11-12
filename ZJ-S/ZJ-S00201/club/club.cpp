#include<bits/stdc++.h>
using namespace std;
struct node{
	int m,s;
};
int t,n,x,y,z;
bool cmp(node p,node q){
	return p.s<q.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long ans=0;
		vector<node> v[3];
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z) v[0].push_back({x,x-max(y,z)}),ans+=x;
			else if(y>=x&&y>=z) v[1].push_back({y,y-max(x,z)}),ans+=y;
			else if(z>=x&&z>=y) v[2].push_back({z,z-max(x,y)}),ans+=z;
		}
		for(int i=0;i<3;i++){
			if(v[i].size()>n/2){
				sort(v[i].begin(),v[i].end(),cmp);
				for(int j=0;j<v[i].size()-n/2;j++) ans-=v[i][j].s;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
