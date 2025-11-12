#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],x[N],dp[N];
vector<int> v[1048580];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,k;
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		v[x[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int y=x[i]^k,l=0,r=v[y].size()-1,mid;
		if(r<0)continue;
		while(l<r){
			mid=l+r+1>>1;
			if(v[y][mid]>=i)r=mid-1;
			else l=mid;
		}
		if(v[y][l]<i)dp[i]=max(dp[i],dp[v[y][l]]+1);
	}
	cout<<dp[n];
	return 0;
}
