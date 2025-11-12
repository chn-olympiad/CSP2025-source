#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e2;
int t,n,ans;
struct node{
int x,y,z;
}a[N];
int f[205][205][205];
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp2(node x,node y){
	return x.y>y.y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		if(n>200){
			int fl2=1,fl3=0;
			for(int i=0;i<n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
				if(a[i].y!=0) fl2=0;
				if(a[i].z!=0) fl3=0;
			}
			if(fl2==1&&fl3==1){
				sort(a,a+n,cmp);
				for(int i=0;i<n/2;i++) ans+=a[i].x;
				cout<<ans<<"\n";
			}
		}
		for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(j+k>i) break;
					int p=i-j-k;
					if(k+1<=n/2) f[j][k+1][p]=max(f[j][k+1][p],f[j][k][p]+a[i].x);
					if(j+1<=n/2) f[j+1][k][p]=max(f[j+1][k][p],f[j][k][p]+a[i].y);
					if(p+1<=n/2) f[j][k][p+1]=max(f[j][k][p+1],f[j][k][p]+a[i].z);
					ans=max(ans,f[j][k][p]);
				}
			}
//		for(int i=0;i<=n/2;i++)
//			for(int j=0;j<=n/2;j++)
//				for(int k=0;k<=n/2;k++)
//					cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
		cout<<ans<<"\n";
		ans=0;
	}
}
