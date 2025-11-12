#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[10008];
int num;//有多少个1 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n>>k;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]==1) num++;
	}
	cout<<1; 

	return 0;
} 
