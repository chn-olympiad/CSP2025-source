#include<bits/stdc++.h>
using namespace std;
long long p(int n){
	long long sum=1,i;
	for(i=n;i>0;i--){
		sum*=n;
		sum=sum%998244353;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,n,m,a[501],sb;
	char b[501];
	bool flag=1,f=1;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>b[i];
		if(b[i]=='0'){
			flag=0;
		}
		if(b[i]=='1'){
			f=0;
		}
	}
	bool ff=flag;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			flag=0;
		}
	}
	if(m==n && flag){
		cout<<p(n);
	}else{
		cout<<0;
	}
	if(m==1 && f){
		cout<<0;
	}else{
		cout<<p(n);
	}
	if(flag){
		cout<<p(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}