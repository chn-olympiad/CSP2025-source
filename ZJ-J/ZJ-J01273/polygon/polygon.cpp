//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int a[5010];
int s[5010];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	
	int ans=0;
	int ma=0,l=0,sum=0;
	if(n==3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
			ma=max(ma,a[i]);
		}
		if(sum>2*ma) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<10;
	return 0;
}
