#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005],mx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int ant=0;
			for(int k=j;k<=i+j-1;k++){
				ant+=a[k];
			}
			if(ant>mx*2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
