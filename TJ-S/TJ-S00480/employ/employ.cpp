#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		s*=i;
	}
	s=s%998;
	s=s%244;
	s=s%353;
	cout<<s;
	return 0;
}
