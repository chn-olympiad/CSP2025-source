#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],dp[105][105],f,b;
bool cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=1;
	b=a[1];
	sort(a+1,a+1+n*m,cnt);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				dp[i][j]=(i-1)*n+j;
				if(a[dp[i][j]]==b)cout<<i<<" "<<j;
			}else{
				dp[i][n-j+1]=(i-1)*n+j;
				if(a[dp[i][n-j+1]]==b)cout<<i<<" "<<n-j+1;
			}
		}
	}
	return 0;
}
