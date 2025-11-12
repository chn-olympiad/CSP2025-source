#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a1[100005],a2[100005],a3[100005];
void dfs(int x,int y,int z,int o,int sum){
	if(o==n+1){
		ans=max(ans,sum);
		return;
	};
	if(x<n/2){
		dfs(x+1,y,z,o+1,sum+a1[o]);
	}
	if(y<n/2){
		dfs(x,y+1,z,o+1,sum+a2[o]);
	}
	if(z<n/2){
		dfs(x,y,z+1,o+1,sum+a3[o]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a1[i],&a2[i],&a3[i]);
		}
		if(n<=200){
			ans=0;
			dfs(0,0,0,1,0);
		    printf("%d",ans);
		    cout<<"\n";
		}else{
			sort(a1+1,a1+1+n);
			ans=0;
			for(int i=n/2+1;i<=n;i++){
				ans+=a1[i];
			}
			printf("%d",ans);
		    cout<<"\n";
		}
	}
	return 0;
}
