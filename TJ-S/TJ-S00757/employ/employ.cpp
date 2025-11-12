#include<bits/stdc++.h>
using namespace std;
long long a=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("enploy.out","w",stdout);
	int n,m,num;
	long long a=1;
	string a1;
	cin>>n>>m>>a1;
	if(m==n){
		for(int i=1;i<=m;i++){
			a=a*i%998244353;
		}
		cout<<a;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		if(b!=0) num++; 
	}
	for(int i=1;i<=m;i++){
		a=a*num;
		num--;
		a=a%998244353;
		if(num==0) break;
	}
	cout<<a;
	return 0;
}
