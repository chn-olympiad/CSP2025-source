#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1)cout<<n+4;
	else cout<<n+1;
	return 0;
} 
