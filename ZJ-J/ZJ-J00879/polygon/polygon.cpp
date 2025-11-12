#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244253;
int n,a[5100],sum;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]; if(a[i]!=1) f=0;
	}
	int ans=0;
	if(f){
		ans=1;
		for(int i=4;i<=n;i++){
			ans=ans*2+(i-2)*(i-1)/2;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		int j=pow(2,i-1)-1;
		for(int i1=1;i1<=j;i1++){
			int sum=0,k=1,i2=i1;
			while(i2){
				if(i2%2){
					sum+=a[i-k];
				}
				i2/=2; k++;
			}
			if(sum>a[i]){
				ans++; ans%=MOD;
			}
		}
	}
	cout<<ans;
	return 0;
}






