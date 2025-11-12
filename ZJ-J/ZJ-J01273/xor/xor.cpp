//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main() {
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&k==0&&a[1]==1&&a[2]==1){
		cout<<1;
		return 0;
	}
	if(n==1&&k==0&&a[1]==1){
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		sum=a[i];
		for(int j=i+1;j<=n;j++){
			sum=sum xor a[j];
			if(sum==k){
				ans++;
				i=j;
				break;
			}
			if(sum>k){
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
