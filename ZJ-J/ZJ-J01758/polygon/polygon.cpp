#include<bits/stdc++.h>
using namespace std;
int a[5005];int n;
long long  ans=0;
const long long mod=998244353;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n==3){
			if(a[1]+a[2]>a[3]){
				cout<<1;
				return 0;
			}
		}
		cout<<0;
	}
	else{
		int cmp[5005];
		cmp[0]=0;
		cmp[1]=a[1];
		for(int i=2;i<=n;i++){
			cmp[i]=cmp[i-1]+a[i];
		}
		for(int i=n;i>=1;i--){
			int maxi=a[i]*2;
			for(int j=0;j<=i;j++){
				if(cmp[i]-cmp[j]>maxi){
					cout<<i<<' '<<j<<"!!!\n";
					ans++,ans%=mod;
				}
			}
			for(int j=1;j<i-2;j++){
				
			}
			while(a[i]==maxi/2){
				i--;
			}
			i++;
		}
		cout<<ans;
	}
	return 0;
}