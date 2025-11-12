#include<bits/stdc++.h>
using namespace std;
struct hjh{
	int u,v,w;
}a[1000005];
bool cmp(hjh x,hjh y){
	return x.w<y.w;
}
map<int,int>c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0){
		sort(a+1,a+1+m,cmp);int j=2;
		long long ans=0;
		c[a[1].u]++;c[a[1].v]++;ans+=a[1].w;
		while(c.size()<n){
			if(!c[a[j].u]||!c[a[j].v]){
				c[a[j].u]+=1;
				c[a[j].v]+=1;
				ans+=a[j].w;
			}
			j++;
		}
		cout<<ans;
	}
	return 0;
}/*
4 5 0
1 2 1
3 4 2
2 3 2
3 4 3
1 4 4
*/
