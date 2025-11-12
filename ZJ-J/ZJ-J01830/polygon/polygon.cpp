#include<bits/stdc++.h>
using namespace std;
int a[21],n,b[21],ans,ans2=1,k,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20){
		for(int i=1;i<=n;i++){
			ans2*=2;
			ans2%=998244353;
		}
		ans2+=998244353;
		ans2-=1;
		ans2-=n;
		ans2-=(n*(n-1)/2);
		ans2%=998244353;
		cout<<ans2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<(1<<n);i++){
		k=0;
		sum=0;
		memset(b,0,sizeof(b));
		for(int j=0;(1<<j)<=i;j++){
			if((1<<j)&i){
				k++;
				b[21-k]=a[j+1];
				sum+=b[21-k];
			}
		}
		if(b[21-k]<sum-b[21-k]&&k>=3){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
