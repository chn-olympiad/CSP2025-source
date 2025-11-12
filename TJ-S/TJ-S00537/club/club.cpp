#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N];
int dfs(int x,int y,int z,int i){
	if(i==n+1)return 0;
	int ans=-1,p=0;
	if(x<n/2){
		p=a[i]+dfs(x+1,y,z,i+1);
		ans=max(ans,p);
	}
	if(y<n/2){
		p=b[i]+dfs(x,y+1,z,i+1);
		ans=max(ans,p);
	}
	if(z<n/2){
		p=c[i]+dfs(x,y,z+1,i+1);
		ans=max(ans,p);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int gb=0,gc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			gb+=b[i];
			gc+=c[i];
		}
		if(gb==0&&gc==0){
			sort(a+1,a+n+1);
			int res=0;
			for(int i=n;i>n/2;i--){
				res+=a[i];
			}
			cout<<res;
			continue;
		}
		int u=dfs(0,0,0,1);
		cout<<u<<endl;
	}
	return 0;
}
