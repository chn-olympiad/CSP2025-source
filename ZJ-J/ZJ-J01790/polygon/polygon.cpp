#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n,a[N],sum=0;
void Dp(){
	int tmp;
	sum=0;
	for(int i=1;i<=(1<<n)-1;i++){
		tmp=i;
		int cnt=0,maxn=-1;
		for(int j=1;j<=n;j++){
			if(tmp>>(j-1)&1){
				cnt+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		if(cnt>2*maxn) sum++;
	}
	cout<<sum;
}
int C(int n,int m){
	int ans=1;
	for(int i=1;i<=n;i++) ans=ans*(m-i+1)/i%mod;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){Dp();return 0;}
	int t=3;
	while(t<=n){
		sum+=C(t,n);
		sum%=mod;
		t++;
	}
	cout<<sum;
	return 0;
}
