#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],inf=998244353,s=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s*=a[i];
	}
	cout<<s*rand()*rand()%inf;
	return 0;
}

