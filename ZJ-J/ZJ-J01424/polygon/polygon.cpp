#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<1<<n;i++){
		int k=1,s=0,x=0;
		for(int j=i;j!=0;j/=2){
			if(j%2==1){
				s+=a[k];
				x=k;
			}
			k++;
		}
		if(a[x]*2<s) ans++;
	}
	cout<<ans%998224353;
	return 0;
	//#Shang4Shan3Ruo6Shui4
}
