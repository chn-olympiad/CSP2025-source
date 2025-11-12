#include<bits/stdc++.h>
using namespace std;
int a[5010],s[5010],n,ans=0,sum=0;
int jia(int nn){
	int ss;
	for(int j=0;j<nn;j++){
		ss+=a[j];
	}
	return ss;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	s[1]=a[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	return 0;
}
