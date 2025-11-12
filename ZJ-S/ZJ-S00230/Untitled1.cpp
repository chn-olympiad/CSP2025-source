#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,f[40000];
	cin>>n;
	f[1]=1,f[2]=1;
	for(int i=3;i<=n;i++) f[i]+=f[i-1]+f[i-2]; 
	cout<<(1ULL<<64-1);
}

