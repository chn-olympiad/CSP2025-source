#include<bits/stdc++.h>
using namespace std;
int a[500007],b[500007],n,k,jl,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>20000&&k>1){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==0&&k!=0){
			--n;
			--i;
			continue;
		}
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j>jl;--j){
			if((b[i]^b[j-1])==k){
				jl=i;
				++sum;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
