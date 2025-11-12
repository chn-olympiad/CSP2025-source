#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=2e9;
const int MOD=1e9+7;
struct club{
	int x,y,z;
}a[N];
int n,ans,cnt1,cnt2,cnt3,jb;
vector<club>b[3];
int vis[N][3];
void solve(){
	cin>>n;
	memset(vis,0,sizeof vis);
	for(int i=0;i<3;i++)b[i].clear();
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=n;i++){
		if(a[i].x>a[i].y&&a[i].x>a[i].z){
			if(cnt1==n/2){
				int mn=INF,mn1=INF,mnid,mnid1;
				for(int i=0;i<b[0].size();i++){
					if(vis[i][0])continue;
					club u=b[0][i];
					if(u.x-u.y<mn){
						mn=min(u.x-u.y,mn);
						mnid=i;
					}
					if(u.x-u.z<mn1){
						mn1=min(u.x-u.z,mn1);
						mnid1=i;
					}
				}
				int bla=max(a[i].y,a[i].z),jl=a[i].x-min(mn,mn1);
				if(bla>jl)ans+=bla;
				else{
					if(mn<mn1)vis[mnid][0]=1;
					else vis[mnid1][0]=1;
					ans+=jl;
					b[0].push_back(a[i]);
				}
			}else{
				cnt1++;
				ans+=a[i].x;
				b[0].push_back(a[i]);
			}
		}
		else if(a[i].x<a[i].y&&a[i].y>a[i].z){
			if(cnt2==n/2){
				int mn=INF,mn1=INF,mnid,mnid1;
				for(int i=0;i<b[1].size();i++){
					if(vis[i][1])continue;
					club u=b[1][i];
					if(u.y-u.x<mn){
						mn=min(u.y-u.x,mn);
						mnid=i;
					}
					if(u.y-u.z<mn1){
						mn1=min(u.y-u.z,mn1);
						mnid1=i;
					}
				}
				int bla=max(a[i].x,a[i].z),jl=a[i].y-min(mn,mn1);
				if(bla>jl)ans+=bla;
				else{
					if(mn<mn1)vis[mnid][1]=1;
					else vis[mnid1][1]=1;
					ans+=jl;
					b[1].push_back(a[i]);
				}
			}else{
				cnt2++;
				ans+=a[i].y;
				b[1].push_back(a[i]);
			}
		}
		else if(a[i].z>a[i].y&&a[i].x<a[i].z){
			if(cnt3==n/2){
				int mn=INF,mn1=INF,mnid,mnid1;
				for(int i=0;i<b[2].size();i++){
					if(vis[i][2])continue;
					club u=b[2][i];
					if(u.z-u.x<mn){
						mn=min(u.z-u.x,mn);
						mnid=i;
					}
					if(u.z-u.y<mn1){
						mn1=min(u.z-u.y,mn1);
						mnid1=i;
					}
				}
				int bla=max(a[i].y,a[i].x),jl=a[i].z-min(mn,mn1);
				if(bla>jl)ans+=bla;
				else{
					if(mn<mn1)vis[mnid][2]=1;
					else vis[mnid1][2]=1;
					ans+=jl;
					b[2].push_back(a[i]);
				}
			}else{
				cnt3++;
				ans+=a[i].z;
				b[2].push_back(a[i]);
			}
		}
	}
	cout<<ans<<endl;
	ans=0,cnt1=cnt2=cnt3=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
