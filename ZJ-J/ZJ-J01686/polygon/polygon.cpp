#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[100005],sum,vis[100005];
long long C(int a,int b){
	for(int i=1; i<=a; i++)vis[b-i+1]=b-i+1;
	for(int i=1; i<=a; i++){
		for(int j=1; j<=a; j++){
			if(vis[b-j+1]%i==0){
				vis[b-j+1]/=i;
				break;
			}
		}
	}long long g=1;
	for(int i=1; i<=a; i++)g=(g*vis[b-i+1])%998244353;
	return g;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	if(n<=20){
		for(int i=0; i<(1<<n); i++){
		long long r=i,k=0,mx=-2e9,sum=0,t=0;
			while(r){
				k++;
				if(r%2){
					t++;
					mx=max(mx,a[k]);
					sum+=a[k];
				}r/=2;
			}if(sum>mx*2&&t>=3)ans=(ans+1)%998244353;
		}cout<<ans;
	}else{
		for(int i=3; i<=n; i++)sum=(sum+C(i,n))%998244353;
		cout<<sum;
	}return 0;
}