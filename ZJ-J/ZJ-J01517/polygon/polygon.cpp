#include<bits/stdc++.h>
using namespace std;
const int MAX=5010;
long long q[MAX],mx,a[MAX],n,ans;
void f(long long k,long long abs,long long m,long long mx){

	if(k==0){
		if(abs>2*mx){
			ans++;
		//	cout<<abs<<" "<<mx<<"\n";
		}	
		return ;
	}
	if(m>n)	return;
	f(k-1,abs+a[m],m+1,max(mx,a[m]));
	f(k,abs,m+1,mx);
	return ;
}
int main(){ 
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=a[i]+q[i-1];
	}
	for(int i=3;i<=n;i++){
		f(i,0,1,a[1]);
	}
	cout<<ans;
	return 0;
}
