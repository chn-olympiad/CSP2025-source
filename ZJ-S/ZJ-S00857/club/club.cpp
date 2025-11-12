#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,cntx,cnty,cntz;
long long f[205][105][105],ans;
struct node{
	int x,y,z;
}a[N];
bool cmp(node a,node b){
	return a.x-a.y>b.x-b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int lx=0;lx<=min(n/2,i);lx++){
					for(int ly=0;ly<=min(i-lx,n/2);ly++){
						int lz=i-lx-ly;
						if(lz>n/2||lz<0){
							continue;
						}
						if(lx>0)	f[i][lx][ly]=max(f[i][lx][ly],f[i-1][lx-1][ly]+a[i].x);
						if(ly>0)	f[i][lx][ly]=max(f[i][lx][ly],f[i-1][lx][ly-1]+a[i].y);
						if(lz>0)	f[i][lx][ly]=max(f[i][lx][ly],f[i-1][lx][ly]+a[i].z);
						ans=max(ans,f[i][lx][ly]);
					}
				}
			}
		}
		else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].y;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}