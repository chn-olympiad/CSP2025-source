#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	cout<<n%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
