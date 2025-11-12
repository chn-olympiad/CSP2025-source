#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[505];
long long q[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
 	cout<<m;
	return 0;
}
