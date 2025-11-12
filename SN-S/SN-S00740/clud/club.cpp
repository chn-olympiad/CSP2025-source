#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,cnt,qx,qy,qz,t;
int xq[100025],yq[100025],zq[100025];
struct qwertyuiop {
	int x,y,z;
} p[100025];
bool cmp(int i,int j){
	return i>j; 
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		qx=0,qy=0,qz=0;
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cnt=0;
			cin>>p[i].x>>p[i].y>>p[i].z;
			cnt=min(p[i].x,min(p[i].y,p[i].z));
			p[i].x-=cnt,p[i].z-=cnt,p[i].y-=cnt;
			ans+=cnt;
			cnt=max(p[i].x,max(p[i].y,p[i].z));
			ans+=cnt;
			if(p[i].x==cnt){
				xq[++qx]=p[i].x-max(p[i].y,p[i].z);
			}else if(p[i].y==cnt){
				yq[++qy]=p[i].y-max(p[i].x,p[i].z);
			}else{
				zq[++qz]=p[i].z-max(p[i].y,p[i].x);
			}
		}
		if(qx>n/2){
			sort(xq+1,xq+qx+1,cmp);
			for(int i=qx;i>n/2;i--)ans-=xq[i];
		}else if(qy>n/2){
			sort(yq+1,yq+qy+1,cmp);
			for(int i=qy;i>n/2;i--)ans-=yq[i];
		}else if(qz>n/2){
			sort(zq+1,zq+qz+1,cmp);
			for(int i=qz;i>n/2;i--)ans-=zq[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
