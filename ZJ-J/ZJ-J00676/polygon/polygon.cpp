#include<bits/stdc++.h>
using namespace std;
const int mod=998224353;
const int N=5010;
long long a[N],f[N],l[N];
long long n,ans=0;
int find(long long x){
	int L=0,R=n;
	while(L+1<R){
		int mid=(L+R)/2;
		if(a[mid]>=x)R=mid;
		else L=mid;
	}
	return R;
}
long long qpow(long long a,long long b){
	long long sum=1;
	while(b!=0){
		if(b%2==0){
			b=b/2;
			a=a*a%mod;
		}
		else{
			sum=(sum*a)%mod;
			b-=1;
		}
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1){
		ans=qpow((long long)2,n);
		ans=ans-1-n-(n*(n-1))/2;
		ans=(ans+mod)%mod;
		cout<<ans;
		return 0;
	}
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(f[i-1]*2)%mod;
	}
	for(int i=n;i>=1;i--){
		f[i]=(f[i]+f[i+1])%mod;
		if(a[i]==a[i+1]){
			l[i]+=l[i+1];
		}
		l[i]++;
	}
	for(int i=3;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			long long x=a[i]-a[j];
			int k=find(x);
			if(k>=j)break;
			if(a[k]+a[j]==a[i]){
				ans=(ans+f[k]-l[k]-f[j])%mod;
			}
			else{
				ans=(ans+f[k]-f[j])%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
