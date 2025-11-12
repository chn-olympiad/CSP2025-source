#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],fl=1,s,v[100001];
void f(){
	int t=n*(n-1)*(n-2)/6;
	for(int i=4;i<=n;i++){
		s=(s+t)%998244353;
		t=t*(n-i+1)/i;
	}
	cout<<(s+t)%998244353;
	exit(0);
}
void ff(long long t,long long m,long long p,long long l,long long js){
	if(t==js&&p>m*2){
		s=(s+1)%998244353;
		return ;
	} 
	for(int i=l;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			ff(t+1,max(m,a[i]),p+a[i],i+1,js);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=0;
	}
	if(fl){
		f();
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		ff(0,0,0,1,i);
	}
	cout<<s;
	return 0;
}
