#include<bits/stdc++.h>
using namespace std;
long long c(int n,int m){
	long long s=1;
	for(int i=1;i<=m;i++) s=s*n--/i,s%=998244353;
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a) cout<<1;
		else cout<<0;
	}
	else{
		int a[5010];
		long long cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=3;i<=n;i++){
			cnt=(cnt+c(n,i))%998244353;
		}
		cout<<cnt;
	}
	return 0;
}