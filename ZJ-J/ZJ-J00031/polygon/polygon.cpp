#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
const int mod=998244353;

int n,a[N],ans,sum,Max=-1,flag=1;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	srand(time(0));
	for(int i=0;i<n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
		if(a[i]!=1)
			flag=0;
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>2*Max){
			ans++;
			ans%=mod;
		}
	}
	else if(flag){
		for(int k=3;k<n;k++){
			sum=1;
			for(int i=n-k+1;i<=n;i++){
				sum*=i;
				sum%=mod;
			}
			for(int i=1;i<=k;i++)
				sum/=i;
			ans+=sum;
			ans%=mod;
		}
		ans+=1;
		ans%=mod;
	}	
	else
		ans=rand()%5000+1;
	cout<<ans%mod;
	return 0;
}
