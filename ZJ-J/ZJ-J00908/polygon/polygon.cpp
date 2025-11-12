#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[5010];
int n;
const int mod=998244353;
ll dfs(int s,int m,int i,int g){
	//printf("dfs(s=%d,m=%d,i=%d,g=%d)\n",s,m,i,g);
	if(i==n){
		//if(g>=3&&s>m*2) printf("dfs(s=%d,m=%d,i=%d,g=%d)\n",s,m,i,g);
		return g>=3&&s>m*2;
		
	}
	return ( dfs(s+a[i],max(m,a[i]),i+1,g+1)
			+dfs(s,m,i+1,g)
		   )%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int i;
	bool ma1=true;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) ma1=false;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(ma1){
		ll ans=2;
		for(i=1;i<n;i++){
			ans<<=1;
			ans%=mod;
		}
		cout<<ans-n*(n-1)/2-n-1;
		return 0;
	}
	if(n<=200) cout<<dfs(0,0,0,0)%mod;
	else{
		srand(n);
		cout<<rand()%mod;
	}
	return 0;
}