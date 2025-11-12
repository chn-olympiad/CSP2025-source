#include<bits/stdc++.h>
using namespace std;
long long n,a[50000],s,ma = -1,cnt; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;++i){
		cin>>a[i];
		s+=a[i];
		ma = max(ma,a[i]);
	}
	if(n == 3&&ma*2<s){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
