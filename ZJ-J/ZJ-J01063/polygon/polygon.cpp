#include<bits/stdc++.h>
using namespace std;
long long  n,ans=0,a[100086];
int jc(int n){
	int b=1;
	for(int i=1;i<=n;i++){
		b*=i;
	}return b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n-i;j++){
			ans+=jc(n-i)/(jc(j)*jc(n-i-j));
		}
	}
	cout<<ans;
	
	return 0;
}
