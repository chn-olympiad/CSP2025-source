#include<bits/stdc++.h>
using namespace std;
int n,K,ans1,ans2,a[1005],vis[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int v=0,f=0;
			for(int k=i;k<=j;k++){
				if(vis[k]){
					f=1;
					break;
				}
				v=v^a[k];
			}
			if(f)break;
			if(v==K){
				for(int k=i;k<=j;k++)vis[k]=1;
				ans1++;	
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=n;i>=1;i--){
		for(int j=n;j>=i;j--){
			int v=0,f=0;
			for(int k=j;k<=i;k++){
				if(vis[k]){
					f=1;
					break;
				}
				v=v^a[k];
			}
			if(f)break;
			if(v==K){
				for(int k=i;k<=j;k++)vis[k]=1;
				ans2++;	
			}
		}
	}
	cout<<max(ans1,ans2);
	return 0;
}
