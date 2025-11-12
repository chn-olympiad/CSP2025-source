#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long s,ss;
int zh(int x){
	long long sum=1;
	for(int i=x+1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	for(int i=2;i<=n-x;i++){
		sum/=i;
		sum%=998244353;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		for(int i=1;i<=n;i++) s+=a[i];
		sort(a+1,a+n+1);
		if(a[n]*2<s) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		s+=zh(i);
		s%=998244353;
	}
	cout<<s;
	return 0;
}
