#include<bits/stdc++.h>
using namespace std;
int n,ans;
int as[5005],dp[5005][5005];
void ds(int x,int y){
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>as[i];
	}
	for(int bian=3;bian<=n;bian++){
		for(int i=1;i<=n-bian+1;i++){
			for(int j=1;j<=n;j++){
				dp[i][j];
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout); 
}
