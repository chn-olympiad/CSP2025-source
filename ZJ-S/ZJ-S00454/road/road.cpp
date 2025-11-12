#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,k,ans,d1,b[10005],zx=2312331233434,ddd[1000005];
struct edge{
	LL u,v,w;
}d[1500005];
bool cmp(edge no,edge yes){
	return no.w<yes.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if (k==0){
		for (int i=1;i<=m;i++){
			LL u,v,w;
			cin>>d[i].u>>d[i].u>>d[i].w;
		}
		sort (d+1,d+1+m,cmp);
		for (int i=1;i<=m;i++){
			if (b[d[i].u]==0||b[d[i].v]==0) ans+=d[i].w,b[d[i].u]=1,b[d[i].v]=1,ddd[1]++;
			if (ddd[1]==n-1){
				cout<<ans;
				return 0;
			}
		}
		return 0;
	}
	cout<<0;
}//16

/*
5 7 0
1 2 10
1 3 8
1 5 13
3 4 5
5 4 2
3 5 3
3 2 7
*/
