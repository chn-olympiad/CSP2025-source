#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod=998244353;
int n;
ll y[5005][5005];
int a[5005];
int x1=0;
int xx=0;
void yh(){
	for(int i=1;i<=n+1;i++){
		y[i][1]=y[i][i]=1;
		for(int j=2;j<i;j++){
			y[i][j]=y[i-1][j]+y[i-1][j-1];
//			cout<<y[i][j]<<" ";
		}
//		cout<<"\n";
	}
}
void f(int x,int l,ll s){
	x++;
	if(x>n){
		if(l*2<s){
//			cout<<x<<"-"<<l<<"-"<<s<<"\n";
			xx++;
			xx%=mod;
		}
		return;
	}
	f(x,l,s);
	f(x,a[x],s+a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) x1++;
	}
	if(x1==n){
		yh();
		ll s=0;
		for(int i=3;i<=n;i++){
			s+=y[n+1][i+1];
			s%=mod;
		}
		cout<<s%mod;
		return 0;
	}
	sort(a+1,a+1+n);
	f(0,0,0);
	cout<<xx%mod;
	return 0;
}
