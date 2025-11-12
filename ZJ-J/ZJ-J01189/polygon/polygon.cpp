#include<bits/stdc++.h>
using namespace std;
int n,a[5000001],b[5000001],ans=0;
void f(int x,int y,int z){
	if(y==1){
		if(x+a[z]>2*a[z]){
		ans++;
	}
		return;
	}
	for(int i=z+1;i<=n-y+2;i++){
		f(x+a[z],y-1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	a[0]=0;
	sort(a+1,a+1+n);
	if(a[n]==1){
	for(int i=3;i<=n;i++){
		unsigned long long q=1,s=1;
		for(int j=1;j<=i;j++){
			q*=j;
			q%=998244353;
		}
		for(int k=n;k>n-i;k--){
			s*=k;
			s%=998244353;
		}
		ans+=s/q;
	}
	cout<<ans;
	return 0;
}
	for(int i=3;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
		f(0,i,j);
	}
	}
	cout<<ans;
	return 0;
} 
