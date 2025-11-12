#include<bits/stdc++.h>
using namespace std;
freopen("xor.in",'r',stdin);
freopen("xor.out",'w',stdout);
int main(){
	long long n,maxn=0;
	string x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(maxn<=x[i]){
			maxn=x[i];
		}
	}
	cout<<maxn;
	return 0;
}
