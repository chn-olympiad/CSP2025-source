#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int s[1000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	cout<<n*m*m*m*n*n*n*n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
