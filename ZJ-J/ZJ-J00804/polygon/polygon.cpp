#include<bits/stdc++.h>
using namespace std;
long long n,md=998244353,a[5010],f[5010],b[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans+=b[5001]-b[a[i]];
		ans%=md;
		f[5001]+=b[5001]-b[5000-a[i]];
		f[5001]%=md;
		for(int j=5000;j>=a[i];j--){
			f[j]+=f[j-a[i]];
			f[j]%=md;
		}
		for(int j=1;j<=5001;j++){
			b[j]=b[j-1]+f[j];
			b[j]%=md;
		}
	}
	cout<<ans;
	return 0;
}
