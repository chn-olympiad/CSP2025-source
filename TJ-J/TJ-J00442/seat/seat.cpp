#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int vis[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int ans=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				vis[i][j]=a[ans];
				ans++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				vis[i][j]=a[ans];
				ans++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(vis[i][j]==r){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
