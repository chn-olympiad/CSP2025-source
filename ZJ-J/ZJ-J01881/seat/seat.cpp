#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	bool flag=true;
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(flag){
			for(int i=1;i<=n;i++){
				b[i][j]=a[cnt];
				cnt++;
			}	
			flag=false;
		}
		else if(!flag){
			for(int i=n;i>=1;i--){
				b[i][j]=a[cnt];
				cnt++;
			}	
			flag=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}