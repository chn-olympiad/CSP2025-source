#include<bits/stdc++.h>
using namespace std;
long long C(int x,int y){
	long long d=1,f=1;
	for(int i=x;i>=x-y+1;i--) d*=i,d%=998244353;
	for(int i=1;i<=y;i++) f*=i,f%=998244353;
	return d/f;
}
long long a[100005],k=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) k=0;
	}
	if(k==1){
		long long cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=C(n,i);
			cnt%=998244353;
		}
		cout<<cnt<<"\n";
	}else if(n==3){
		sort(a+1,a+3+1);
		if(a[1]+a[2]>a[3])cout<<"1";
		else cout<<"0";
	}
	return 0;
}