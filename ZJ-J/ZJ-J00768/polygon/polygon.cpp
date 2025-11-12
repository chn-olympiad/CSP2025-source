#include<bits/stdc++.h>
using namespace std;
int n,a[5001],z=998244353,b[5001],v[5001];
long long s;
long long A(int p,int q){
	long long S=1;
	for(int i=q;i>q-p;i--)S*=i,S%=z;
	return S;
}
long long C(int x,int y){
	return A(x,y)/A(x,x)%z;
}
void x(int d,int e,int f){
	if(!d){
		int mx=0,ans=0;
		for(int i=0;i<e;i++)mx=max(mx,b[i]),ans+=b[i];
		if(ans>2*mx)s++,s%=z;
		return;
	}
	for(int i=f;i<n;i++){
		if(v[i])continue;
		v[i]=1,b[e-d]=a[i],x(d-1,e,i+1),v[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n>20){
	    for(int i=3;i<=n;i++)s+=C(i,n),s%=z;
	    cout<<s,exit(0);
	}
	for(int i=3;i<=n;i++)x(i,i,0),memset(b,0,sizeof b),memset(v,0,sizeof v);
	cout<<s%z;
}
