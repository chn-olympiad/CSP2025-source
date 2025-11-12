#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[100000],b[100000],c[100000];
struct node{
	ll a,b,c,sum;
};
ll dfs(node curr,ll depth=0){
	if(curr.a>n/2||curr.b>n/2||curr.c>n/2) return 0;
	if(depth==n) return curr.sum;
	return max({dfs({curr.a+1,curr.b,curr.c,curr.sum+a[depth]},depth+1),
		        dfs({curr.a,curr.b+1,curr.c,curr.sum+b[depth]},depth+1),
				dfs({curr.a,curr.b,curr.c+1,curr.sum+c[depth]},depth+1)});
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
		cout<<dfs({0,0,0,0})<<'\n';
	}
	return 0;
}
