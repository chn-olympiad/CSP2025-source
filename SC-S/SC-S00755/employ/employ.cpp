#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	while(1){
		cout<<1;
	}
}
#if 0
#include<bits/stdc++.h>
using namespace std;
int t,n,a[12][4];
int c[4];
int ans;
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i]==n/2)continue;
		c[i]++;
		dfs(x+1,sum+a[x][i]);
		c[i]--;
	}
}
void solve(){
	cin>>n;
	c[1]=c[2]=c[3]=0;ans=0;
	for(
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	
	cin>>t;
	while(t--)solve();
}
#endif