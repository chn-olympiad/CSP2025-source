#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,k,f[MAXN],ans=0;
bool dp[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		f[i]=k^f[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int flag=1;
			for(int a=j;a<=i;a++){
				if(dp[a]==1){
					flag=0;	
					break;
				} 	
			} 
			if(!flag)continue;
			int xorn=f[i]^f[j];
			if(i==j) xorn=f[i]^f[i-1];
			if(xorn==k){
				ans++;
				for(int a=j+1;a<=i;a++){
					dp[a]=1;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}