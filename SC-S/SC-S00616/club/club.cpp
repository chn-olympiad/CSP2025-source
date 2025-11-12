#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=1e5+10;
int n;
bool vis[N];
struct node{
	int x,y,z,idx;
}a[N],l[N],r[N],f[N];
bool cmp1(node x,node y){
	return x.x>y.x;
}
bool cmp2(node x,node y){
	return x.y>y.y;
}
bool cmp3(node x,node y){
	return x.z>y.z;
}
signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		int ans=0;
		memset(vis,0,sizeof vis);
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].idx=i;
			l[i]=a[i];
			r[i]=a[i];
			f[i]=a[i];
		}
		sort(l+1,l+n+1,cmp1);
		sort(r+1,r+n+1,cmp2);
		sort(f+1,f+n+1,cmp3);
		int ll=1,rr=1,ff=1;
		while(ll<=n&&rr<=n&&ff<=n){
			if(vis[l[ll].idx]==0&&l[ll].x>=r[rr].y&&l[ll].x>=f[ff].z){
				ans+=l[ll].x;
				vis[l[ll].idx]=1;
				ll++;
			}
			if(vis[r[rr].idx]==0&&l[ll].x<=r[rr].y&&r[rr].y>=f[ff].z){
				ans+=r[rr].y;
				vis[r[rr].idx]=1;
				rr++;
			}
			if(vis[f[ff].idx]==0&&f[ff].z>=r[rr].y&&l[ll].x<=f[ff].z){
				ans+=f[ff].z;
				vis[f[ff].idx]=1;
				ff++;
			}
			if(vis[l[ll].idx]) ll++;
			if(vis[r[rr].idx]) rr++;
			if(vis[f[ff].idx]) ff++;
		}
		cout << ans << "\n";
	}
	return 0;
}