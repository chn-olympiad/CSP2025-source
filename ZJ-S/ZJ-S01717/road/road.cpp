#include<bits/stdc++.h>
using namespace std;
long long n,m,q,sum,fa[100005],kk[100005];
struct node {
	int now;
	int to;
	int w;
}a[100005];
int finds(int x) {
	if(fa[x]==x)return x;
	else return fa[x]=finds(fa[x]);
}bool cmp(node x,node y) {
	if(x.w<y.w)return 1;
	return 0;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++)fa[i]=i;
	for(int i=1; i<=m; i++)cin>>a[i].now>>a[i].to>>a[i].w;
	if(q==0){
		sort(a+1,a+1+m,cmp);
		int r=0;
		for(int i=1; i<=m; i++){
			int fx=finds(a[i].now);
			int fy=finds(a[i].to);
			if(fx!=fy) {
				fa[fx]=fy;
				sum+=a[i].w;
				r++;
			}if(r==n-1){
				cout<<sum;
				break;
			}
		}return 0;
	}else cout<<0;
}
//road