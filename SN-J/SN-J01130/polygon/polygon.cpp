#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,ans,a[5005],b[5005];
int C(int x,int y){
	int nnum=1;
	for(int i=x;i>=x-y+1;i--)
		nnum*=i;
	for(int i=1;i<=y;i++)
		nnum/=i;
	return nnum%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=b[i-1]+a[i];
	if(b[n]==n){
		for(int i=3;i<=n;i++)
			ans+=C(n,i),ans%=mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(b[i]>2*a[i]){
			ans%=mod;
			int tmp=b[i]-2*a[i],tx=i-3;
			for(int head=0,tail=0,num=0;head<=tail;){
				while(num+a[tail+1]<tmp)
					tail++,num+=a[tail+1];
				int l=tail-head;
				for(int i=0;i<=l && i<=tx;i++){
					int ttmp=C(l,min(i,l-i));
					ans+=ttmp,ans%=mod;
				}
				head++;
				num-=a[head];
			}
		}
	}
	cout<<ans;
	return 0;
}
