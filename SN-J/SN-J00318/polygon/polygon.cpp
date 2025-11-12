#include<bits/stdc++.h>
using namespace std;
int n,a[5005]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n-1;j++){
			int h=a[i]+a[j];
			for(int k=j+1;k<n;k++){
				if(a[k]>=h) break;
				ans++;
			}
			//cout << a[i] <<  " "  << a[j] << " "<< "\n";//debug
			ans=ans%998244353;
		}
	}
	cout << ans;
	return 0;
}
