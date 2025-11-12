#include<bits/stdc++.h>
using namespace std;
int a[10010];
long long judge(int n,int i){
	long long ret=1;
	int m=n-i;
	for(int j=i;j<=n;j++){
		ret*=(j-2);
		if(m!=0){
			ret/=m;
			m--;	
		}
		ret%=998244353;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
		long long ret=0;
		for(int i=3;i<=n;i++){
			ret+=judge(n,i);
			ret%=998244353;
		}
		cout<<ret;
	return 0;
}


