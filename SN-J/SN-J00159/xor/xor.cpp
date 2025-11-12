#include<bits/stdc++.h>
using namespace std;
long long n,k,a,ans=0,jld=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==k){
			ans++;
			jld=0;
			continue;
		}
		jld=(jld ^ a);
		if(jld==k){
			ans++;
			jld=0;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
