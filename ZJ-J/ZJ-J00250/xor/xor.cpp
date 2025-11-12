#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+4;
ll n,m,a[maxn],x[maxn],dp[maxn],maxx[maxn],ans,p[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	dp[0]=maxx[0]=0;
	for(int i=1;i<=n;i++){
	  cin>>a[i];
	  x[i]=x[i-1]^a[i];
	  p[x[i]]=i;
	  int h=m^x[i];
	  int g=p[h]+1;
	  if(g>1)
	    dp[i]=maxx[g-1]+1;
	  else{
	    dp[i]=0;
	    if(x[i]==m)
	      dp[i]=1;
	  }
	  maxx[i]=max(maxx[i-1],dp[i]);
	}
	for(int i=1;i<=n;i++)
	  ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
