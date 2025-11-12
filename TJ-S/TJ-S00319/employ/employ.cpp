#include<bits/stdc++.h>;
using namespace std;
long long m,n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	if(m==n) cout<<1;
	else if(m==1)	cout<<n*n;
	return 0;
}
