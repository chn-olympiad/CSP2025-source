#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<3){
		cout<<0;
		return 0;
	}
	if (n==3){
		if (a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
			return 0;		
		}
		else cout<<0;
		return 0;
	}	
	int ans=0;
	if (n>3){
		int maxx=0;
		int j=2,k=3;
		for (int i=1;i<=j;i++){
			for (;j<=k;j++){
				for (;k<=n;k++){
					if (a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i]){
						ans++;
					}
				}
			}	
		}
	}
	cout<<ans;
	return 0;
}
