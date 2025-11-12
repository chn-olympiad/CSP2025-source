#include<bits/stdc++.h>
using namespace std;
int a,b,y[250001];
int l(int a,int b){
	long long sum=1;
	for(int i=a;i>=a-b+1;i--){
		sum*=i;
	}
	sum%=998244353;
	return sum;
}
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	char x[a+1];
	cin>>x;
	for(int i=1;i<=a;i++){
		cin>>y[i];
	}
	cout<<l(a,b);
	return 0;
}
