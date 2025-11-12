#include<bits/stdc++.h>
using namespace std;
int a[5005],sum[5005];
const long long mod=998244353;
long long cnt=0;
int n;
bool check(int m,int p){
	int i=0,sum=0;
	while(m!=0){
		i++;
		if(m%2==1) sum+=a[i];
		m/=2;
	}
	return sum>p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;i++){
		if(sum[i]<=a[i]*2) continue;
		for(int j=0;j<(1<<(i-1));j++){
			if(check(j,a[i])) cnt++;
		}
		cnt%=mod;
	}
	cout<<cnt;
	return 0;
}
