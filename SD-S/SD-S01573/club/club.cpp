//20pts
#include<iostream>
using namespace std;
int a[100005],b[100005],c[100005],n,ans=0;
void dfs(int x,int y,int z,int k){
	if(x+y+z==n){
		ans=max(ans,k);return;
	}
	if(x+1<=n/2)dfs(x+1,y,z,k+a[x+y+z+1]);
	if(y+1<=n/2)dfs(x,y+1,z,k+b[x+y+z+1]);
	if(z+1<=n/2)dfs(x,y,z+1,k+c[x+y+z+1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 


