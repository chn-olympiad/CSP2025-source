#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,j,x,y,z,t,cnt,id,mi,ans,fx,fy,fa[10050],ff[11][1010],c[11];
vector<int>f[100050];
struct no{
	int x,y,z;
}a[1110010];
bool cmp(no q,no h){
	return q.z<h.z;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[++t].x=x;a[t].y=y;a[t].z=z;
	}
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=t;i++){
		fx=find(a[i].x);
		fy=find(a[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			cnt++;
			mi+=a[i].z;
		}
		if(cnt==n-1)break;
	}
	if(k==0){
		cout<<mi;
		return 0;
	}
	return 0;
}
