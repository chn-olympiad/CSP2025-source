#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum=0,ans=0,s=0;
void fl(int x,int k){
	for(int i=x;i<=n;i++){
		if(k-a[i]>0){
			ans++;
			ans%=998244353;
			if(k>a[i]) fl(x+1,k-a[i]);
		}
		else return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(1+a,1+a+n);
	sum=a[1]+a[2];
	for(int i=3;i<=n;i++){
		sum+=a[i];
		int k=sum-2*a[i];
		if(k<=0) continue;
		ans++;
		s++;
		if(s==2) ans--;
		fl(1,k);
	}
	cout<<ans%998244353;
	return 0;
}
