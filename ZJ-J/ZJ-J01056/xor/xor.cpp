#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;	
	}
	if(k==0&&f==0){
		cout<<n/2;
		return 0;
	}
	long long x=0;
	for(int i=1;i<=n;i++){
		x=x^a[i];
		if(x==k){
			s++;
			x=0;
		}
	}
	cout<<s;
	return 0;
}

