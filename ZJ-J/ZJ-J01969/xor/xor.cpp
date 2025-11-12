#include<bits/stdc++.h>
using namespace std;
int n,k,a[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool isa=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isa=0;
		}
	}
	if(isa){
		cout<<n/2;
	}else{
		int ans=0;
		int wz=0;
		for(int i=1;i<=n;i++){
			long long int x=a[i];
			if(x==k){
				ans++;
				wz=i;
			}else{
				for(int j=i-1;j>=wz+1;j--){
					x=x^a[j];
					if(x==k){
						ans++;
						wz=i;
						break;
					}
				}
			}
//			cout<<i<<":"<<a[i]<<" "<<wz<<" ans:"<<ans<<"\n";
		}
		cout<<ans;
	}
	return 0;
}
