#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int z;
	int b;
}a[4][100005],vis[100005];
bool cmp(node x,node y){
	return x.z>y.z;
}
void j(){
}
void solve(){
	cin>>n;
	int x=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[1][i].z>>a[2][i].z>>a[3][i].z;
		a[1][i].b=a[2][i].b=a[3][i].b=i;
	}
	for(int i=1;i<=3;i++){
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	if(a[2][1].z==0&&a[3][1].z==0){
		int ans=0;
		for(int i=1;i<=x;i++){
			ans+=a[1][i].z;
		}
		cout<<ans;
		return;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[1][i].z<<' '<<a[2][i].z<<' '<<a[3][i].z<<'\n';
//	}
	int i1=1,i2=1,i3=1;
	int cnt=0;
	int ans=0;
	while(cnt<=n){
		int x1=0,x2=0,x3=0;
		if(vis[a[1][i1].b].b==0){
			x1=max(x1,a[1][i1].z);
		}else{
			x1=max(x1,a[1][i1].z-a[vis[a[1][i1].b].b][vis[a[1][i1].b].z].z);
		}
		if(vis[a[2][i2].b].b==0){
			x2=max(x2,a[2][i2].z);
		}else{
			x2=max(x2,a[2][i2].z-a[vis[a[2][i2].b].b][vis[a[2][i2].b].z].z);
		}
		if(vis[a[3][i3].b].b==0){
			x3=max(x3,a[3][i3].z);
		}else{
			x3=max(x3,a[3][i3].z-a[vis[a[3][i3].b].b][vis[a[3][i3].b].z].z);
		}
		if(x1>x2&&x1>x3){
			if(vis[a[1][i1].b].b==0){
				cnt++;
			}
			ans+=x1;
			vis[a[1][i1].b].b=1;
			vis[a[1][i1].b].z=i1;
			i1++;
		}else if(x2>x1&&x2>x3){
			if(vis[a[2][i2].b].b==0){
				cnt++;
			}
			ans+=x2;
			vis[a[2][i2].b].b=2;
			vis[a[2][i2].b].z=i2;
			i2++;
		}else{
			if(vis[a[3][i3].b].b==0){
				cnt++;
			}
			ans+=x3;
			vis[a[3][i3].b].b=3;
			vis[a[3][i3].b].z=i3;
			i3++;
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		vis[i].b=vis[i].z=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0; 
}