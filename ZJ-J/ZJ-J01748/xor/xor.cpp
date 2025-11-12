#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
#define forDown(i,a,b) for(int i=(a);i>=(b);--i)
constexpr int N=5e5+10,V=1<<20;using namespace std;
int n,k,A[N],lst[V],pre[N],dp[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	forUp(i,1,n)cin>>A[i];
	forUp(i,1,n)A[i]^=A[i-1];
	memset(lst,-1,sizeof(lst));lst[0]=0;
	forUp(i,1,n){
		int pos=lst[A[i]^k];
		if(pos!=-1)dp[i]=pre[pos]+1;
		pre[i]=max(pre[i-1],dp[i]);
		lst[A[i]]=i;
	}
	cout<<pre[n];
	return 0;
}