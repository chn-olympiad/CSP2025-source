#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],ans,maxm=1e9+1,cnt;
set<int>v;
struct noip{
	int u,v,w;
}a[10005];
bool cmp(noip x,noip y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	if(k==0){
		ans=0;
		sort(a,a+m,cmp);
		for(int i=0;i<m;i++){
			ans+=a[i].w;
			v.insert(a[i].u);
			v.insert(a[i].v);
			if(v.size()==n){
				break;
			}
		}
		cout<<ans;
	}else{
		for(int i=0;i<k;i++){
			cin>>c[i];
		}
		cout<<ans;
	}
	return 0;
}
