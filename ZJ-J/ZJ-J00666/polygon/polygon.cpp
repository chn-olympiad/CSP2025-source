#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5005],ans,ma;
const int mod=998244353;
bool cmp(int x,int y){
	return x>y;
}
int f(int x,int y,int z){
	if(y==0||x>=n)return 0;
	int m=0;
	for(int i=x+1;i<n;i++){
		if(z+a[i]>ma)m=(m+1)%mod;
		m=(m+f(i,y-1,z+a[i]))%mod;
	}
	return m;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		ma=a[i],ans=(ans+f(i,n-i-1,0))%mod;
	}
	cout<<ans;
	return 0;
}
