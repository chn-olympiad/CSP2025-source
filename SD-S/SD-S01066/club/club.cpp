#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,up,f[220000][4];
struct node{
	ll x,y,z,max;
}a[220000];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.max>b.max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		bool f1=0,f2=0,f3=0;
		cin>>n;
		up=n/2;
		ll idx=0,idy=0,idz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].max=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].x) f1=1;
			if(a[i].y) f2=1;
			if(a[i].z) f3=1;
			if(a[i].max==a[i].x) idx++;
			if(a[i].max==a[i].y) idy++;
			if(a[i].max==a[i].z) idz++;
			
		}
		if(!f2&&f2==f3){
			ll ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=up;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(idx<=up&&idy<=up&&idz<=up){
			ll ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i].max;
			}
			cout<<ans<<"\n";
			continue;
		}else{
			ll cntx=0,cnty=0,cntz=0;
			f[1][1]=a[1].x;f[1][2]=a[1].y;f[1][3]=a[1].z;
			for(int i=2;i<=n;i++){
				if(cntx<up){
					f[i][1]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i].x;
					cntx++;
				}else if(cntx>=up) f[i][1]=-1e9;
				if(cnty<up){
					f[i][2]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i].y;
					cnty++;
				}else if(cnty>=up) f[i][2]=-1e9;
				if(cntz<up){
					f[i][3]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i].z;
					cntz++;
				}else if(cntz>=up) f[i][3]=-1e9;
			}
			cout<<max(f[n][1],max(f[n][2],f[n][3]))<<"\n";
			continue;
		}
	}
	return 0;
}
