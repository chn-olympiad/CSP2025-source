#include<bits/stdc++.h>
using namespace std;
freopen("polygon.in",'r',stdin);
freopen("polygon.out",'w',stdout);
int main(){
	long long n,maxn=0,m=0;
	string x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(maxn<=x[i]){
			maxn=x[i];
		}
	}
	for(int i=1;i<=n-2;i++){
		m+=i;
	}
	cout<<m;
	return 0;
}

