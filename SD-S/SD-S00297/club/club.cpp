#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,ans;
struct nd{
	int x,y,z,flag,cnt;
}a[N];
vector<int> vx,vy,vz;
signed main(){
//	freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		vx.clear();vy.clear();vz.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int maxx=max(a[i].x,max(a[i].y,a[i].z));
			ans+=maxx;
			if(a[i].x==maxx){
				vx.push_back(a[i].x-max(a[i].y,a[i].z));
			}
			else if(a[i].y==maxx){
				vy.push_back(a[i].y-max(a[i].x,a[i].z));
			}
			else if(a[i].z==maxx){
				vz.push_back(a[i].z-max(a[i].x,a[i].y));
			}
		}
		if(vx.size()>n/2){
			sort(vx.begin(),vx.end());
			int sum=(int)(vx.size())-n/2;
			for(int i=0;i<sum;i++){
				ans-=vx[i];
			}
		}
		else if(vy.size()>n/2){
			sort(vy.begin(),vy.end());
			int sum=(int)(vy.size())-n/2;
			for(int i=0;i<sum;i++){
				ans-=vy[i];
			}
		}
		else if(vz.size()>n/2){
			sort(vz.begin(),vz.end());
			int sum=(int)(vz.size())-n/2;
			for(int i=0;i<sum;i++){
				ans-=vz[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
