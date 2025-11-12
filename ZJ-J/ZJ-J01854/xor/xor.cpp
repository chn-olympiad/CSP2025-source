#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],s[600000],s1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1)break;
		if(i==n){
			if(k==1)
				cout<<n;
			if(k==0)
			cout<<n/2;
			if(k>1)
				cout<<0;
			return 0;
		}
	}
	int a1=0,max=0,m1=1;
	for(int i=1;i<=n;i++){
		if(a[i]>1)break;
		if(a[i]==1)a1++;
		if(i==n){
			if(k==1)
				cout<<a1;
			if(k==0)
			cout<<a1+(n-a1)/2;
			if(k>1)
				cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(max<a[i])max=a[i];
	}
	while(max>1){
		max/=2;
		m1++;
	}
	while(m1>=1){
		max*=2;
		m1--;
	}
	if(k>max){
		cout<<0;
		return 0;
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	cout<<(n/2)%998244353<<endl;
	return 0;
}
