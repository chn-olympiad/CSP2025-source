#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],q[500005],dp[500005],book[500005];
int sol(int x){
	if(book[x]) return dp[x]; 
	if(x>n) return 0;
	int d=0;
	for(int i=x;i<=n;i++){
		if((q[i]^q[x-1])==k){
			d=max(d,sol(i+1)+1);
		}else{
			d=max(d,sol(i+1));
		} 
	}
	book[x]=1;
	return dp[x]=d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]^a[i];
	}
		cout<<sol(1);
	return 0;
} 
