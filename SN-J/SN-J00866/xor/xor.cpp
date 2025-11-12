#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int o=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1&&i!=o){
				ans++;
				o=i+1;
			}
		}
		cout<<ans;
	}
	if(k==1){
		for(long long i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
	}
	return 0;
}
