#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long sum=0,maxa=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n] && a[1]==1){
		cout<<((n-2)*(n-1)/2)%N;
		return 0;
	}
	if(sum>maxa*2){
		cout<<1;
	}else cout<<0;
	return 0;
}
