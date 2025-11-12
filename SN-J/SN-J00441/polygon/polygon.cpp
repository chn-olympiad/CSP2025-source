#include<bits/stdc++.h>
using namespace std;
int n,x,a[5000],b[5000];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(b[i]-b[j-1]>(a[i]*2)){
				ans++;
			}
			ans%=998244353;
		}
	}
	cout<<ans;
}

