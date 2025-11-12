#include<bits/stdc++.h>
using namespace std;
long long n;
int a[5001];
bool b[5001];
int s(int x,long long ans,int y,int t){
	int mod=998244353;
	for(;y<=n;y++){
		if(!b[y]){
			if(x==1){
				if(t>a[y]){
					ans++;
				}
				continue;
			}
			b[y]=1;
			ans=(ans+s(x-1,0,y+1,t+a[y])%mod)%mod;
			b[y]=0;
		}
	}
	return ans;
}
int main(){
	long long sum=0,mod=998244353;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		sum=(sum+s(i,0,1,0)%mod)%mod;
	}
	cout<<sum;
	return 0;
}

