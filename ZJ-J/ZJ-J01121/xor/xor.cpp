#include <bits/stdc++.h>
using namespace std;
int n,k,s,a[500010],vis[500010],w,dp[1010][1010],ans,t,flag,x;
bool pd(int t,int w){
	for(int i=t;i<=w;i++)
		if(vis[i]) return 0;
	return 1;
}
void gai(int t,int w){
	for(int i=t;i<=w;i++) vis[i]=1;
}
int cal(int t,int w){
	int s=0;
	for(int i=t;i<=w;i++) s=s xor a[i];
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=1000){
		for(int len=1;len<=n;len++)
			for(int t=1;t<=n-len+1;t++){
				w=t+len-1;
				dp[t][w]=dp[t+1][w] xor a[t];
				if(dp[t][w]==k&&pd(t,w)){
					gai(t,w);
					ans++;
				}
			}
		cout<<ans;		
	}
	else{			
		t=1;
		while(t<=n){
			s=0;flag=0;
			while(w<=n){
				w++;
				s=s xor a[w];
				if(s==k){
					flag=1;
					x=w;
					ans++;
					break;
				}
			}		
			if(!flag) t++;
			else t=x,w=x-1;	
		}
		cout<<ans;
	}
	return 0;
}