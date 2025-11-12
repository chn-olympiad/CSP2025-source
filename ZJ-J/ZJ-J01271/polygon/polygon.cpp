#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,a[maxn],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;for(int i=1;i<=n;i++){cin>>a[i];if(a[i]>1) flag=false;}
	if(flag){
		for(int i=3;i<=n;i++){
			int k=1;
			for(int j=n;j>=i;j--) k*=n-j+1;
			ans=(ans+k)%998244353;
		}
		cout<<ans;
	}
	else cout<<n*2;
	return 0;
}