#include<bits/stdc++.h>
using namespace std;
long long n,a[5010];
long long pl(int x){
	if(x==1) return 1;
	else{
		return x+pl(x-1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		long long sum=0,maxx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		maxx*=2;
		if(sum>maxx) cout<<1;
		else cout<<0;
		return 0;
	}
	long long maxxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
	}
	long long cnt1=0;
	if(maxxx==1){
		for(int i=n;i>=3;i--){
			for(int j=n-i+1;j>=1;j--){
				cnt1+=pl(j);
			}
		}
		cout<<cnt1%998244353;
		return 0;
	}
	long long cnt=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j+i<=n;j++){
			long long sum=0,maxx=-1;
			for(int z=j;z<=j+i;z++){
				sum+=a[z]; 
				maxx=max(maxx,a[z]);
			}
			maxx*=2;
			if(sum>maxx){
				cout<<j<<' '<<j+i<<endl;
				cnt++;
			}
		}
	}
	cout<<cnt%998244353;
	return 0;
}
