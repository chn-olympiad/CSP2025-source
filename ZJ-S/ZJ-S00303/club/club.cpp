#include <iostream>
#include <algorithm>
using namespace std;
int t,n,us[100010][4],a[100010];
int ans;
void dfs(int l,int sum,int i1,int i2,int i3){
	if(l>n){
		ans=max(ans,sum);
	}
	for(int i=l;i<=n;i++){
		if(i1<n/2&&us[i][1]){
			dfs(i+1,sum+us[i][1],i1+1,i2,i3);
		}
		if(i2<n/2&&us[i][2]){
			dfs(i+1,sum+us[i][2],i1,i2+1,i3);
		}
		if(i3<n/2&&us[i][3]){
			dfs(i+1,sum+us[i][3],i1,i2,i3+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>us[i][1]>>us[i][2]>>us[i][3];
			f&=(us[i][2]==0&&us[i][3]==0);
		}
		if(f){
			for(int i=1;i<=n;i++){
				a[i]=us[i][1];
			}
			sort(a+1,a+1+n);
			for(int i=n;i>n/2;i--){
				ans+=a[i];
			}
		}else{
			dfs(1,0,0,0,0);
		}
		cout<<ans;
		if(t!=0){
			cout<<'\n';
		}
	}
	return 0;
}
