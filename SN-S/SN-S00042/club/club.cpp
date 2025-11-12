#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],ans;
void dfs(int x,int u,int v,int k,int f){
	if(u>n/2||v>n/2||k>n/2)return;
	if(x>n){
		ans=max(ans,f);
		return;
	}
	dfs(x+1,u+1,v,k,f+a[x]);
	dfs(x+1,u,v+1,k,f+b[x]);
	dfs(x+1,u,v,k+1,f+c[x]);
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=30){
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		else{
			ans=0;
			int g=0,h=0;
			for(int i=1;i<=n;i++){
				g=max(g,b[i]);
				h=max(h,b[i]);
			}
			if(g==0&&h==0){
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i];
				}
			}
			else{
				ans=0;
				dfs(1,0,0,0,0);
				//cout<<ans<<"\n";
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
