#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110000][3],maxn=-1;
long long dp(int macn=0,int l=0,int u=0,int o=0,int p=0){
	if((o-1)==n/2||(p-1)==n/2||(u-1)==n/2)return 0;
	if((u+o+p)==n){
		if(macn>maxn)maxn=macn;
		return macn;
	}
	maxn=max(dp((macn+a[u+o+p+1][1]),1,u+1,o,p),max(dp((macn+a[u+o+p+1][2]),2,u,o+1,p),dp((macn+a[1+u+o+p][3]),3,u,o,p+1)));
	return maxn;
}
int main(){
	freopen("club.in","w",stdin);
	freopen("culb.out","r",stdout);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n;
		maxn=-1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		cout<<dp(0,0,0,0,0)<<endl;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				a[j][k]=0;
			}
		}
	}
	return 0;
} 