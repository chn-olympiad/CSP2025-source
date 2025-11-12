#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
long long ans;
int n,t,a[N][4],ll[4];
void dfs(int now,int l,long long sum){
	if(now==n){
		ans=max(ans,sum);
		return;
	}
	int lll=n/2;
	for(int i=1;i<=3;i++){
		if(ll[i]+1<=lll){
			ll[i]++;
			dfs(now+1,i,sum+a[now+1][i]);
			ll[i]--;
		}
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int opp=1;opp<=t;opp++){
		cin>>n;
		ans=0;ll[1]=0;ll[2]=0;ll[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(0,0,0); 
		cout<<ans<<endl;
	}
	return 0;
}

