#include <bits/stdc++.h>
using namespace std;
int t,n,ans,mx[100005],vis[5];
struct node{
	int cnt,z;
} a[100005],b[100005],c[100005];
bool cmp(node x,node y){
	return x.z>y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int flag=0;
		vis[1]=0,vis[2]=0,vis[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].z>>b[i].z>>c[i].z;
			if(c[i].z!=0||b[i].z!=0) flag=1;
			int x=max({a[i].z,b[i].z,c[i].z});
			a[i].cnt=x;
			b[i].cnt=x;
			c[i].cnt=x;
		}
		if(flag==0){
			for(int i=1;i<=n;i++){
				ans+=a[i].z;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n==2){
			ans=max({a[1].z+b[2].z,a[1].z+c[2].z,b[1].z+c[2].z,b[1].z+a[2].z,c[1].z+a[2].z,c[1].z+b[2].z});
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(vis[1]>=n/2) break;
			if(a[i].z==a[i].cnt){
				ans+=a[i].z;
				vis[1]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[2]>=n/2) break;
			if(b[i].z==b[i].cnt){
				ans+=b[i].z;
				vis[2]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[3]>=n/2) break;
			if(c[i].z==c[i].cnt){
				ans+=c[i].z;
				vis[3]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}