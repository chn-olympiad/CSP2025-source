#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],b[500005],x,p,l,r,mid;
vector<int> t[2000005];
int xz(int x,int f){
	if(t[x][0]>=f){
		return t[x][0];
	}
	l=0;
	r=t[x].size()-1;
	while(l+1<r){
		mid=(l+r)/2;
		if(t[x][mid]>=f){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return t[x][r];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		t[b[i]].push_back(i);
	}
	for(int i=n;i>=1;i--){
		dp[i]=dp[i+1];
		x=b[i-1]^k;	
		if(t[x].size()!=0&&t[x][t[x].size()-1]>=i){
			p=xz(x,i);
			dp[i]=max(dp[i],dp[p+1]+1);
		}
	}
	cout<<dp[1];
	return 0;
}
