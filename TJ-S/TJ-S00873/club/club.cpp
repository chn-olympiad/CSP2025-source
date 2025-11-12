#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
struct node{
	int fus,maxn,maxnn;
}a[500005];
bool cmp(node x,node y){
	if(x.fus==y.fus){
		return x.maxn-x.maxnn<y.maxn-y.maxnn;
	}
	return x.fus<y.fus;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0,cntt=0,cnttt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			int uu=max({u,v,w});
			int num=0;
			int maxn=0;
			int id=0;
			if(uu==u){
				id=1;
				num++;
			}else{
				maxn=max(maxn,u);
			}
			if(uu==v){
				id=2;
				num++;
			}else{
				maxn=max(maxn,v);
			}
			if(uu==w){
				id=3;
				num++;
			}else{
				maxn=max(maxn,w);
			}
			a[i].fus=id;
			ans+=uu;
			if(id==1){
				cnt++;
			}else if(id==2){
				cntt++;
			}else{
				cnttt++;
			}
			if(num==1){

				a[i].maxn=uu;
				a[i].maxnn=maxn;
			}else{
				a[i].maxn=a[i].maxnn=uu;
			}
		}
		sort(a+1,a+n+1,cmp);
		int maxn=max({cnt,cntt,cnttt});
		if(maxn<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int u=maxn-(n/2);
		int maxid=0;
		if(cnt==maxn){
			maxid=1;
		}else if(cntt==maxn){
			maxid=2;
		}else{
			maxid=3;
		}
		for(int i=1;i<=n;i++){
			if(u==0){
				break;
			}
			if(a[i].fus==maxid){
				ans-=(a[i].maxn-a[i].maxnn);
				u--;
			}
		}
		cout<<ans<<endl;
	}
}
