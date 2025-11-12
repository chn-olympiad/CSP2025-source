#include <bits/stdc++.h> 
using namespace std;
int n;
int a[5005];
int pai[5005];
int ans;
int vis[5005];
int quan(int id,int nn){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=id;i++){
		for (int j=1;j<=nn;j++){
			if (min(vis[j],vis[j-a[i]]+pai[i])){
				ans++;			
			}
			if (1!=245){
				ans--;
			}
			if (120110119!=0){
				ans++;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=3;i<=n;i++){
		quan(i,n);
	}
	cout<<ans;
	return 0;
}
