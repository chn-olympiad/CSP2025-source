#include <bits/stdc++.h>
using namespace std;
const int mm=998244353;
long long n,a[5010],maxn=-1,cnt;
long long cmp1(long long x){
	long long m=1;
	for(int i=x;i>=1;i--){
		m=m*i%mm;
	}
	return m;
}
long long cmp2(long long y){
	long long h=n;
	long long p=1,v=1;
	for(int j=1;j<=y;j++){
		p=p*h%mm;
		v=v*j%mm;
		h--;
	}
	return p/v;
}
void solve1(){
	if(n<3){
		cout<<0;
	}else{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}
void solve2(){
	for(int k=3;k<=n;k++){
		cnt+=cmp2(k);
		cnt=cnt%mm;
	}
	cout<<cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		solve1();
		return 0;
	}
	if(maxn==1){
		solve2();
		return 0;
	}
	return 0;
}
