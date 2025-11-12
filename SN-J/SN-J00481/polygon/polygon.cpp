#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int INT=998244353;
int n;
int a[N];
int maxx[N];
long long ans,tmp=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx[i-1]){
			maxx[i]=a[i];
		}
	}
	if(maxx[n]=1){
		for(int i=3;i<=n;i++){
			for(int j=0;j<n-i;j++){
				tmp*=(n-j);
				tmp%INT;
			}
			ans+=tmp;
			tmp=1;
		}
		cout<<ans;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>maxx[3]*2){
			cout<<1;	
		}else{
			cout<<0;
		}
		return 0;
	}
}
