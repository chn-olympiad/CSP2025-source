#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long njc=1;
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
long long jc(int n){
	long long s=1;
	for(int i=2;i<=n;i++){
		s*=i;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,s=0,m=0,t=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(s>2*a[1]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}else if(s==n){
		njc=jc(n);
		for(int i=3;i<n;i++){
			t=jc(n-i)*jc(i);
			m+=njc/t;
			m%=998244353;
		}
		cout<<m+1;
	}
	return 0;
}
