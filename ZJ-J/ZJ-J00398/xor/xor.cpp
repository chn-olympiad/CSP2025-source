#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("xor.in");
	ofstream cout("xor.out");
	long long n,k;
	cin>>n>>k;
	vector<int>xl(n+1);
	for(long long i=1;i<=n;i++){
		cin>>xl[i];
	}
	long long p=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long flg=xl[i];
			for(long long x=i+1;x<=j;x++){
				flg=flg^xl[x];
			}
			if(flg==k){
				p++;
			}
		}
	}
	cout<<p<<endl;
}
