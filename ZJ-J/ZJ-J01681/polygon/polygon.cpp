#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5050];
const int mod=998244353;
long long choose(long long x){
	if(x<=n/2) x=(n-x);
	long long fenzi=1,fenmu=1;
	for(int i=n;i>x;i--){
		fenzi*=i;
		fenzi%=mod;
	}
	for(int i=1;i<=n-x;i++){
		fenmu*=i;
		fenmu%=mod;
	}
	return fenzi/fenmu;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		maxx=max(maxx,arr[i]);
	}
	if(n==3){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=arr[i];
		}
		if(sum>2*maxx){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=choose(i);
			ans%=mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

