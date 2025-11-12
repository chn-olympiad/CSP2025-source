#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005]={0};
int max_a=0,ans_a=0;
int ans=0,ans_s=ans;
signed main(){
	
	freopen("playgon.in","r",stdin);
	freopen("playgon.out","w",stdin);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			max_a=a[j];
			ans_a=a[i]+a[j];
			for(int k=i+1;k<j;k++){
				if(max_a*2<ans_a){
					ans=(ans%998244353+j%998244353-k%998244353)%998244353;
					break;
				}
				ans_a=ans_a+a[k];
			}
		}
	}
	cout<<ans;
	return 0;
} 
