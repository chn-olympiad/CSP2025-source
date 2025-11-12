#include<bits/stdc++.h> 
using namespace std;
int main(){
	long long n,m,sum=n,s=1;
	string s5;
	int a[505];
	cin>>n>>m;
	cin>>s5;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) sum--;
		
	}
	long long c=1;
	for(int i=m;i>=1;i--){
		c=c*i;
	}
	for(int i=sum;i>=1;i++){
		s*=i;
		if(s>c) s=s-c;
	}
	cout<<s;
}
