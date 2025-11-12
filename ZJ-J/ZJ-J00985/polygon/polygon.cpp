#include <bits/stdc++.h>

using namespace std;
unsigned long long ans=0;
const int N=5050;
long long sticks[N];
int dp[ N<<2 ];
int vis[ N<<2 ][N];
int cnt[ N<<2 ];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sticks[i];
		cnt[sticks[i]]++;
	}
	sort(sticks+1,sticks+1+n);
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof dp);
		for(int j=0;j<=(N<<1)-N;j++){
			for(int k=1;k<=i-1;k++){
				if(dp[j]==1&&vis[j+sticks[k]][sticks[k]]<cnt[sticks[k]]){
					dp[j+sticks[k]]=1;
					vis[j+sticks[k]][sticks[k]]++;
					if((j+sticks[k])>(sticks[i]<<1)){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

