#include<bits/stdc++.h>

using namespace std;
int n,a[5005],ans;
long long gh;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				gh+=a[k];
			}
			if(gh%998244353>a[j]*2){
				ans++; 
			}
		}
	}
	cout<<ans;
	return 0;
}
