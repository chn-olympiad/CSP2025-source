#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[100000]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long cnt=a[1];
	long long ans=1;
	sort(a+1,a+n*m+1,cmp);
	long long vis[100][100];
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				vis[i][j]=a[ans];
				ans++;
			}
		}else{
			for(int j=m;j>=1;j--){
				vis[i][j]=a[ans];
				ans++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=0;j--){
				if(vis[i][j]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
