#include<bits/stdc++.h>
using namespace std;
long long a[5050],maxn,cnt,ans;
int n;
long long camp(int x){
	if(x==1)return x;
	return x*camp(x-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		cnt+=a[i];
	}
	if(n==3){
		if(cnt>maxn*2){
			cout<<1; 
		}else{
			cout<<0;
		}
		return 0;
	}else if(maxn==1){
		long long b=camp(n);
		ans=1;
		for(int i=3;i<n;i++){
			ans+=b/(camp(i)*camp(n-i));
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0; 
}
