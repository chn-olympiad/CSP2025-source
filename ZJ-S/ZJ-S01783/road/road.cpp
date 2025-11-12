#include<bits/stdc++.h>
using namespace std;
int n,k,m,i,x,y,ans,f[10010];
struct no{
	int x,y,z;
}a[1001000];
bool cmp(no q,no h){
	return q.z<h.z;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(i=1;i<=n;i++){
			f[i]=i;
		}
		for(i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}sort(a+1,a+m+1,cmp);
		for(i=1;i<=m;i++){
			x=find(a[i].x);
			y=find(a[i].y);
			if(x!=y){
				f[x]=y;
				ans+=a[i].z;
			}
		}cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
