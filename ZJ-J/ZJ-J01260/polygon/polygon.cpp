#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long sum;
int n;
int a[5010];
int rp=INT_MAX;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	//int maxx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			int ans=0,maxx=INT_MIN;
			for(int k=j;k<=j+i;k++){
				ans+=a[k];
				maxx=max(maxx,a[k]);
			}if(ans>maxx*2) sum++;
		}
	}
	cout<<sum%mod;
	return 0;
}
