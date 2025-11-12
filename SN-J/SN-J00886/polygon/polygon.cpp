#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,a[5005],b[5005];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			long long y=1;
			for(int j=1;j<=i;j++){
				y=y*(n-j+1);
				y=(y/j)%N;
			}
			ans=(ans+y)%N;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) ans=1;
	}
	
	cout<<ans;
	return 0;
}

