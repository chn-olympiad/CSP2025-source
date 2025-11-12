#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5001];
bool isshape(int x,int y,int z){
	if(x+y+z>2*max(x,max(y,z))) return 1;
	return 0;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int c=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) c=1;
	}if(c==1){
		long long sum=0;
		for(int i=1;i<n;i++){
			for(int j=1+i;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(isshape(a[i],a[j],a[k])) sum++;
				}
			}
		}cout<<sum;
	}else{
		long long ans=1;
		for(int i=1;i<=n;i++) ans=(ans*2)%mod;
		ans=(ans-1-n-(n*n-n)/2+mod)%mod;
		cout<<ans;
	}return 0;
}
