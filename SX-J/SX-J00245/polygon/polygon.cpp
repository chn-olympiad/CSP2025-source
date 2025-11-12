#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int vis[5001];
int ans=0;
void bfs(int nn,int n2){
	if(nn=n2){
		ans++;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		for(int j=1;j<=n;j++){
			bfs(nn+1,n2);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[1]*2&&a[1]+a[2]+a[3]>a[2]*2&&a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
	     	fclose(stdin);
			fclose(stdout);
			return 0;
		}else {
			cout<<0;
	     	fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	for(int i=n;i<=3;i++){
		bfs(1,i);
	}
	cout<<ans%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}