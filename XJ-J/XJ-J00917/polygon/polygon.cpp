#include<bits/stdc++.h>
using namespace std;
int modd=998244353;
int p(int x,int y){
	return x*(x-1)/y;
}
int main(){
	int n,a[5010],ans=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=5;i<n;i++){
		ans+=p(n,i);
	}
	cout<<ans%modd;
	return 0;
}

